#-------------------------------------------------
#
# Project created by QtCreator 2018-05-02T09:53:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pipeline
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    city/city.cpp \
    common/storage.cpp \
    city/citystorage.cpp \
    city/cityservice.cpp \
    map/pipelinemap.cpp \
    map/pipelinecity.cpp \
    map/pipelinemapstorage.cpp \
    map/pipelinemapservice.cpp \
    map/pipelinemapresponse.cpp \
    map/pipelinecityresponse.cpp \
    common/configloader.cpp \
    common/jsonloader.cpp \
    exceptions/filenotfoundexception.cpp \
    city/cityparser.cpp \
    user/userstorage.cpp \
    map/mapparser.cpp \
    map/pipelinecityparser.cpp \
    user/user.cpp \
    user/userparser.cpp \
    user/userservice.cpp \
    alternatives/alternativesservice.cpp \
    alternatives/alternativesmatrix.cpp \
    criterion/criterion.cpp \
    criterion/criterionstorage.cpp \
    criterion/criterionmatrix.cpp \
    criterion/criterionservice.cpp \
    tree/treeexception.cpp \
    tree/treeservice.cpp

HEADERS += \
        mainwindow.h \
    city/city.h \
    common/storage.h \
    city/citystorage.h \
    city/cityservice.h \
    map/pipelinemap.h \
    map/pipelinecity.h \
    map/pipelinemapstorage.h \
    map/pipelinemapservice.h \
    map/pipelinemapresponse.h \
    map/pipelinecityresponse.h \
    common/configloader.h \
    common/jsonloader.h \
    exceptions/filenotfoundexception.h \
    city/cityparser.h \
    user/userstorage.h \
    map/mapparser.h \
    map/pipelinecityparser.h \
    user/user.h \
    user/userparser.h \
    user/userservice.h \
    alternatives/alternativesservice.h \
    alternatives/alternativesmatrix.h \
    criterion/criterion.h \
    criterion/criterionstorage.h \
    criterion/criterionmatrix.h \
    criterion/criterionservice.h \
    tree/edge.h \
    tree/vertex.h \
    tree/tree.h \
    tree/treeiterator.h \
    tree/treeallocator.h\
    tree/treeexception.h \
    tree/treeservice.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    maps.json \
    cities.json \
    users.json
