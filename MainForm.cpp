/*
 * File:   MainForm.cpp
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:05
 */

#include "MainForm.h"
#include <iostream>

MainForm::MainForm() {
    widget.setupUi(this);
    widget.listView->setItemDelegate(new CharacterDelegate());
    setModel();

    connect(widget.addButton, SIGNAL(clicked()), this, SLOT(execCharacterForm()));
    connect(widget.editButton, SIGNAL(clicked()), this, SLOT(execCharacterForm()));
    connect(widget.deleteButton, SIGNAL(clicked()), this, SLOT(deleteCharacter()));
    connect(widget.loginButton, SIGNAL(clicked()), this, SLOT(loginCharacter()));
    connect(widget.aboutButton, SIGNAL(clicked()), this, SLOT(aboutNeoxTrainer()));
    connect(widget.listView, SIGNAL(clicked(QModelIndex)), this, SLOT(changeCharacter()));
}

MainForm::~MainForm() {
}

void MainForm::execCharacterForm() {
    int selectedCharacterId = widget.listView->currentIndex().row(); // wrong
    CharacterForm form(dbm.readCharacter(selectedCharacterId), this);
    form.setWindowFlags(form.windowFlags() & ~Qt::WindowContextHelpButtonHint);

    if (this->sender() == widget.addButton) {
        form.setWindowTitle("Add " + form.windowTitle());
    } else if (this->sender() == widget.editButton) {
        form.setWindowTitle("Edit " + form.windowTitle());
    }

    connect(&form, SIGNAL(saveCharacter(Character)), this, SLOT(saveCharacter(Character)));
    form.exec();
    disconnect(&form, SIGNAL(saveCharacter(Character)), this, SLOT(saveCharacter(Character)));
}

void MainForm::deleteCharacter() {
    int selectedCharacterId = widget.listView->currentIndex().row(); // wrong
    dbm.deleteCharacter(selectedCharacterId);
    setModel();
}

void MainForm::saveCharacter(Character c) {
    dbm.createCharacter(c);
    widget.listView->update();
    setModel();
}

void MainForm::setModel() {
    QSqlQueryModel* model = dbm.getCharacterModel();
    widget.listView->setModel(model);
    QModelIndex firstIndex = model->index(0, 0);
    bool isRecord = firstIndex.isValid();
    
    if (isRecord) {
        widget.listView->selectionModel()->select(firstIndex, QItemSelectionModel::Select);
    }
    widget.editButton->setEnabled(isRecord);
    widget.deleteButton->setEnabled(isRecord);
    widget.loginButton->setEnabled(isRecord);
}

void MainForm::loginCharacter() {
    QModelIndex currentIndex = widget.listView->currentIndex();
    std::cout << currentIndex.data(0).toString().toStdString() << ":";
    std::cout << currentIndex.data(1).toString().toStdString() << ":";
    std::cout << currentIndex.data(2).toString().toStdString() << ":";
    std::cout << currentIndex.data(3).toString().toStdString() << std::endl;
}

void MainForm::aboutNeoxTrainer() {
    AboutForm form(this);
    form.setWindowFlags(form.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    form.exec();
}
