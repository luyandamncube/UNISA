#ifndef JOURNALARTICLE_H
#define JOURNALARTICLE_H
#include "reference.h"

class JournalArticle: public Reference{
    private:
        QString title;
        QStringList authors;
        int year;
        QString refID;
        //JournalArticle uniqe members
        QString journalName;
        int volume;
        int number;
    public:
        JournalArticle(QString ti, QStringList as, int ye, QString jn, QString id, int vo, int no)
        :Reference(ti,as,ye,id)
        {
            refType="Journal";
            journalName=jn;
            volume=vo;
            number=no;
        }
        QString getJournalName();
        int getVolume();
        int getNumber();
};
#endif // JOURNALARTICLE_H
