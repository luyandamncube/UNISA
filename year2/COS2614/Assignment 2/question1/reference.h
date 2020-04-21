#ifndef REFERENCE_H
#define REFERENCE_H
#include <QString>
#include <QStringList>
#include <QDebug>

class Reference {
    private:
        QString title;
        QStringList authors;
        int year;
        QString refID;
    protected:
        QString refType;
    public:
        //Constructor
        Reference(QString ti, QStringList as, int ye, QString id)
        {
            title = ti;
            authors = as;
            year = ye;
            refID = id;
            refType="Generic";
        }
        //Add virtual destructor to make polymorphic
        virtual ~Reference(){}
        QString getTitle();
        QStringList getAuthors();
        int getYear();
        QString getRefID();
        QString toString();
        QString toAPAStyle();
        QString getType();
};
#endif // REFERENCE_H
