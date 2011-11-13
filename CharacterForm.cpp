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
    widget.passwordField->installEventFilter(this);
    widget.pinField->setValidator(new QIntValidator(this));
    character = c;

    if (character.exist()) {
        widget.loginField->setText(character.getLogin());
        widget.passwordField->setText(character.getPassword());
        widget.pinField->setText(character.getPin());
        widget.nameField->setText(character.getName());
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

bool CharacterForm::eventFilter(QObject* target, QEvent* event) {
    if (target == widget.passwordField) {
        if (event->type() == QEvent::FocusIn) {
            widget.passwordField->setText("");
        }
    }
    return QDialog::eventFilter(target, event);
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
