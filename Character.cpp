/* 
 * File:   Character.cpp
 * Author: Quentin
 * 
 * Created on 11 novembre 2011, 23:42
 */

#include <basetyps.h>

#include "Character.h"

Character::Character() {
}

Character::~Character() {
}

bool Character::exist() {
    return !login.isEmpty();
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

void Character::setChannel(QString channel) {
    this->channel = channel;
}

void Character::setId(QString id) {
    this->id = id;
}

void Character::setLogin(QString login) {
    this->login = login;
}

void Character::setName(QString name) {
    this->name = name;
}

void Character::setPassword(QString password) {
    this->password = password;
}

void Character::setPin(QString pin) {
    this->pin = pin;
}

void Character::setServer(QString server) {
    this->server = server;
}
