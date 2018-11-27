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
    
    /**
     *  @brief  Creates an empty %removeForm.
     */
    removeForm();
    
    /**
     *  @brief  Creates a %removeForm with a specific set of events.
     *  @param  events  The set of events, as a vector<RandomEvent>.
     */
    removeForm(vector <RandomEvent>*);
    
    virtual ~removeForm();
    
    /**
     *  @brief  Returns the index of the event to remove.
     */
    int selectedID();
    
private:
    Ui::removeForm widget;
    vector <RandomEvent> *events;
};

#endif /* _REMOVEFORM_H */
