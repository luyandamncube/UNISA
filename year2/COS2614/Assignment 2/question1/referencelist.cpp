#include "referencelist.h"
#include "conferencepaper.h"
#include "journalarticle.h"

ReferenceList::~ReferenceList(){
//    qDeleteAll(this);
    this->clear();
}

bool ReferenceList::addReference(Reference *r){
//    int count = 0;
    for(Reference *temp : *this)
        if (temp->getRefID() == r->getRefID())
        {
//            count++;
//            qDebug() << "Match found 0" + QString::number(count) + "| " + temp->getRefID() + " | " +r->getRefID();
            return(false);
        }
//        else {
//            count++;
//            qDebug() << "0" + QString::number(count) + "| " + temp->getRefID() + " | " +r->getRefID();
//        }
    if (r->getType() == "Conference"){
        this->append(dynamic_cast<ConferencePaper*>(r));
    }
    return(true);
}

QString ReferenceList::generateReferences(QStringList ids, bool full){
    QString output = "";
    for (int i = 0; i < ids.size();i++){
            if(ids.contains(at(i)->getRefID(),Qt::CaseInsensitive) ){
                if(full){
                    output += at(i)->toString();
                }
                else{
                    output += at(i)->toAPAStyle();
                }
        }
    }
    return (output);
}

QStringList ReferenceList::getIDsByAuthor(QString au){
    QStringList output;
    for(Reference *r: *this)
        if(r->getAuthors().contains(au,Qt::CaseInsensitive)){
            output.append(r->getRefID());
        }
    return (output);
}

QStringList ReferenceList::getIDsByConference(QString cn){
    QStringList output;
    for(Reference *c: *this)
        //Run-time Type Identification (RTTI), cast to a specific type
        if (QString::compare(dynamic_cast<ConferencePaper*>(c)->getConfName(),"Conference",Qt::CaseInsensitive)==0){
            if (QString::compare(dynamic_cast<ConferencePaper*>(c)->getConfName(),cn,Qt::CaseInsensitive)==0){
                output.append(c->getRefID());
            }
        }
    return output;
}

QStringList ReferenceList::getIDsByJournal(QString jn){
    QStringList output;
    for(Reference *c: *this)
        if (c->getType()=="Journal"){
            //Run-time Type Identification (RTTI), cast to a specific type
            if (QString::compare(dynamic_cast<JournalArticle*>(c)->getJournalName(), jn,Qt::CaseInsensitive)==0){
                output.append(c->getRefID());
            }
        }
    return output;

}

Reference * ReferenceList::findByID(QString id){
    for(Reference *r: *this)
        if(r->getRefID() == id){
            return(r);
        }
    return (NULL);
}
