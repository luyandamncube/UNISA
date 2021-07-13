#include "bookwriter.h"
#include <QTextStream>
#include <QMessageBox>

BookWriter::BookWriter()
{

}

void BookWriter::writeItem(Book &b)
{
    QFile file("Book_Data.txt");
    file.open(QIODevice::Append);
    QTextStream toFile(&file);

   toFile << "Title:\t" << b.getTitle() << endl;
   toFile << "Authors: " << endl;
   QStringList tempList = b.getAuthors();
   while(!tempList.empty())
   {
       toFile << "\t" << tempList.front() << endl;
       tempList.pop_back();
   }
   toFile << "ISBN:\t" << b.getIsbn() << endl;
   toFile << "Publication Date:\t" << b.getPublicationDate().toString("yyyy.MM.dd") << endl;

   file.close();

}

BookWriter::~BookWriter()
{
}
