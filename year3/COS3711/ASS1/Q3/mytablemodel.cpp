#include "mytablemodel.h"

MyTableModel::MyTableModel()
{
}

MyTableModel::~MyTableModel()
{
    qDeleteAll(BookList);
    BookList.clear();
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return BookList.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 4;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        if (index.column() == 0)
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return int(Qt::AlignRight | Qt::AlignVCenter);
    }

    if (role == Qt::DisplayRole)
    {
        int col = index.column();
        int row = index.row();
        if (col==0) return BookList.at(row)->getTitle();
        else if (col==1) return BookList.at(row)->getAuthors();
        else if (col==2) return BookList.at(row)->getIsbn();
        else if (col==3) return BookList.at(row)->getPublicationDate();
    }
    return QVariant();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
      case 0: return QString("Title");   break;
      case 1: return QString("Authors"); break;
      case 2: return QString("Isbn"); break;
      case 3: return QString("Publication Date"); break;
      default: return QVariant();
    }

    return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role==Qt::EditRole)
    {
        int col = index.column();
        int row = index.row();
        switch (col)
        {
          case 0: BookList.at(row)->setProperty("title", value.toString());   break;
          case 1: BookList.at(row)->setProperty("authors", value.toStringList());     break;
          case 2: BookList.at(row)->setProperty("isbn", value.toInt()); break;
          case 3: BookList.at(row)->setProperty("publicationDate", value.toString()); break;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    else
        return 0;
}

void MyTableModel::addBook(Book *e)
{
    int row = BookList.size();
    beginInsertRows(QModelIndex(), row+1, row+1);
    BookList.append(e);
    endInsertRows();
}
