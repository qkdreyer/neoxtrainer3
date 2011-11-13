/*
 * File:   AboutForm.cpp
 * Author: Quentin
 *
 * Created on 12 novembre 2011, 11:16
 */

#include "AboutForm.h"

AboutForm::AboutForm(QString text, QDialog* parent = 0) : QDialog(parent) {
    widget.setupUi(this);
    widget.label->setText(text);
}

AboutForm::~AboutForm() {
}

