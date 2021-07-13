#include "book.h"

Book::Book()
{

}

Book::Book(QString t, QStringList a , QString i, QDate p) : title(t), authors(a), isbn(i), publicationDate(p)
{
    //
}
void Book::setTitle(QString t)
{
    title = t;
}

void Book::setAuthors(QStringList a)
{
    authors = a;
}

void Book::setIsbn(QString i)
{
    isbn = i;
}

void Book::setPublicationDate(QDate p)
{
    publicationDate = p;
}

QString Book::getTitle()
{
    return(title);
}

QStringList Book::getAuthors()
{
    return(authors);
}

QString Book::getIsbn()
{
    return(isbn);
}

QDate Book::getPublicationDate()
{
    return(publicationDate);
}

QString Book::toString() const
{
    return QString("%1\t%2\t%3\t%4").arg(title, 15).arg(QString(authors.join(""))).arg(isbn, 13).arg(publicationDate.toString("dd-MM-yyyy"));
}
