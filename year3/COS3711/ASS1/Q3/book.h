#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>
#include <QDate>
#include <QObject>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(QStringList authors READ getAuthors WRITE setAuthors)
    Q_PROPERTY(QString isbn READ getIsbn WRITE setIsbn)
    Q_PROPERTY(QDate publicationDate READ getPublicationDate WRITE setPublicationDate)
public:
    Book();
    Book(QString t, QStringList a , QString i, QDate p);

    void setTitle(QString t);
    void setAuthors(QStringList a);
    void setIsbn(QString i);
    void setPublicationDate(QDate p);

    QString getTitle();
    QStringList getAuthors();
    QString getIsbn();
    QDate getPublicationDate();
    void obtainBookInfo();

    void saveBook(Book& b);

     QString toString() const;

private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;

};

#endif // BOOK_H
