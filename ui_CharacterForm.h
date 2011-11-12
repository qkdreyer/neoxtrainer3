/********************************************************************************
** Form generated from reading UI file 'CharacterForm.ui'
**
** Created: Sat 12. Nov 03:56:52 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERFORM_H
#define UI_CHARACTERFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CharacterForm
{
public:
    QGridLayout *gridLayout;
    QLabel *login;
    QLineEdit *loginField;
    QLabel *password;
    QLineEdit *passwordField;
    QLabel *pin;
    QLineEdit *pinField;
    QLabel *server;
    QComboBox *serverCombo;
    QComboBox *channelCombo;
    QLabel *name;
    QLineEdit *nameField;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CharacterForm)
    {
        if (CharacterForm->objectName().isEmpty())
            CharacterForm->setObjectName(QString::fromUtf8("CharacterForm"));
        CharacterForm->resize(226, 171);
        gridLayout = new QGridLayout(CharacterForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        login = new QLabel(CharacterForm);
        login->setObjectName(QString::fromUtf8("login"));

        gridLayout->addWidget(login, 0, 0, 1, 1);

        loginField = new QLineEdit(CharacterForm);
        loginField->setObjectName(QString::fromUtf8("loginField"));

        gridLayout->addWidget(loginField, 0, 1, 1, 2);

        password = new QLabel(CharacterForm);
        password->setObjectName(QString::fromUtf8("password"));

        gridLayout->addWidget(password, 1, 0, 1, 1);

        passwordField = new QLineEdit(CharacterForm);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        passwordField->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordField, 1, 1, 1, 2);

        pin = new QLabel(CharacterForm);
        pin->setObjectName(QString::fromUtf8("pin"));

        gridLayout->addWidget(pin, 2, 0, 1, 1);

        pinField = new QLineEdit(CharacterForm);
        pinField->setObjectName(QString::fromUtf8("pinField"));

        gridLayout->addWidget(pinField, 2, 1, 1, 2);

        server = new QLabel(CharacterForm);
        server->setObjectName(QString::fromUtf8("server"));

        gridLayout->addWidget(server, 3, 0, 1, 1);

        serverCombo = new QComboBox(CharacterForm);
        serverCombo->setObjectName(QString::fromUtf8("serverCombo"));

        gridLayout->addWidget(serverCombo, 3, 1, 1, 1);

        channelCombo = new QComboBox(CharacterForm);
        channelCombo->setObjectName(QString::fromUtf8("channelCombo"));

        gridLayout->addWidget(channelCombo, 3, 2, 1, 1);

        name = new QLabel(CharacterForm);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 4, 0, 1, 1);

        nameField = new QLineEdit(CharacterForm);
        nameField->setObjectName(QString::fromUtf8("nameField"));

        gridLayout->addWidget(nameField, 4, 1, 1, 2);

        buttonBox = new QDialogButtonBox(CharacterForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 3);


        retranslateUi(CharacterForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), CharacterForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CharacterForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(CharacterForm);
    } // setupUi

    void retranslateUi(QDialog *CharacterForm)
    {
        CharacterForm->setWindowTitle(QApplication::translate("CharacterForm", "Character", 0, QApplication::UnicodeUTF8));
        login->setText(QApplication::translate("CharacterForm", "Login", 0, QApplication::UnicodeUTF8));
        password->setText(QApplication::translate("CharacterForm", "Password", 0, QApplication::UnicodeUTF8));
        pin->setText(QApplication::translate("CharacterForm", "Pin", 0, QApplication::UnicodeUTF8));
        server->setText(QApplication::translate("CharacterForm", "Server", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("CharacterForm", "Character", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CharacterForm: public Ui_CharacterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERFORM_H
