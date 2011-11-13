/*
 * File:   MainForm.cpp
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:05
 */

#include "MainForm.h"
#include <iostream>
using namespace std;

MainForm::MainForm() {
    widget.setupUi(this);
    widget.listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    widget.listView->setItemDelegate(new CharacterDelegate(this));
    
    QSqlTableModel* model = dbm.getCharacterModel();
    widget.listView->setModel(model);
    widget.listView->setCurrentIndex(model->index(0, 0));
    this->setButtonsStates(widget.listView->currentIndex());

    connect(widget.addButton, SIGNAL(clicked()), this, SLOT(execCharacterForm()));
    connect(widget.editButton, SIGNAL(clicked()), this, SLOT(execCharacterForm()));
    connect(widget.deleteButton, SIGNAL(clicked()), this, SLOT(deleteCharacter()));
    connect(widget.loginButton, SIGNAL(clicked()), this, SLOT(loginCharacter()));
    connect(widget.aboutButton, SIGNAL(clicked()), this, SLOT(aboutNeoxTrainer()));
    connect(widget.listView, SIGNAL(clicked(QModelIndex)), this, SLOT(setButtonsStates(QModelIndex)));
}

MainForm::~MainForm() {
}

void MainForm::execCharacterForm() {
    CharacterForm* form;
    if (this->sender() == widget.addButton) { // add
        form = new CharacterForm(Character(), this);
        (*form).setWindowTitle("Add " + (*form).windowTitle());
    } else { // edit
        int selectedCharacterId = widget.listView->currentIndex().data(0).toInt();
        form = new CharacterForm(dbm.readCharacter(selectedCharacterId), this);
        (*form).setWindowTitle("Edit " + (*form).windowTitle());
    }
    (*form).setWindowFlags((*form).windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect(form, SIGNAL(saveCharacter(Character)), this, SLOT(saveCharacter(Character)));
    (*form).exec();
    disconnect(form, SIGNAL(saveCharacter(Character)), this, SLOT(saveCharacter(Character)));
}

void MainForm::deleteCharacter() {
    int selectedCharacterId = widget.listView->currentIndex().data(0).toInt();
    dbm.deleteCharacter(selectedCharacterId);
    widget.listView->setModel(dbm.getCharacterModel());
    setButtonsStates(QModelIndex());
}

void MainForm::saveCharacter(Character c) {
    if (c.getId().isEmpty()) {
        dbm.createCharacter(c);
    } else {
        dbm.updateCharacter(c);
    }
    widget.listView->setModel(dbm.getCharacterModel());
    setButtonsStates(QModelIndex());
}

void MainForm::setButtonsStates(QModelIndex i) {
    bool val = i.isValid();
    widget.editButton->setEnabled(val);
    widget.deleteButton->setEnabled(val);
    widget.loginButton->setEnabled(val);
    widget.listView->setFocus();
}

void MainForm::loginCharacter() {
    QString title = "WIP " + widget.listView->currentIndex().data(0).toString();
    QMessageBox wip(QMessageBox::Information, title, "Work in Progress !");
    wip.exec();
}

void MainForm::aboutNeoxTrainer() {
    AboutForm form("Neox Trainer made by Neoxyde", this);
    form.setWindowFlags(form.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    form.exec();
}
