import pandas as pd
import json
import urllib
import warnings
from datetime import datetime
from urllib import request, parse
from sqlalchemy import create_engine, event
warnings.filterwarnings('ignore')
ref_params = urllib.parse.quote_plus(r'DRIVER={SQL Server};SERVER=10.10.0.201, 1633;DATABASE=ReferenceDB;UID=sa;PWD=97nJ_#M&uaH96s2e')
ref_conn_str = 'mssql+pyodbc:///?odbc_connect={}'.format(ref_params)
ref_engine = create_engine(ref_conn_str)
live_params = urllib.parse.quote_plus(r'DRIVER={SQL Server};SERVER=10.10.0.201, 1633;DATABASE=LiveRaceDB;UID=sa;PWD=97nJ_#M&uaH96s2e')
live_conn_str = 'mssql+pyodbc:///?odbc_connect={}'.format(live_params)
live_engine = create_engine(live_conn_str)
athlete_params = urllib.parse.quote_plus(r'DRIVER={SQL Server};SERVER=10.10.0.201, 1633;DATABASE=ReferenceDB;UID=sa;PWD=R97nJ_#M&uaH96s2e')
athlete_conn_str = 'mssql+pyodbc:///?odbc_connect={}'.format(athlete_params)
athlete_engine = create_engine(athlete_conn_str)
hasRunPCS = 0
def send_message_to_slack(text):
    
    tagged = 'TESTING: from 102.165.246.110: ' + text
    post = {"text": "{0}".format(tagged)}
 
    try:
        json_data = json.dumps(post)
        req = request.Request("https://hooks.slack.com/services/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",
                              data=json_data.encode('ascii'),
                              headers={'Content-Type': 'application/json'}) 
        resp = request.urlopen(req)
    except Exception as em:
        print("EXCEPTION: " + str(em))
#def newsflashes():
  #  try:
 #       missing_newsflashes = []
    
 #       df_newsflash = pd.read_sql('SELECT srn.* FROM LandingRef.stg.vw_RaceNews srn LEFT JOIN ReferenceDB.ref.PressRelease pr ON LEFT(CAST(CAST(srn.NewsflashPublishTime AS TIME) AS VARCHAR),8) = pr.Hour WHERE pr.NewsflashId IS NULL ORDER BY Hour DESC;', ref_conn_str)
 #       for index, newsflash in df_newsflash.iterrows():
 #           missing_newsflashes.append(newsflash['NewsflashId'])

  #      if len(missing_newsflashes) > 0:
 #           print('<!channel> Missing newsflashes: {}'.format(','.join(missing_newsflashes)))
        
 #   except:
  #      print('No newsflashes found for this stage')
def team_time_trial():
    try:
        # check when checkpoint passed
        df_chrono = pd.read_sql('SELECT ttpoi.*, poi.PointOfInterest, tt.TeamPK FROM ReferenceDB.ref.TeamTrialPointOfInterest ttpoi JOIN ref.PointOfInterest poi ON poi.PointOfInterestPK = ttpoi.PointOfInterestPK JOIN ReferenceDB.ref.Stage s ON s.StagePK = poi.StagePK JOIN ref.TeamTrial tt ON tt.TeamTrialPK = ttpoi.TeamTrialPK WHERE s.StageDate = CAST(GETDATE() AS DATE) ORDER BY ttpoi.CreatedDate DESC', ref_conn_str)
        for index, last_classification in df_chrono.iterrows():
            last_classification['CreatedDate'] = pd.to_datetime(last_classification['CreatedDate'])
            current_timestamp = datetime.now()
            difference = current_timestamp - last_classification['CreatedDate']
            duration = str(difference).replace(' days ',':').split(':')
            # split duration into different measurements
            days = int(duration[0])
            hours = int(duration[1])
            mins = int(duration[2])
            secs = int(round(float(duration[3]),0))
            if mins < 1:
                send_message_to_slack('Classifications for point {} received {} mins {} seconds ago (Team {})'.format(last_classification['PointOfInterest'],mins,secs,last_classification['TeamPK']))

        # check actual starts and ends
        df_ttt = pd.read_sql('SELECT tt.* FROM ReferenceDB.ref.TeamTrial tt JOIN ReferenceDB.ref.Stage s ON s.StagePK = tt.StagePK WHERE s.StageDate = CAST(GETDATE() AS DATE) ORDER BY s.LastModifiedDate DESC', ref_conn_str)
        for index, last_classification in df_ttt.iterrows():
            last_classification['LastModifiedDate'] = pd.to_datetime(last_classification['LastModifiedDate'])
            current_timestamp = datetime.now()
            difference = current_timestamp - last_classification['LastModifiedDate']
            duration = str(difference).replace(' days ',':').split(':')
            # split duration into different measurements
            days = int(duration[0])
            hours = int(duration[1])
            mins = int(duration[2])
            secs = int(round(float(duration[3]),0))
            if mins < 1:
                # actual start
                if last_classification['ActualStartTime'] != None and last_classification['FinishTimeFromStart'] == None:
                    #print('start')
                    print(last_classification['ActualStartTime'])
                    print(last_classification['FinishTimeFromStart'])
                    send_message_to_slack('Actual Start Recorded for Team {} received {} mins {} seconds ago'.format(last_classification['TeamPK'],mins,secs))
                # end
                elif last_classification['FinishTimeFromStart'] != None:
                    #print('finished')
                    print(last_classification['ActualStartTime'])
                    print(last_classification['FinishTimeFromStart'])
                    send_message_to_slack('Team {} finished {} mins {} seconds ago'.format(last_classification['TeamPK'],mins,secs))

    except Exception as e:
        print(e)
