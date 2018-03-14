#ifndef PUZZLEFORM_H
#define PUZZLEFORM_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <fstream>
#include "mouse_qlabel.h"
#include "mainwindow.h"

namespace Ui {
class puzzleForm;
}

class puzzleForm : public QDialog
{
    Q_OBJECT

public:
    explicit puzzleForm(QWidget *parent = 0);
    ~puzzleForm();

signals:
    void qLClickedSignal();

private slots:
    void qLClickedSlot();

private:
    Ui::puzzleForm *ui;

    void loadFromFile();
    bool openPuzzleFile();
    QPixmap pixmapTab[4][5];
    void setQLabelImg();
    void checkForWin();
};

#endif // PUZZLEFORM_H
