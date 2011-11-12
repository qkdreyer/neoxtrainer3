/* 
 * File:   DatabaseManager.h
 * Author: Quentin
 *
 * Created on 12 novembre 2011, 01:59
 */

#ifndef DATABASEMANAGER_H
#define	DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlTableModel>
#include "Character.h"

class DatabaseManager {
public:
    DatabaseManager();
    DatabaseManager(const DatabaseManager& orig);
    virtual ~DatabaseManager();
    bool openDB();
    bool hasCharacterTable();
    bool createCharacterTable();
    QSqlTableModel* getCharacterModel();
    int createCharacter(Character);
    Character readCharacter(int);
    bool deleteCharacter(int);
private:
    QSqlDatabase db;
    QString dbname;
    QString tblname;
    QSqlTableModel* model;
};

#endif	/* DATABASEMANAGER_H */

