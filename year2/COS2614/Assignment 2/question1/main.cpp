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
    QStringList confPaperAuthors;
    confPaperAuthors.append("J Mbambo");
    confPaperAuthors.append("V Dube");
    ConferencePaper confPaper1("Boring conf QT1",confPaperAuthors,2017,"12x","Super QT conference yes",1);
    ConferencePaper confPaper2("Boring conf QT2",confPaperAuthors,2018,"13x","Super QT conf",2);
    QStringList journalAuthors;
    //journalAuthors.append("J Mbambo");
    journalAuthors.append("V Dube");
    JournalArticle JournalArticle1("Boring Journal QT1",journalAuthors,2017,"19x","Super QT",1,3);
    JournalArticle JournalArticle2("Boring Journal QT2",journalAuthors,2018,"20x","Super boring QT journal",3,2);
    ReferenceList referenceList;
    referenceList.addReference(&confPaper1);
    referenceList.addReference(&confPaper2);
    referenceList.addReference(&JournalArticle1);
    referenceList.addReference(&JournalArticle2);
    qDebug() << ""<<referenceList.getIDsByAuthor("J Mbambo");
    qDebug() << ""<<referenceList.getIDsByConference("Super QT conference yes");
    qDebug() << ""<<referenceList.getIDsByJournal("Super boring QT journal");
    return a.exec();
}
