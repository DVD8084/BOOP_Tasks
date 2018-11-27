#include <QApplication>
#include "mainForm.h"

int main(int argc, char *argv[]) {
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    mainForm form;
    form.show();

    return app.exec();
}
