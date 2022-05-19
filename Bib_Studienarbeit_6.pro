QT       += core serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        crc_com.cpp \
        main.cpp \
        raw_com.cpp \
        read_com.cpp \
        telegram_com.cpp \
        write_com.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    crc_com.h \
    header_com.h \
    raw_com.h \
    read_com.h \
    telegram_com.h \
    write_com.h
