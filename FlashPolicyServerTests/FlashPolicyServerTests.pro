include(../FlashPolicyServer.pri)

TEMPLATE = app

QT += \
    testlib \

CONFIG += \
    testcase \

HEADERS += \

SOURCES += \
    sources/main.cpp

LIBS += \
    -L../FlashPolicyServerCore/build/debug \
    -L../FlashPolicyServerCore/build/release \
    -lFlashPolicyServerCore \
