/* 
 * File:   AboutForm.h
 * Author: Quentin
 *
 * Created on 12 novembre 2011, 11:16
 */

#ifndef _ABOUTFORM_H
#define	_ABOUTFORM_H

#include "ui_AboutForm.h"

class AboutForm : public QDialog {
    Q_OBJECT
public:
    AboutForm(QDialog*);
    virtual ~AboutForm();
private:
    Ui::AboutForm widget;
};

#endif	/* _ABOUTFORM_H */

