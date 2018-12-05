#ifndef _MAINFORM_H
#define _MAINFORM_H

#include "ui_mainForm.h"
#include "archives.h"
#include <direct.h>
#include <vector>
#include <QFileDialog>
#include <QMessageBox>
#include <archive.h>
#include <archive_entry.h>

class mainForm : public QMainWindow {
    Q_OBJECT
    
public:
    mainForm();
    virtual ~mainForm();
    
private slots:
    void on_actionOpen_File_triggered();
    void on_actionUnpack_triggered();
    
private:
    Ui::mainForm widget;
    QString filePath;
    
    QTreeWidgetItem *addTreeRoot(QString, QString);
    QTreeWidgetItem *addTreeChild(QTreeWidgetItem*, QString, QString);
    
    bool isFolder(QString);
    int treeLevel(QString);
    QString lastPathElement(QString);
    
};

        
#endif /* _MAINFORM_H */
