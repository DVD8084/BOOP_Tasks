/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: DVD
 *
 * Created on 24 октября 2018 г., 13:40
 */

#include <QApplication>
#include "mainForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    mainForm form;
    form.show();
    // create and show your widgets here

    return app.exec();
}
