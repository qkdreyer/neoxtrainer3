/* 
 * File:   Character.h
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:42
 */

#ifndef CHARACTER_H
#define	CHARACTER_H
#include <QString>
#include <QHash>

class Character {
public:
    Character();
    Character(QHash<QString, QString>);
    //Character(const Character& orig); //is called faster any constructor
    virtual ~Character();
    bool isNull();
    bool isEmpty();
    void setId(int);
    QString getId() const;
    QString getLogin() const;
    QString getPassword() const;
    QString getPin() const;
    QString getServer() const;
    QString getChannel() const;
    QString getName() const;
private:
    QString id;
    QString login;
    QString password;
    QString pin;
    QString server;
    QString channel;
    QString name;
};

#endif	/* CHARACTER_H */

