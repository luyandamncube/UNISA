#ifndef REFERENCELIST_H
#define REFERENCELIST_H
#include "reference.h"

class ReferenceList: public QList<Reference*> {
    public:
        ~ReferenceList();
        bool addReference(Reference *r);
        QString generateReferences(QStringList ids, bool full);
        QStringList getIDsByAuthor(QString au);
        QStringList getIDsByConference(QString cn);
        QStringList getIDsByJournal(QString jn);
        Reference *findByID(QString id);
};
#endif // REFERENCELIST_H
