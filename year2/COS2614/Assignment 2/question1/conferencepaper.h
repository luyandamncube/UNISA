#ifndef CONFERENCEPAPER_H
#define CONFERENCEPAPER_H
#include "reference.h"

class ConferencePaper : public Reference {
    private:
        QString title;
        QStringList authors;
        int year;
        QString refID;
        //ConferencePaper uniqe members
        QString confName;
        int month;
    public:
        ConferencePaper(QString ti, QStringList as, int ye, QString id, QString cn, int mo)
        :Reference(ti,as,ye,id)
        {
            refType="Conference";
            confName=cn;
            month=mo;
        }



        QString getConfName();
        int getMonth();

};
#endif // CONFERENCEPAPER_H
