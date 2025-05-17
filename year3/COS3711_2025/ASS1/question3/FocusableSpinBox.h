#ifndef FOCUSABLESPINBOX_H
#define FOCUSABLESPINBOX_H

#include <QDoubleSpinBox>
#include <QFocusEvent>

class FocusableSpinBox : public QDoubleSpinBox {
    Q_OBJECT
public:
    explicit FocusableSpinBox(QWidget *parent = nullptr) : QDoubleSpinBox(parent) {}

signals:
    void gotFocus();

protected:
    void focusInEvent(QFocusEvent *event) override {
        emit gotFocus();
        QDoubleSpinBox::focusInEvent(event);
    }
};

#endif // FOCUSABLESPINBOX_H
