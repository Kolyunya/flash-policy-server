TEMPLATE = subdirs

CONFIG += \
    ordered \

SUBDIRS = \
    flash-policy-server-core \
    flash-policy-server \
    flash-policy-server-tests \

flash-policy-server.depends = flash-policy-server-core
flash-policy-server-tests.depends = flash-policy-server-core
