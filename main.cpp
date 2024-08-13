#include <QApplication>

#include "model/Repository/Repository.h"
#include "model/Temperature.h"
#include "model/Humidity.h"
#include "model/UV.h"
#include "model/Rainfall.h"
#include "View/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Repository repository;
    repository.add(new Temperature(1, "London", "UK", false));
    repository.add(new Humidity(2, "London", "UK"));
    repository.add(new UV(3, "London", "UK"));
    repository.add(new Rainfall(4, "London", "UK", false));
    repository.add(new Temperature(5, "Paris", "FR", false));
    repository.add(new Humidity(6, "Paris", "FR"));
    repository.add(new UV(7, "Paris", "FR"));
    repository.add(new Rainfall(8, "Paris", "FR", false));

    MainWindow window(&repository);
    window.resize(1250, 512);
    window.show();

    return app.exec();
}
