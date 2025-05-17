#include <QApplication>
#include "CalculatorWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CalculatorWindow window;
    window.setWindowTitle("Styled Calculator");
    window.setFixedSize(320, 440);
    window.show();
    return app.exec();
}
