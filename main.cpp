#include <QApplication>
#include <QFile>
#include <QStyleHints>

#include "View/MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication::setStyle("Material");
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":assets/weather.png"));

    QFile stylesheet;

    /* If you are using Qt 6.5 or later you can access dark mode support by uncommenting the code in this file 
       and in the following files: MainWindow.cpp, TemperatureGraph.cpp, RainfallGraph.cpp, UVGraph.cpp, HumidityGraph.cpp

    if (QApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark) {
        stylesheet.setFileName(":/assets/stylesheet_dark.qss");
    } else {*/
        stylesheet.setFileName(":/assets/stylesheet_light.qss");
    //}
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    MainWindow window;
    window.resize(1250, 512);
    window.show();

    return app.exec();
}
