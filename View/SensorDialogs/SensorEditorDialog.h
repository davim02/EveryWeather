#include "../../model/Sensor.h"
#include "../../model/Repository/Repository.h"
#include "../../View/MainWindow.h"
#include "SensorEditor.h"
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QStackedLayout>

class SensorEditorDialog : public QDialog {
    Q_OBJECT

    private:
        MainWindow *mainWindow;
        const Sensor *sensor;
        QSpinBox *id;
        QLineEdit *city;
        QLineEdit *country;
        QComboBox *type;
        QStackedLayout *stackedLayout;
        QVector<SensorEditor*> editors;

    public:
        SensorEditorDialog(MainWindow *mainWindow, Repository *repository, const Sensor *sensor = nullptr);
        
    public slots:
        void showTypeEditor(int index);
        void apply();

   
};
    
