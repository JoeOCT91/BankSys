TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        BankSys.cpp

DISTFILES += \
    BankSys.pro.user \
    clients.txt \
    users.txt

HEADERS += \
    Employee.h \
    LoginData.h \
    client.h
