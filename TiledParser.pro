TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    tinyxml2.cpp \
    tiledmap.cpp \
    tiledmaptileset.cpp \
    tiledmaplayer.cpp \
    tiledmapobject.cpp \
    tiledmapobjectproperty.cpp \
    tiledmapobjectgroup.cpp

HEADERS += \
    tinyxml2.h \
    tiledmap.h \
    tiledmaptileset.h \
    tiledmaplayer.h \
    tiledmapobject.h \
    tiledmapobjectproperty.h \
    tiledmapobjectgroup.h

