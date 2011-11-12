/* 
 * File:   Crypto.h
 * Author: Quentin
 *
 * Created on 12 novembre 2011, 00:20
 */

#ifndef CRYPTO_H
#define	CRYPTO_H
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>

class Crypto {
public:
    static QString toSHA1(QString);
};

#endif	/* CRYPTO_H */

