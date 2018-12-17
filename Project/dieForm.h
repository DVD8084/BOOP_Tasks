#ifndef _DIEFORM_H
#define _DIEFORM_H

#include <QPushButton>
#include "ui_dieForm.h"

/**
 *  @brief  Used to add a "die"-type random event.
 * 
 *  Dice events are list events with a fixed name (Dn) and n even outcomes,
 *  numbered from 1 to n. They are useful for getting random integer values.
 *  Note that it is possible to get numbers from 1 to 9999 using a %dieForm,
 *  while an %addForm can only create 99 possible outcomes for an event.
 */
class dieForm : public QDialog {
    Q_OBJECT
public:
    dieForm();
    virtual ~dieForm();
    
    int getSides();

private slots:
    void on_sideAmount_textChanged(QString);

private:
    Ui::dieForm widget;
};

#endif /* _DIEFORM_H */
