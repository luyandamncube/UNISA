#include "conferencepaper.h"

//QString Reference::refType = "Conference";

//ConferencePaper::ConferencePaper(
//        QString _title, QStringList _authors, int _year, QString _refID, QString _confName, int _month):
//    Reference(_title, _authors, _year, _refID),
//    confName(_confName),
//    month(_month)
//{
//}

QString ConferencePaper::getConfName(){
    return(confName);
}

int ConferencePaper::getMonth(){
    return(month);
}
