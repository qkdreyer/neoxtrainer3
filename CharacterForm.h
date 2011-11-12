/* 
 * File:   CharacterForm.h
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:32
 */

#ifndef _CHARACTERFORM_H
#define	_CHARACTERFORM_H

#include "ui_CharacterForm.h"
#include "Character.h"
#include "Crypto.h"

class CharacterForm : public QDialog {
    Q_OBJECT
public:
    CharacterForm();
    CharacterForm(Character, QDialog*);
    virtual ~CharacterForm();
private slots:
    void accept();
signals:
    void saveCharacter(Character);
private:
    Ui::CharacterForm widget;
};

#endif	/* _CHARACTERFORM_H */

