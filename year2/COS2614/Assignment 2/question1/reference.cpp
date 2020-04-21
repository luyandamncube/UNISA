#include "reference.h"
#include <QDebug>

QString Reference::getTitle(){
    return(title);
}

QStringList Reference::getAuthors(){
    return(authors);
}

int Reference::getYear(){
    return(year);
}

QString Reference::getRefID(){
    return(refID);
}

QString Reference::toString(){
    return("Authors: " + getAuthors().join(", ") +
           "\nYear: " + QString::number(year) +
           "\nTitle: " + getTitle() +
           "\nType: " + getType()+
           "\nRef ID: " + getRefID());
}

QString Reference::toAPAStyle(){
    return(getAuthors().join(", ") +" ("+
           QString::number(year) + "), " +
           getTitle());
}

QString Reference::getType(){
    return (refType);
}
