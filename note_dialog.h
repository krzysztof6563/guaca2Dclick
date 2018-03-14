#ifndef NOTE_DIALOG_H
#define NOTE_DIALOG_H

#include <QDialog>
#include <fstream>
#include "mainwindow.h"
#include "load.h"
#include <QShortcut>

namespace Ui {
class note_dialog;
}

class note_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit note_dialog(QWidget *parent = 0);
    ~note_dialog();

private:
    void setBackground();
    void setText();
    void setTitle();
    void setColor();

    Ui::note_dialog *ui;
};

bool openNotesFile();
std::string extractLine(std::string line, int i);
QString loadNote(int i);

#endif // NOTE_DIALOG_H
