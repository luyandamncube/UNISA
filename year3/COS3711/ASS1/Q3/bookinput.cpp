#include "bookinput.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QActionGroup>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include <QIcon>
#include <QToolBar>
#include <QTextEdit>
#include <QDateEdit>
#include <QLineEdit>
#include <QMessageBox>
#include "book.h"

BookInput::BookInput() : titleEdit(new QLineEdit), authorEdit(new QLineEdit), isbnEdit(new QLineEdit), dateEdit(new QDateEdit)
{
    setWindowTitle("Book Input");
    QLabel *titleLabel = new QLabel("Title:");
    QLabel *authorLabel = new QLabel("Author:");
    QLabel *isbnLabel = new QLabel("ISBN:");
    QLabel *publicationDateLabel = new QLabel("Publication Date:");

    QPushButton* savebook = new QPushButton("Save book");
    QGridLayout* layout = new QGridLayout();

    layout->addWidget(titleLabel, 0,0);
    layout->addWidget(titleEdit, 0, 1);
    layout->addWidget(authorLabel, 1, 0);
    layout->addWidget(authorEdit, 1, 1);
    layout->addWidget(isbnLabel, 2, 0);
    layout->addWidget(isbnEdit, 2, 1);
    layout->addWidget(publicationDateLabel, 3,0);
    layout->addWidget(dateEdit, 3, 1);
    layout->addWidget(savebook, 4, 0);
    dateEdit->setDate(QDateTime::currentDateTime().date());

    this->setLayout(layout);

    connect(savebook, SIGNAL(clicked()), this, SLOT(getData()));
}
void BookInput::getData(){
   m_book1.setProperty("title", titleEdit->text());
   m_book1.setProperty("authors", authorEdit->text());
   m_book1.setProperty("isbn", isbnEdit->text());
   m_book1.setProperty("publicationDate", dateEdit->date());
   QMessageBox::information(this, "Success!", "Data has been saved to file");
}
