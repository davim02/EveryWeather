#include <QApplication>
#include <QFile>
//#include <QStyleHints>

#include "View/MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication::setStyle("Material");
    QApplication app(argc, argv);
    //qDebug() << QApplication::styleHints()->colorScheme();
    app.setWindowIcon(QIcon(":assets/weather.png"));

    QFile stylesheet(":/assets/stylesheet.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    MainWindow window;
    window.resize(1250, 512);
    window.show();

    return app.exec();
}
