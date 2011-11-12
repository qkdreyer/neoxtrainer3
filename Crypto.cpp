/* 
 * File:   Crypto.cpp
 * Author: Quentin
 * 
 * Created on 11 novembre 2011, 00:54
 */

#include "Crypto.h"

QString Crypto::toSHA1(QString hash) {
    QByteArray saltedHash = QString("!" + hash + "?").toUtf8();
    return QString(QCryptographicHash::hash(saltedHash, QCryptographicHash::Sha1).toHex());
}

