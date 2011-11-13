/* 
 * File:   DatabaseManager.cpp
 * Author: Quentin
 * 
 * Created on 12 novembre 2011, 01:59
 */

#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
    dbname = "characters";
    tblname = "character";
    openDB();
    createCharacterTable();
    model = new QSqlTableModel;
}

DatabaseManager::~DatabaseManager() {
}

bool DatabaseManager::openDB() {
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    return db.open();
}

bool DatabaseManager::hasCharacterTable() {
    bool ret = false;
    if (db.isOpen()) {
        QSqlQuery query("select * from " + tblname);
        ret = query.next();
    }
    return ret;
}

bool DatabaseManager::createCharacterTable() {
    bool ret = hasCharacterTable();
    if (!ret && db.isOpen()) {
        QSqlQuery query;
        ret = query.exec("create table " + tblname + " ("
                "id integer primary key, "
                "login varchar(12), "
                "password varchar(40), "
                "pin varchar(4), "
                "server varchar(16), "
                "channel varchar(2), "
                "name varchar(16));");
    }
    return ret;
}

QSqlTableModel* DatabaseManager::getCharacterModel() {
    model->setTable(tblname);
    model->select();
    return model;
}

int DatabaseManager::createCharacter(Character c) {
    int newId = -1;
    bool ret = false;
    if (db.isOpen()) {
        QSqlQuery query; //http://www.sqlite.org/autoinc.html
        ret = query.exec(QString("insert into " + tblname + " values(%1, "
                "'%2', '%3', '%4', '%5', '%6', '%7');").arg("NULL")
                .arg(c.getLogin()).arg(c.getPassword()).arg(c.getPin())
                .arg(c.getServer()).arg(c.getChannel()).arg(c.getName()));
        if (ret) {
            // http://www.sqlite.org/c3ref/last_insert_rowid.html  
            newId = query.lastInsertId().toInt();
        }
    }
    return newId;
}

Character DatabaseManager::readCharacter(int id) {
    Character character = Character();
    if (db.isOpen()) {
        QSqlQuery query(QString("select * from " + tblname + " where id=%1").arg(id));
        if (query.next()) {
            character.setId(query.value(0).toString());
            character.setLogin(query.value(1).toString());
            character.setPassword(query.value(2).toString());
            character.setPin(query.value(3).toString());
            character.setServer(query.value(4).toString());
            character.setChannel(query.value(5).toString());
            character.setName(query.value(6).toString());
        }
    }
    return character;
}

bool DatabaseManager::updateCharacter(Character c) {
    bool ret = false;
    if (db.isOpen()) {
        QSqlQuery query;
        ret = query.exec("update " + tblname + " set "
                "login = '" + c.getLogin() + "', "
                "password = '" + c.getPassword() + "', "
                "pin = '" + c.getPin() + "', "
                "server = '" + c.getServer() + "', "
                "channel = '" + c.getChannel() + "', "
                "name = '" + c.getName() + "' "
                "where id = " + c.getId());
    }
    return ret;
}

bool DatabaseManager::deleteCharacter(int id) {
    bool ret = false;
    if (db.isOpen()) {
        QSqlQuery query;
        ret = query.exec(QString("delete from " + tblname + " where id=%1").arg(id));
    }
    return ret;
}
