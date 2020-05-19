#include "referencelist.h"
#include "conferencepaper.h"
#include "journalarticle.h"

ReferenceList::~ReferenceList(){
    this->clear();
}

bool ReferenceList::addReference(Reference *r){
    for(Reference *temp : *this)
        if (temp->getRefID() == r->getRefID())
        {
            return(false);
        }

    this->append(r);
    return(true);
}

QString ReferenceList::generateReferences(QStringList ids, bool full){
    QString output = "";
    //iterate through ReferenceList
    for(Reference *r : *this)
        //iterate through list of ID's in parameter
        for (int i = 0; i < ids.size();i++){
            if(!QString::compare(r->getRefID(), ids.at(i), Qt::CaseInsensitive)){
                if(full){
                    output += r->toString() + "\n";
                 }
                else{
                    output += r->toAPAStyle()+ "\n";
                 }
            }
        }
    return (output);
}

QStringList ReferenceList::getIDsByAuthor(QString au){
    QStringList ids;
    for(int i = 0; i < size(); ++i){
        for(int x = 0; x < at(i)->getAuthors().size(); x++){
            if(QString::compare(at(i)->getAuthors().at(x), au, Qt::CaseInsensitive) == 0){
                ids.append(at(i)->getRefID());
            }
        }
    }
    return ids;
}

QStringList ReferenceList::getIDsByConference(QString cn){
    QStringList ids;
    for(int i = 0; i < size(); ++i){
        if(QString::compare(at(i)->getType(),"Conference",Qt::CaseInsensitive) == 0){
            ConferencePaper *c = (ConferencePaper*)at(i);
            if(QString::compare(c->getConfName(), cn, Qt::CaseInsensitive) == 0){
                ids.append(at(i)->getRefID());
            }
        }
    }
    return ids;
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