def classifications():
    try:
        df_classification = pd.read_sql('SELECT TOP(1000) rc.* FROM ReferenceDB.ref.RiderClassification rc JOIN ReferenceDB.ref.RiderStage rs ON rs.RiderStagePK = rc.RiderStagePK JOIN ReferenceDB.ref.Stage s ON rs.StagePK = s.StagePK WHERE s.StageDate = CAST(GETDATE() AS DATE) ORDER BY rc.CreatedDate DESC', ref_conn_str)
        last_classification = df_classification.iloc[0]
        last_classification['CreatedDate'] = pd.to_datetime(last_classification['CreatedDate'])
        if last_classification['CompetitionPK'] == 1 and last_classification['ClassificationCategoryPK'] == 1 and last_classification['Quality'] == 0:
            send_message_to_slack('Q0 is in')
        current_timestamp = datetime.now()
        difference = current_timestamp - last_classification['CreatedDate']
        duration = str(difference).replace(' days ',':').split(':')
        # split duration into different measurements
        days = int(duration[0])
        hours = int(duration[1])
        mins = int(duration[2])
        secs = int(round(float(duration[3]),0))
        if mins < 1:
            send_message_to_slack('Classifications received {} mins {} seconds ago'.format(mins,secs))
    except Exception as e:
        print('No available new classifications')

def motorbike_data():
    try:
        df_motor_bike = pd.read_sql('SELECT TOP(100) * FROM LiveRaceDB.dbo.ASOFTPRaceOutput ORDER BY UTCFileTimestampFormatted DESC',live_conn_str)
        last_motor_bike = df_motor_bike.iloc[0]
        last_motor_bike['UTCFileTimestampFormatted'] = pd.to_datetime(last_motor_bike['UTCFileTimestampFormatted'])
        current_timestamp = datetime.now()
        difference = current_timestamp - last_motor_bike['UTCFileTimestampFormatted']
        duration = str(difference).replace(' days ',':').split(':')
        # split duration into different measurements
        days = int(duration[0])
        hours = int(duration[1])
        mins = int(duration[2])
        secs = int(round(float(duration[3]),0))
        if secs >= 10 and last_motor_bike['GroupDistanceToFinish'] > 1 and hours < 23:
            send_message_to_slack('<!channel> No new motorbike data received for {} hours {} mins {} seconds'.format(hours,mins,secs))
        else:
            print(last_motor_bike['GroupDistanceToFinish'])
    except:
        print('No motorbike data found')
        
# for lebuzz webhook https://hooks.slack.com/services/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
def lebuzz_data():
    try:
        df_lebuzz1 = pd.read_sql('SELECT MAX(TimeStampEpochFormatted) FROM LiveRaceDB.[ml].[LeBuzz] WHERE TimeStampEpochFormatted < GETDATE()',live_conn_str)
        
        df_lebuzz2 = pd.read_sql('SELECT MAX(TimeStampEpochFormatted) FROM LiveRaceDB.[ml].[LeBuzz] WHERE TimeStampEpochFormatted >= GETDATE()',live_conn_str)
        
        
        
        if df_lebuzz2 > df_lebuzz1:
            send_message_to_slack('<!channel> Lebuzz received')
            counter = counter + 1
        else:
            print(df_lebuzz1['TimeStampEpochFormatted'])
    except:
        print('No motorbike data found')
#def pcs():
 #   df_athlete_result = pd.read_sql('SELECT TOP(1) * FROM AthleteStatDB.dbo.AthleteResult ORDER BY CreatedDate DESC',athlete_conn_str)
 #   df_athlete_team_history = pd.read_sql('SELECT TOP(1) * FROM AthleteStatDB.dbo.AthleteTeamHistory ORDER BY LoadDate DESC',athlete_conn_str)
 #   df_athlete_team_result = pd.read_sql('SELECT TOP(1) * FROM AthleteStatDB.dbo.AthleteTeamResult ORDER BY CreatedDate DESC',athlete_conn_str)
#    df_athlete = pd.read_sql('SELECT TOP(1) * FROM AthleteStatDB.dbo.Athlete ORDER BY CreatedDate DESC',athlete_conn_str)
#    df_race_event = pd.read_sql('SELECT TOP(1) * FROM AthleteStatDB.dbo.RaceEvent ORDER BY CreatedDate DESC',athlete_conn_str)
#    send_message_to_slack('Last PCS Record Creation Date: \nAthlete: {}\nAthlete Result: {}\nAthlete Team Result: {}\nAthlete Team History: {}\nRace Event: {}'.format(df_athlete['CreatedDate'][0], df_athlete_result['CreatedDate'][0], df_athlete_team_result['CreatedDate'][0], df_athlete_team_history['LoadDate'][0], df_race_event['CreatedDate'][0]))

def streams():
    try:
        
        df_streams = pd.read_sql('SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT TOP (1) ProcessingTime FROM [LiveRaceDB].[dbo].[RiderRaceOutput] WHERE TimeStampEpoch=(SELECT max(Timestampepoch) FROM [LiveRaceDB].[dbo].[RiderRaceOutput]);',live_conn_str)
        last_streams = round(df_streams['ProcessingTime'].iloc[0],2)
        if last_streams >= 5 :
            
            send_message_to_slack('<!channel> Streams Processing time: {}'.format(last_streams))
        else:
            print(last_streams)
            
    except Exception as e: 
        print(e)
def main():
 #   newsflashes()
    motorbike_data()
    #if hasRunPCS == 0:
        #check_pcs()
        #hasRunPCS = 1
    classifications()
    
    lebuzz_data()
    #streams()
 #   team_time_trial()
main()