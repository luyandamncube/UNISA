#include <QCoreApplication>
#include <QDebug>
#include "TextAnalyzer.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDir>


void printHelp() {
    qDebug() << "Usage: count [flags] file1.txt [file2.txt...]";
    qDebug() << "Flags:";
    qDebug() << "  -a  Capital-start words >4 chars";
    qDebug() << "  -b  Hyphenated words (not start/end)";
    qDebug() << "  -c  Words that start and end on same char";
    qDebug() << "  -d  Words not starting with vowels";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // qDebug() << "[DEBUG] App started. Raw arguments:";
    // for (int i = 0; i < argc; ++i) {
    //     qDebug() << "  argv[" << i << "] =" << argv[i];
    // }

    QStringList args = app.arguments();
    args.removeFirst(); // remove executable name

    // if (args.isEmpty()) {
    //     qWarning() << "[DEBUG] No arguments provided.";
    //     printHelp();
    //     return 0;
    // }

    bool flagA = false, flagB = false, flagC = false, flagD = false;
    QStringList files;

    for (const QString &arg : args) {
        if (arg.startsWith('-')) {
            for (QChar ch : arg.mid(1)) {
                switch (ch.toLatin1()) {
                case 'a': flagA = true; break;
                case 'b': flagB = true; break;
                case 'c': flagC = true; break;
                case 'd': flagD = true; break;
                default:
                    // qWarning() << "[DEBUG] Unknown flag:" << ch;
                    printHelp();
                    return 1;
                }
            }
        } else {
            files.append(arg);
        }
    }

    if (!flagA && !flagB && !flagC && !flagD) {
        // qDebug() << "[DEBUG] No specific flags provided; enabling all.";
        flagA = flagB = flagC = flagD = true;
    }

    // qDebug() << "[DEBUG] Final flag settings:";
    // qDebug() << "  Flag A:" << flagA;
    // qDebug() << "  Flag B:" << flagB;
    // qDebug() << "  Flag C:" << flagC;
    // qDebug() << "  Flag D:" << flagD;

    // qDebug() << "[DEBUG] Current working directory:" << QDir::currentPath();

    // qDebug() << "[DEBUG] Files to process:" << files;

    if (files.isEmpty()) {
        // qWarning() << "[DEBUG] No input files provided.";
        printHelp();
        return 1;
    }

    TextAnalyzer analyzer(flagA, flagB, flagC, flagD);
    for (const QString &fileName : files) {
        // qDebug() << "[DEBUG] Processing file:" << fileName;
        // qDebug() << "[DEBUG] File exists?" << QFile::exists(fileName);
        // qDebug() << "[DEBUG] Absolute path attempted:" << QFileInfo(fileName).absoluteFilePath();
        analyzer.analyzeFile(fileName);
    }



    // qDebug() << "[DEBUG] App completed successfully.";
    return 0;
}
