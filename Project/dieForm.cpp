#include "dieForm.h"

/**
 *  @brief  Creates a default %dieForm. Default amount of sides is 2.
 */
dieForm::dieForm() {
    widget.setupUi(this);
    widget.sideAmount->setText("2");
}

dieForm::~dieForm() {
}


/**
 *  @brief  Check if the side amount is valid.
 * 
 *  If the side amount isn't a valid integer between 1 and 10000
 *  (non-inclusively), the "Ok" button is disabled.
 */
void dieForm::on_sideAmount_textChanged(QString text) {
    bool ok = false;
    int value = 0;
    value = text.toInt(&ok);
    if (!ok || value < 2 || value > 9999) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

/**
 *  @brief  Returns the amount of sides.
 */
int dieForm::getSides() {
    return widget.sideAmount->text().toInt();
}