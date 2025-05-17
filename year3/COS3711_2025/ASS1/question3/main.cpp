#include <QApplication>
#include "CalculatorWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CalculatorWindow window;
    window.setWindowTitle("Simple Calculator");
    window.show();
    return app.exec();
}