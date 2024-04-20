#include <QApplication>

#include "model/Repository/Repository.h"
#include "model/Temperature.h"
#include "model/Humidity.h"
#include "model/UV.h"
#include "View/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Repository repository;
    repository.add(new Temperature("London", "UK"));
    repository.add(new Humidity("London", "UK"));
    repository.add(new UV("London", "UK"));

    MainWindow window(&repository);
    window.show();

    return app.exec();
}