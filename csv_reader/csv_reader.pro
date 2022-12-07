TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        csvparcer.cpp \
        main.cpp \
        person.cpp \
        personrecord.cpp

HEADERS += \
    csvparcer.h \
    person.h \
    personrecord.h
