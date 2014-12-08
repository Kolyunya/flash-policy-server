include(../FlashPolicyServer.pri)

TEMPLATE = lib

TARGET = FlashPolicyServerCore

CONFIG += \
    staticlib \

HEADERS += \
    sources/PolicyServer/PolicyServer.hpp \
    sources/SocketServer/SocketServer.hpp \
    sources/PolicyFactory/PolicyFactory.hpp \
    sources/ClientRoutine/ClientRoutine.hpp \
    sources/ThreadPool/ThreadPool.hpp \
    sources/Configurable/Configurable.hpp \

SOURCES += \
    sources/PolicyServer/PolicyServer.cpp \
    sources/SocketServer/SocketServer.cpp \
    sources/PolicyFactory/PolicyFactory.cpp \
    sources/ClientRoutine/ClientRoutine.cpp \
    sources/ThreadPool/ThreadPool.cpp \
    sources/Configurable/Configurable.cpp \
