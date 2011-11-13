/*
 * File:   CharacterForm.cpp
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:32
 */

#include "CharacterForm.h"
#include <iostream>
using namespace std;

CharacterForm::CharacterForm() {
}

CharacterForm::CharacterForm(Character c, QDialog* parent = 0) : QDialog(parent) {
    widget.setupUi(this);
    character = c;
    widget.loginField->setValidator(new QRegExpValidator(QRegExp("\\w{4,12}"), this));
    widget.passwordField->setValidator(new QRegExpValidator(QRegExp("\\w{6,12}"), this));
    widget.pinField->setValidator(new QRegExpValidator(QRegExp("\\d{4}"), this));
    widget.nameField->setValidator(new QRegExpValidator(QRegExp("\\w{4,12}"), this));

    QStringList channelList;
    channelList << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14";
    widget.channelCombo->addItems(channelList);

    QStringList serverList;
    serverList << "Kradia" << "Demethos";
    widget.serverCombo->addItems(serverList);

    if (character.exist()) {
        cout << "exist" << character.getId().toStdString() << endl;
        widget.loginField->setText(character.getLogin());
        widget.passwordField->setText(character.getPassword());
        widget.pinField->setText(character.getPin());
        //widget.serverCombo TODO
        widget.serverCombo->setCurrentIndex(0);
        widget.channelCombo->setCurrentIndex(0);
        widget.nameField->setText(character.getName());
        widget.passwordField->installEventFilter(this);
    }
}

CharacterForm::~CharacterForm() {
}

bool CharacterForm::eventFilter(QObject* target, QEvent* event) {
    if (target == widget.passwordField) {
        if (event->type() == QEvent::FocusIn) {
            widget.passwordField->setText("");
        } else if (event->type() == QEvent::FocusOut && widget.passwordField->text().isEmpty()) {
            widget.passwordField->setText(character.getPassword());
            widget.passwordField->removeEventFilter(this);
        }
    }
    return QDialog::eventFilter(target, event);
}

void CharacterForm::accept() {
    bool val = true;
    QString input;
    int pos;
    QList<QLineEdit*> fieldList;
    fieldList << widget.loginField << widget.passwordField << widget.pinField << widget.nameField;

    foreach(QLineEdit* field, fieldList) {
        input = field->text();
        pos = field->text().length();
        if (val && (*field->validator()).validate(input, pos) == QValidator::Intermediate) {
            field->setFocus();
            val = false;
        }
    }

    if (val) {
        character.setLogin(widget.loginField->text());
        QString currentPassword = widget.passwordField->text();
        if (character.getPassword() != currentPassword) {
            character.setPassword(Crypto::toSHA1(currentPassword));
        }
        character.setPin(widget.pinField->text());
        character.setServer(widget.serverCombo->currentText());
        character.setChannel(widget.channelCombo->currentText());
        character.setName(widget.nameField->text());
        emit saveCharacter(character);
        emit done(1);
    }
}
