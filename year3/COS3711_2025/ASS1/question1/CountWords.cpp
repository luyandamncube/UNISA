#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>
#include "CountWords.h"

CountWords::CountWords(bool flagA, bool flagB, bool flagC, bool flagD)
    : flagA(flagA), flagB(flagB), flagC(flagC), flagD(flagD) {}

QStringList CountWords::extractWords(const QString &text) const {
    return text.split(' ', Qt::SkipEmptyParts);
}

void CountWords::countPatterns(const QStringList &words, const QString &fileName) const {
    int countA = 0, countB = 0, countC = 0, countD = 0;

    for (const QString &word : words) {
        if (flagA && word.length() > 4 && word.at(0).isUpper())
            ++countA;

        if (flagB && word.contains('-')) {
            int idx = word.indexOf('-');
            if (idx > 0 && idx < word.length() - 1)
                ++countB;
        }

        if (flagC && word.length() >= 2 &&
            word.front().toLower() == word.back().toLower())
            ++countC;

        if (flagD && !word.isEmpty()) {
            QChar first = word.front().toLower();
            if (!QString("aeiou").contains(first))
                ++countD;
        }
    }

    if (flagA) qDebug() << "  [A] No of capital-start words longer than 4 letters:" << countA;
    if (flagB) qDebug() << "  [B] No of hyphenated words:" << countB;
    if (flagC) qDebug() << "  [C] No of same start/end char words:" << countC;
    if (flagD) qDebug() << "  [D] No of words not starting with vowel:" << countD;
}

void CountWords::parseFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file:" << fileName;
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    QStringList words = extractWords(text);

    qDebug() << "\n";
    qDebug() << "***" << fileName << "***";

    countPatterns(words, fileName);
}
