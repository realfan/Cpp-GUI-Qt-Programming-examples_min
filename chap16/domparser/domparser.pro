greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE      = app
QT           += xml
CONFIG       += console
HEADERS       = domparser.h
SOURCES       = domparser.cpp \
                main.cpp
