#ifndef COUNTWORDS_H
#define COUNTWORDS_H

#include <QString>
#include <QStringList>

class CountWords {
public:
    CountWords(bool flagA, bool flagB, bool flagC, bool flagD);

    void parseFile(const QString &fileName);

private:
    bool flagA;
    bool flagB;
    bool flagC;
    bool flagD;

    QStringList extractWords(const QString &text) const;

    void countPatterns(const QStringList &words, const QString &fileName) const;
};

#endif // COUNTWORDS_H
