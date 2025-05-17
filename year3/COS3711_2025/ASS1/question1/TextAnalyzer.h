#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <QString>
#include <QStringList>

class TextAnalyzer {
public:
    TextAnalyzer(bool flagA, bool flagB, bool flagC, bool flagD);

    void analyzeFile(const QString &fileName);

private:
    bool flagA;
    bool flagB;
    bool flagC;
    bool flagD;

    QString cleanText(const QString &text) const;
    QStringList extractWords(const QString &text) const;

    void countPatterns(const QStringList &words, const QString &fileName) const;
};

#endif // TEXTANALYZER_H
