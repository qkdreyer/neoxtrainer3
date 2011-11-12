/* 
 * File:   DatabaseManager.cpp
 * Author: Quentin
 * 
 * Created on 12 novembre 2011, 01:59
 */

#include "DatabaseManager.h"
#include <iostream>

DatabaseManager::DatabaseManager() {
    dbname = "characters";
    tblname = "character";
    model = new QSqlQueryModel;
    openDB();
    createCharacterTable();
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

QSqlQueryModel* DatabaseManager::getCharacterModel() {
    model->setQuery("select name || ' (' || server || ' ' || channel || ')' as display, "
        "id, login, password, server, channel, name from " + tblname);
    model->setHeaderData(1, Qt::Horizontal, "id", 1);
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
    return Character();
}

bool DatabaseManager::deleteCharacter(int id) {
    bool ret = false;
    if (db.isOpen()) {
        QSqlQuery query;
        ret = query.exec(QString("delete from " + tblname + " where id=:id").arg(id));
    }
    return ret;
}
