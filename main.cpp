#include <QApplication>

#include "View/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":assets/weather.png"));

    MainWindow window;
    window.resize(1250, 512);
    window.show();

    return app.exec();
}
