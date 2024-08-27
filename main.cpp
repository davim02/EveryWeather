#include <QApplication>
#include <QFile>

#include "View/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":assets/weather.png"));

    QFile stylesheet(":/assets/stylesheet.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    MainWindow window;
    window.resize(1250, 512);
    window.show();

    return app.exec();
}
