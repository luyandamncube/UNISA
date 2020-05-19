#include <QCoreApplication>
#include <QTextStream>
#include "referencelist.h"
#include "reference.h"
#include "journalarticle.h"
#include "conferencepaper.h"
#include <QDebug>

QTextStream cout(stdout, QIODevice::WriteOnly);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ReferenceList referenceList;

    QStringList authors_1;
    authors_1 << "Pilkington, CL";
    ConferencePaper CP_00("Gamification of a module in advanced programming",authors_1,2016,"Pil16","SABLA",1);
    authors_1 << "Thomas, A";
    ConferencePaper CP_01("Foundational concepts for teaching software design patterns",authors_1,2017,"ThoHal17","SACLA",2);

    QStringList authors_2;
    authors_2 << "Halland, KJ";
    JournalArticle JA_00("Teaching OOP using the Qt framework",authors_2,2016,"JOOP","Hal16",1,3);
    authors_2 << "Ayer, AJ";
    JournalArticle JA_01("Language, Truth, and Logic",authors_2,1936,"JOOP","HalAye36",3,2);
    JournalArticle JA_02("Language, Truth, and Logic",authors_2,1936,"JOOP","HalAye36",3,2);

    referenceList.addReference(&CP_00);
    referenceList.addReference(&CP_01);
    referenceList.addReference(&JA_00);
    referenceList.addReference(&JA_01);
    qDebug() << "TEST 1 - Add two objects of every concrete class to ReferenceList";
    for (int i = 0; i < referenceList.size();i++){
        qDebug() << "\t" << referenceList.at(i)->getRefID();
    }
    qDebug() << "\nTEST 2 - Add an Reference object with an existing ID";
    if (! referenceList.addReference(&JA_02)){
        qDebug() <<"\t" << "Error Adding reference with id" << JA_02.getRefID();
    }

    qDebug() << "\nTEST 3 - test Object public methods with appropriate arguments.";
    qDebug() << "\t" << "getIDsByAuthor: "<<referenceList.getIDsByAuthor("Ayer, AJ");
    qDebug() << "\t" << "getIDsByConference: "<<referenceList.getIDsByConference("SABLA");
    qDebug() << "\t" << "getIDsByJournal: "<<referenceList.getIDsByJournal("JOOP");

    qDebug() << "\nTEST 4 - test generateReferences() using TRUE";
    qDebug().noquote() << referenceList.generateReferences(referenceList.getIDsByJournal("JOOP"),true);

    qDebug() << "\nTEST 5 - test generateReferences() using FALSE";
    qDebug().noquote() << referenceList.generateReferences(referenceList.getIDsByJournal("JOOP"),false);

    return a.exec();
}
