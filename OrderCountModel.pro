#-------------------------------------------------
#
# Project created by QtCreator 2018-10-06T19:54:42
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = OrderCountModel
TEMPLATE = lib

DEFINES += ORDERCOUNTMODEL_LIBRARY

SOURCES += \
    basemodel.cpp \
    order.cpp \
    product.cpp \
    supplier.cpp \
    ordersummary.cpp

HEADERS +=\
        OrderCountModel_global.h \
    basemodel.h \
    order.h \
    product.h \
    supplier.h \
    ordersummary.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
