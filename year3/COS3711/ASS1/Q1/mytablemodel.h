#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include "book.h"

class MyTableModel : public QAbstractTableModel
{
public:
    MyTableModel();
    ~MyTableModel();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void addBook(Book *e);

private:
    QList<Book *> BookList;

};

#endif // MYTABLEMODEL_H
