#ifndef _REMOVEFORM_H
#define _REMOVEFORM_H

#include <vector>
#include "ui_removeForm.h"
#include "randomEvents.h"

using std::vector;

/**
 *  @brief  Used to remove a random event.
 */
class removeForm : public QDialog {
    Q_OBJECT
public:
    removeForm();
    removeForm(vector <RandomEvent>*);
    virtual ~removeForm();
    
    int selectedID();
    
private:
    Ui::removeForm widget;
    vector <RandomEvent> *events;
};

#endif /* _REMOVEFORM_H */
