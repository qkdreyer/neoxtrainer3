/*
 * File:   CharacterForm.cpp
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:32
 */

#include "CharacterForm.h"
#include <iostream>

CharacterForm::CharacterForm() {    
}

CharacterForm::CharacterForm(Character c, QDialog* parent = 0) : QDialog(parent) {
    widget.setupUi(this);
    
    if (!c.isEmpty()) {
        widget.loginField->setText(c.getLogin());
        widget.passwordField->setText(c.getPassword());
        widget.pin->setText(c.getPin());
        widget.name->setText(c.getName());
    }
    
    QStringList channelList;
    channelList << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14";
    widget.channelCombo->addItems(channelList);

    QStringList serverList;
    serverList << "Kradia" << "Demethos";
    widget.serverCombo->addItems(serverList);
}

CharacterForm::~CharacterForm() {
}

void CharacterForm::accept() {
    if (widget.loginField->text().isEmpty()) {
        widget.loginField->setFocus();
    } else if (widget.passwordField->text().isEmpty()) {
        widget.passwordField->setFocus();
    } else if (widget.pinField->text().isEmpty()) {
        widget.pinField->setFocus();
    } else if (widget.nameField->text().isEmpty()) {
        widget.nameField->setFocus();
    } else {
        QHash<QString, QString> c;
        c.insert("login", widget.loginField->text());
        c.insert("password", Crypto::toSHA1(widget.passwordField->text()));
        c.insert("pin", widget.pinField->text());
        c.insert("server", widget.serverCombo->currentText());
        c.insert("channel", widget.channelCombo->currentText());
        c.insert("name", widget.nameField->text());
        emit saveCharacter(Character(c));
        emit done(1);
    }
}
