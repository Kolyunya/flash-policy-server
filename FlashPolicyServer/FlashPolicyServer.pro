include(../FlashPolicyServer.pri)

TEMPLATE = app

SOURCES += \
    sources/main.cpp \

LIBS += \
    -L../FlashPolicyServerCore/build/debug \
    -L../FlashPolicyServerCore/build/release \
    -lFlashPolicyServerCore \
