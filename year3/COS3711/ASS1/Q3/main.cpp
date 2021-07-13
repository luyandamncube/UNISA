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
    a.setApplicationName("Book Viewer");
    MyTableModel model;
    QTableView view;
    //view.
    view.setModel(&model);
    view.show();

    return a.exec();
}
