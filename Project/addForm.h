#ifndef _ADDFORM_H
#define _ADDFORM_H

#include <vector>
#include <QPushButton>
#include "ui_addForm.h"

using std::vector;

/**
 *  @brief  Used to add a "list"-type random event.
 */
class addForm : public QDialog {
    Q_OBJECT
public:
    addForm();
    virtual ~addForm();
    
    QString getEventName();
    QStringList getColumnList(int);
    vector <double> getProbabilities();

private slots:
    void on_name_textChanged(QString);
    void on_resultAmount_valueChanged(int);
    void on_results_cellChanged(int, int);
    
private:
    Ui::addForm widget;
    
};

#endif /* _ADDFORM_H */
