/* 
 * File:   MainForm.h
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:05
 */

#ifndef _MAINFORM_H
#define	_MAINFORM_H

#include "ui_MainForm.h"
#include "CharacterDelegate.h"
#include "CharacterForm.h"
#include "DatabaseManager.h"
#include "AboutForm.h"

class MainForm : public QDialog {
    Q_OBJECT
public:
    MainForm();
    virtual ~MainForm();
    void setModel();
public slots:
    void execCharacterForm(); // add or edit
    void deleteCharacter();
    void loginCharacter();
    void aboutNeoxTrainer();
    void saveCharacter(Character);
private:
    Ui::MainForm widget;
    DatabaseManager dbm;
};

#endif	/* _MAINFORM_H */

