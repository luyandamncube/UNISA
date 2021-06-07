#ifndef BOOKINPUT_H
#define BOOKINPUT_H
#include <QMainWindow>
#include <QDialog>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QActionGroup>
#include <QFont>
#include <QIcon>
#include <QToolBar>
#include <QTextEdit>
#include <QLineEdit>
#include <QDateEdit>
#include "book.h"
#include "bookwriter.h"


class BookInput : public QDialog{
    Q_OBJECT
public:
    BookInput();
private slots:
    void getData();
private:
    Book m_book1;
    BookWriter m_wBook;

    QTextEdit * textEdit;
    QLineEdit *titleEdit;
    QLineEdit *authorEdit;
    QLineEdit *isbnEdit;
    QDateEdit *dateEdit;
};

#endif // BOOKINPUT_H
