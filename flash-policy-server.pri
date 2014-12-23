INCLUDEPATH += \
    ../flash-policy-server-core/include \

QT += \
    core \
    network \

QT -= \
    gui

CONFIG += \
    c++11 \
    console \

CONFIG -= \
    app_bundle \

QMAKE_CXXFLAGS += \
    -Wall \
    -Wextra \
    -Werror \
    -pedantic \
    -pedantic-errors \

debug:DESTDIR = build/debug
release:DESTDIR = build/release
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui
