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
    virtual ~Character();
    bool exist();
    QString getId() const;
    QString getLogin() const;
    QString getPassword() const;
    QString getPin() const;
    QString getServer() const;
    QString getChannel() const;
    QString getName() const;
    void setId(QString);
    void setLogin(QString);
    void setPassword(QString);
    void setPin(QString);
    void setServer(QString);
    void setChannel(QString);
    void setName(QString);
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

