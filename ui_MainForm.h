/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created: Sat 12. Nov 12:10:37 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QGridLayout *gridLayout;
    QListView *listView;
    QPushButton *aboutButton;
    QPushButton *loginButton;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(355, 210);
        QIcon icon;
        icon.addFile(QString::fromUtf8("briefcase.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listView = new QListView(MainForm);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout->addWidget(listView, 0, 0, 7, 1);

        aboutButton = new QPushButton(MainForm);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));

        gridLayout->addWidget(aboutButton, 4, 1, 1, 1);

        loginButton = new QPushButton(MainForm);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setEnabled(false);

        gridLayout->addWidget(loginButton, 0, 1, 1, 1);

        addButton = new QPushButton(MainForm);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 1, 1, 1, 1);

        editButton = new QPushButton(MainForm);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setEnabled(false);

        gridLayout->addWidget(editButton, 2, 1, 1, 1);

        deleteButton = new QPushButton(MainForm);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);

        gridLayout->addWidget(deleteButton, 3, 1, 1, 1);

        QWidget::setTabOrder(listView, loginButton);
        QWidget::setTabOrder(loginButton, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, aboutButton);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QDialog *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Neox Trainer", 0, QApplication::UnicodeUTF8));
        aboutButton->setText(QApplication::translate("MainForm", "About", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("MainForm", "Login", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("MainForm", "Add", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("MainForm", "Edit", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("MainForm", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
