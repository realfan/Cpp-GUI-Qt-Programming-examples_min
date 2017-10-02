greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE      = app
QT           += xml
CONFIG       += console
HEADERS       = saxhandler.h
SOURCES       = main.cpp \
                saxhandler.cpp
