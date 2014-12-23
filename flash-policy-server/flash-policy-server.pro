include(../flash-policy-server.pri)

TEMPLATE = app

SOURCES += \
    sources/main.cpp \

LIBS += \
    -L../flash-policy-server-core/build/debug \
    -L../flash-policy-server-core/build/release \
    -lflash-policy-server-core \
