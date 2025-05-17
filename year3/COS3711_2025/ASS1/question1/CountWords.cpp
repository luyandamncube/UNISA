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
        if (word.isEmpty())
            continue;

        // --- A: Capital-start, >4 letters
        if (flagA) {
            if (word.length() > 4 && word.at(0).isUpper()) {
                ++countA;
                // qDebug() << "[A] Match:" << word;
            }
        }

        // --- B: Hyphenated word (not starting/ending with hyphen)
        if (flagB) {
            int idx = word.indexOf('-');
            if (idx > 0 && idx < word.length() - 1) {
                ++countB;
                // qDebug() << "[B] Match:" << word;
            }
        }

        // --- C: Same start and end letter (case-insensitive)
        if (flagC) {
            if (word.length() >= 2 && word.front().toLower() == word.back().toLower()) {
                ++countC;
                // qDebug() << "[C] Match:" << word;
            }
        }

        // --- D: Word not starting with a vowel
        if (flagD) {
            QChar first = word.front().toLower();
            if (!QString("aeiou").contains(first)) {
                ++countD;
                // qDebug() << "[D] Match:" << word;
            }
        }
    }

    // --- Summary Output ---
    qDebug() << "\nResults for file:" << fileName;
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
