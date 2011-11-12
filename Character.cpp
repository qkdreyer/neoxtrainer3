/* 
 * File:   Character.cpp
 * Author: Quentin
 * 
 * Created on 11 novembre 2011, 23:42
 */

#include "Character.h"

Character::Character() {
}

Character::Character(QHash<QString, QString> c) {
    login = c.value("login");
    password = c.value("password");
    pin = c.value("pin");
    server = c.value("server");
    channel = c.value("channel");
    name = c.value("name");
}

Character::~Character() {
}

bool Character::isNull() {
    return id.isEmpty();
}

bool Character::isEmpty() {
    return login.isEmpty();
}

void Character::setId(int i) {
    id = i;
}

QString Character::getId() const {
    return id;
}

QString Character::getChannel() const {
    return channel;
}

QString Character::getLogin() const {
    return login;
}

QString Character::getPassword() const {
    return password;
}

QString Character::getPin() const {
    return pin;
}

QString Character::getServer() const {
    return server;
}

QString Character::getName() const {
    return name;
}
