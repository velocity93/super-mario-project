/********************************************************************************
** Form generated from reading UI file 'Editor.ui'
**
** Created: Thu 29. Mar 23:56:02 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EditorClass)
    {
        if (EditorClass->objectName().isEmpty())
            EditorClass->setObjectName(QString::fromUtf8("EditorClass"));
        EditorClass->resize(600, 400);
        menuBar = new QMenuBar(EditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        EditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EditorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EditorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(EditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(EditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EditorClass->setStatusBar(statusBar);

        retranslateUi(EditorClass);

        QMetaObject::connectSlotsByName(EditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *EditorClass)
    {
        EditorClass->setWindowTitle(QApplication::translate("EditorClass", "Editor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditorClass: public Ui_EditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
