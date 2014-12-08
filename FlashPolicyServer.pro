TEMPLATE = subdirs

CONFIG += \
    ordered \

SUBDIRS = \
    FlashPolicyServerCore \
    FlashPolicyServer \
    FlashPolicyServerTests \

FlashPolicyServer.depends = FlashPolicyServerCore
FlashPolicyServerTests.depends = FlashPolicyServerCore
