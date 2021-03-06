#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T15:13:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GestionDeStock
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
	article.cpp \
	stock.cpp \
	comboboxcolor.cpp \
    comboboxcategory.cpp \
    comboboxtype.cpp \
    comboboxsize.cpp \
    ajoutstock.cpp \
    datasets.cpp \
    modifstock.cpp \
    sells.cpp \
    ajoutvente.cpp \
    vente.cpp \
    recherche.cpp

HEADERS  += mainwindow.h \
	article.h \
	datasets.h \
	stock.h \
	comboboxcolor.h \
    comboboxcategory.h \
    comboboxtype.h \
    comboboxsize.h \
    ajoutstock.h \
	modifstock.h \
    sells.h \
    ajoutvente.h \
    vente.h \
    recherche.h

FORMS    += mainwindow.ui \
    ajoutstock.ui \
    modifstock.ui \
    ajoutvente.ui \
    vente.ui \
    recherche.ui
