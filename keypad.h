#ifndef KEYPAD_H
#define KEYPAD_H

#include <QDialog>
#include <QShortcut>
#include "sound.h"
#include "mainwindow.h"

namespace Ui {
class Keypad;
}

class Keypad : public QDialog
{
    Q_OBJECT

public:
    explicit Keypad(QWidget *parent = 0);
    ~Keypad();

signals:
    void Enter_clicked();

private slots:
    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_bClear_clicked();

    void on_b0_clicked();

    void on_bEnter_clicked();
private:
    Ui::Keypad *ui;
};

#endif // KEYPAD_H
