#include <QApplication>
#include "MainWindow.h"
#include <QDir>

int main(int argc, char *argv[]) {
    // --- Initialize Qt application ---
    QApplication app(argc, argv);
    qDebug() << "[DEBUG] Banking Transactions app started.";

    // ---Show project working directory ---
    qDebug() << "[DEBUG] Working directory:" << QDir::currentPath();

    // --- Create and show the main window ---
    MainWindow window;
    window.setWindowTitle("Banking Transactions");
    window.show();

    // --- Start the event loop ---
    return app.exec();
}
