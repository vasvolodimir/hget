TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    network.c \
    main.c \
    io.c

HEADERS += \
    ../include/io.h \
    ../include/shared.h
