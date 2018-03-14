#ifndef ALL_NOTES_DIALOG_H
#define ALL_NOTES_DIALOG_H

#include <QDialog>
#include "note_dialog.h"
#include "note.h"

namespace Ui {
class all_notes_dialog;
}

class all_notes_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit all_notes_dialog(QWidget *parent = 0);
    ~all_notes_dialog();

private slots:

    void on_note_1_clicked();

    void on_note_2_clicked();

    void on_note_3_clicked();

    void on_note_4_clicked();

    void on_note_5_clicked();

    void on_note_6_clicked();

    void on_note_7_clicked();

    void on_note_8_clicked();

    void on_note_9_clicked();

    void on_note_10_clicked();

    void on_note_11_clicked();

    void on_note_12_clicked();

    void on_note_13_clicked();

    void on_note_14_clicked();

    void on_note_15_clicked();

    void on_note_16_clicked();

private:
    void setNotes();
    Ui::all_notes_dialog *ui;
};

#endif // ALL_NOTES_DIALOG_H
