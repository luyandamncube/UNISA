#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void handleDeposit();
    void handleWithdrawal();
    void saveToFile();

private:
    QLineEdit *amountInput;
    QDateEdit *dateDisplay;
    QPushButton *depositButton;
    QPushButton *withdrawButton;
    QPushButton *toFileButton;

    void clearInputs();
    double getAmountInput() const;
};

#endif // MAINWINDOW_Hs