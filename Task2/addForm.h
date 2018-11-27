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
    
    
    /**
     *  @brief  Creates a default %addForm.
     */
    addForm();
    
    virtual ~addForm();
    
    /**
     *  @brief  Returns the name of the "list" event.
     */
    QString getEventName();
    
    /**
     *  @brief  Returns string data from a table column as a QStringList.
     *  @param  col  The column index.
     */
    QStringList getColumnList(int);
   
    /**
     *  @brief  Returns the outcome probabilities as a vector<double>.
     */
    vector <double> getProbabilities();

private slots:
    void on_lineEdit_textChanged(QString);
    void on_spinBox_valueChanged(int);
    void on_tableWidget_cellChanged(int, int);
    
private:
    Ui::addForm widget;
    
};

#endif /* _ADDFORM_H */
