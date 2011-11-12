/*
 * File:   main.cpp
 * Author: Quentin
 *
 * Created on 11 novembre 2011, 23:04
 */

#include <QtGui/QApplication>
#include "MainForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    QString version = "3.0";
    
    // create and show your widgets here
    MainForm form;
    form.setWindowFlags(form.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    form.setWindowTitle(form.windowTitle() + " " + version);
    form.show();
    return app.exec();
}

