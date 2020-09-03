
import json
from urllib import request, parse

def send_message_to_slack(text):
    
    post = {"text": "{0}".format(text)}
 
    try:
        json_data = json.dumps(post)
        req = request.Request("https://hooks.slack.com/services/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",
                              data=json_data.encode('ascii'),
                              headers={'Content-Type': 'application/json'}) 
        resp = request.urlopen(req)
        return (resp.text)
    except Exception as em:
        print("EXCEPTION: " + str(em))



if __name__ == "__main__":
    my_IP = '102.165.246.110'
    resp = send_message_to_slack(f"TESTING: from IP:{my_IP}")
    print(resp)