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
    repository.add(new Temperature("London", "UK"));
    repository.add(new Temperature("Paris", "FR"));
    repository.add(new Humidity("London", "UK"));
    repository.add(new UV("London", "UK"));
    repository.add(new Rainfall("London", "UK"));

    MainWindow window(&repository);
    window.resize(1250, 512);
    window.show();

    return app.exec();
}
