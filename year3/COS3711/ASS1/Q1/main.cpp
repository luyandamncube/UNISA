#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include <QTextStream>
//#include "dataobject.h"
#include "bookinput.h"
#include "mytablemodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Book Writer");

    BookInput w;
    w.show();
    QTextStream outs (stdout);
    QTextStream in(stdin);
    return a.exec();
}
