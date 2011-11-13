/* 
 * File:   MainForm.h
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:05
 */

#ifndef _MAINFORM_H
#define	_MAINFORM_H

#include "ui_MainForm.h"
#include <QMessageBox>
#include "CharacterDelegate.h"
#include "CharacterForm.h"
#include "DatabaseManager.h"
#include "AboutForm.h"
#include "MapleStory.h"

class MainForm : public QDialog {
    Q_OBJECT
public:
    MainForm();
    virtual ~MainForm();
public slots:
    void execCharacterForm(); // add or edit
    void deleteCharacter();
    void loginCharacter();
    void aboutNeoxTrainer();
    void saveCharacter(Character); // add and edit
    void setButtonsStates(QModelIndex);
private:
    Ui::MainForm widget;
    DatabaseManager dbm;
};

#endif	/* _MAINFORM_H */

