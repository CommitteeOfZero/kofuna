CONFIG += kofuna

kofuna {
OBJECTS_DIR = kofuna/.obj
MOC_DIR = kofuna/.moc
RCC_DIR = kofuna/.rcc
UI_DIR = kofuna/.ui

RESOURCES += $$PWD/kofuna.qrc

SOURCES += \
    $$PWD/invertprogressbar.cpp


HEADERS += \
    $$PWD/invertprogressbar.h
}
