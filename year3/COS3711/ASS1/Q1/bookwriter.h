#ifndef BOOKWRITER_H
#define BOOKWRITER_H
#include <QFile>
#include <QString>
#include "book.h"

class BookWriter
{
public:
    BookWriter();
    void writeItem(Book &b);
    ~BookWriter();
};

#endif // BOOKWRITER_H
