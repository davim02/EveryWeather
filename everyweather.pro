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
HEADERS += model/Sensor.h \
           model/Humidity.h \
           model/Rainfall.h \
           model/Temperature.h \
           model/UV.h \
           model/SensorVisitorConstInterface.h \
           model/SensorVisitorInterface.h \
           model/Simulation/HumiditySim.h \
           model/Simulation/RainfallSim.h \
           model/Simulation/UVSim.h \
           model/Simulation/TemperatureSim.h \
           model/Repository/JsonRepository.h \
           model/Repository/RepositoryInterface.h \
           model/JsonFileIO/JsonFile.h \
           model/JsonConverter/Json.h \
           model/JsonConverter/JsonVisitor.h \
           model/JsonConverter/Reader.h \
           model/JsonConverter/ReaderInterface.h \
           View/GraphRenderer/HumidityGraph.h \
           View/GraphRenderer/RainfallGraph.h \
           View/GraphRenderer/SensorGraphWidget.h \
           View/GraphRenderer/SensorGraphWidgetVisitor.h \
           View/GraphRenderer/TemperatureGraph.h \
           View/GraphRenderer/UVGraph.h \
           View/SearchWidget.h \
           View/SensorDialogs/HumidityEditor.h \
           View/SensorDialogs/RainfallEditor.h \
           View/SensorDialogs/SensorEditor.h \
           View/SensorDialogs/SensorEditorDialog.h \
           View/SensorDialogs/SensorEditorDialogInjector.h \
           View/SensorDialogs/TemperatureEditor.h \
           View/SensorDialogs/TypeSelector.h \
           View/SensorDialogs/UVEditor.h \
           View/SensorRenderer/SensorInfoWidget.h \
           View/SensorRenderer/SensorInfoWidgetVisitor.h \
           View/MainWindow.h \
           View/SensorsList.h \
           View/SensorRenderer/SensorWidget.h \
           View/SensorRenderer/SensorWidgetVisitor.h
SOURCES += model/Sensor.cpp \
           model/Humidity.cpp \
           model/Rainfall.cpp \
           model/Temperature.cpp \
           model/UV.cpp \
           model/Simulation/HumiditySim.cpp \
           model/Simulation/RainfallSim.cpp \
           model/Simulation/UVSim.cpp \
           model/Simulation/TemperatureSim.cpp \
           main.cpp \
           model/Repository/JsonRepository.cpp \
           model/JsonFileIO/JsonFile.cpp \
           model/JsonConverter/Json.cpp \
           model/JsonConverter/JsonVisitor.cpp \
           model/JsonConverter/Reader.cpp \
           View/GraphRenderer/HumidityGraph.cpp \
           View/GraphRenderer/RainfallGraph.cpp \
           View/GraphRenderer/SensorGraphWidget.cpp \
           View/GraphRenderer/SensorGraphWidgetVisitor.cpp \
           View/GraphRenderer/TemperatureGraph.cpp \
           View/GraphRenderer/UVGraph.cpp \
           View/SearchWidget.cpp \
           View/SensorDialogs/HumidityEditor.cpp \
           View/SensorDialogs/RainfallEditor.cpp \
           View/SensorDialogs/SensorEditor.cpp \
           View/SensorDialogs/SensorEditorDialog.cpp \
           View/SensorDialogs/SensorEditorDialogInjector.cpp \
           View/SensorDialogs/TemperatureEditor.cpp \
           View/SensorDialogs/TypeSelector.cpp \
           View/SensorDialogs/UVEditor.cpp \
           View/SensorRenderer/SensorInfoWidget.cpp \
           View/SensorRenderer/SensorInfoWidgetVisitor.cpp \
           View/MainWindow.cpp \
           View/SensorsList.cpp \
           View/SensorRenderer/SensorWidget.cpp \
           View/SensorRenderer/SensorWidgetVisitor.cpp
RESOURCES = resources.qrc
