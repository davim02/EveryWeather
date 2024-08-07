######################################################################
# Automatically generated by qmake (3.1) Sun Feb 11 17:32:09 2024
######################################################################

TEMPLATE = app
TARGET = everyweather
INCLUDEPATH += .
QT += widgets charts

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += model/Humidity.h \
           View/GraphRenderer/SensorGraph.h \
           View/SensorDialogs/EditSensorDialog.h \
           model/Rainfall.h \
           model/Sensor.h \
           model/SensorVisitorConstInterface.h \
           model/SensorVisitorInterface.h \
           model/Temperature.h \
           model/UV.h \
           View/MainWindow.h \
           View/SensorsList.h \
           model/Repository/Repository.h \
           model/Repository/RepositoryInterface.h \
           View/GraphRenderer/SensorGraphVisitor.h \
           View/SensorRenderer/SensorWidget.h \
           View/SensorRenderer/SensorWidgetVisitor.h
SOURCES += main.cpp \
           View/GraphRenderer/SensorGraph.cpp \
           View/SensorDialogs/EditSensorDialog.cpp \
           model/Humidity.cpp \
           model/Rainfall.cpp \
           model/Sensor.cpp \
           model/Temperature.cpp \
           model/UV.cpp \
           View/MainWindow.cpp \
           View/SensorsList.cpp \
           model/Repository/Repository.cpp \
           View/GraphRenderer/SensorGraphVisitor.cpp \
           View/SensorRenderer/SensorWidget.cpp \
           View/SensorRenderer/SensorWidgetVisitor.cpp
RESOURCES = resources.qrc
