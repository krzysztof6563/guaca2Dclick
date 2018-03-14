#ifndef INVFORM_H
#define INVFORM_H

#include <QDialog>
#include <QLabel>
#include "mouse_qlabel.h"
#include "sound.h"
#include "inventory.h"
#include "mainwindow.h"

namespace Ui {
class invForm;
}

class invForm : public QDialog
{
    Q_OBJECT

public:
    explicit invForm(QWidget *parent = 0);
    ~invForm();

private slots:
    void QLClicked();

    void on_combineButton_clicked();

    void on_exitButton_clicked();

    void on_pushButton_clicked();

signals:
    void addAltStageSignal();

    void loadAltStageSignal();
private:
    Ui::invForm *ui; 

    void setItems();

    void uncheckAll();

    void clearAndSort();

    QString selected1Style = "border: 3px solid blue";
    QString selected2Style = "border: 3px solid green";
    QString nonSelectedStyle = "border: 1px solid white";
};

int isSel(int i);

#endif // INVFORM_H
