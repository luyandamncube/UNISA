#include <QCoreApplication>
#include <QDebug>
#include "CountWords.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDir>


void printHelp() {
    qDebug() << "Usage: count [flags] file1.txt [file2.txt...]";
    qDebug() << "EXAMPLE: count -abc test1.txt test2.txt";
    qDebug() << "Flags:";
    qDebug() << "  -a  Capital-start words >4 chars";
    qDebug() << "  -b  Hyphenated words (not start/end)";
    qDebug() << "  -c  Words that start and end on same char";
    qDebug() << "  -d  Words not starting with vowels";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList args = app.arguments();
    args.removeFirst();

    if (args.isEmpty()) {
        qWarning() << "[DEBUG] No arguments provided.";
        printHelp();
        return 0;
    }

    bool flagA = false;
    bool flagB = false;
    bool flagC = false;
    bool flagD = false;

    QStringList files;

    QSet<QChar> validFlags = {'a', 'b', 'c', 'd'};

    for (const QString &arg : args) {
        if (arg.startsWith('-')) {
            QString flags = arg.mid(1);

            for (QChar ch : flags) {
                if (!validFlags.contains(ch)) {
                    printHelp();
                    return 1;
                }

                // Set corresponding flags
                if (ch == 'a') flagA = true;
                else if (ch == 'b') flagB = true;
                else if (ch == 'c') flagC = true;
                else if (ch == 'd') flagD = true;
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

    CountWords parse(flagA, flagB, flagC, flagD);
    for (const QString &fileName : files) {
        // qDebug() << "[DEBUG] Processing file:" << fileName;
        // qDebug() << "[DEBUG] File exists?" << QFile::exists(fileName);
        // qDebug() << "[DEBUG] Absolute path attempted:" << QFileInfo(fileName).absoluteFilePath();
        parse.parseFile(fileName);
    }



    // qDebug() << "[DEBUG] App completed successfully.";
    return 0;
}
