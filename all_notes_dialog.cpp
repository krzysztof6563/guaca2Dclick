#include "all_notes_dialog.h"
#include "ui_all_notes_dialog.h"

all_notes_dialog::all_notes_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::all_notes_dialog)
{
    ui->setupUi(this);
    setNotes();
    this->adjustSize();
}

all_notes_dialog::~all_notes_dialog()
{
    delete ui;
}

void all_notes_dialog::setNotes(){
    if (gGl.notes[0] != 0){
        loadNote(gGl.notes[0]);
        ui->note_1->setHidden(false);
        ui->note_1->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_1->setText(QString::fromStdString(nT.title));
    } else ui->note_1->setHidden(true) ;

    if (gGl.notes[1] != 0){
        loadNote(gGl.notes[1]);
        ui->note_2->setHidden(false);
        ui->note_2->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_2->setText(QString::fromStdString(nT.title));
    } else ui->note_2->setHidden(true);

    if (gGl.notes[2] != 0){
        loadNote(gGl.notes[2]);
        ui->note_3->setHidden(false);
        ui->note_3->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_3->setText(QString::fromStdString(nT.title));
    } else ui->note_3->setHidden(true);

    if (gGl.notes[3] != 0){
        loadNote(gGl.notes[3]);
        ui->note_4->setHidden(false);
        ui->note_4->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_4->setText(QString::fromStdString(nT.title));
    } else ui->note_4->setHidden(true);

    if (gGl.notes[4] != 0){
        loadNote(gGl.notes[4]);
        ui->note_5->setHidden(false);
        ui->note_5->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_5->setText(QString::fromStdString(nT.title));
    } else ui->note_5->setHidden(true);

    if (gGl.notes[5] != 0){
        loadNote(gGl.notes[5]);
        ui->note_6->setHidden(false);
        ui->note_6->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_6->setText(QString::fromStdString(nT.title));
    } else ui->note_6->setHidden(true);

    if (gGl.notes[6] != 0){
        loadNote(gGl.notes[6]);
        ui->note_7->setHidden(false);
        ui->note_7->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_7->setText(QString::fromStdString(nT.title));
    } else ui->note_7->setHidden(true);

    if (gGl.notes[7] != 0){
        loadNote(gGl.notes[7]);
        ui->note_8->setHidden(false);
        ui->note_8->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_8->setText(QString::fromStdString(nT.title));
    } else ui->note_8->setHidden(true);

    if (gGl.notes[8] != 0){
        loadNote(gGl.notes[8]);
        ui->note_9->setHidden(false);
        ui->note_9->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_9->setText(QString::fromStdString(nT.title));
    } else ui->note_9->setHidden(true);

    if (gGl.notes[9] != 0){
        loadNote(gGl.notes[9]);
        ui->note_10->setHidden(false);
        ui->note_10->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_10->setText(QString::fromStdString(nT.title));
    } else ui->note_10->setHidden(true);

    if (gGl.notes[10] != 0){
        loadNote(gGl.notes[10]);
        ui->note_11->setHidden(false);
        ui->note_11->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_11->setText(QString::fromStdString(nT.title));
    } else ui->note_11->setHidden(true);

    if (gGl.notes[11] != 0){
        loadNote(gGl.notes[11]);
        ui->note_12->setHidden(false);
        ui->note_12->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_12->setText(QString::fromStdString(nT.title));
    } else ui->note_12->setHidden(true);

    if (gGl.notes[12] != 0){
        loadNote(gGl.notes[12]);
        ui->note_13->setHidden(false);
        ui->note_13->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_13->setText(QString::fromStdString(nT.title));
    } else ui->note_13->setHidden(true);

    if (gGl.notes[13] != 0){
        loadNote(gGl.notes[13]);
        ui->note_14->setHidden(false);
        ui->note_14->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_14->setText(QString::fromStdString(nT.title));
    } else ui->note_14->setHidden(true);

    if (gGl.notes[14] != 0){
        loadNote(gGl.notes[14]);
        ui->note_15->setHidden(false);
        ui->note_15->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_15->setText(QString::fromStdString(nT.title));
    } else ui->note_15->setHidden(true);

    if (gGl.notes[15] != 0){
        loadNote(gGl.notes[15]);
        ui->note_16->setHidden(false);
        ui->note_16->setStyleSheet("border-image: url('"+QString::fromStdString(nT.thumb)+"') 0 0 0 0 stretch stretch; color: "+QString::fromStdString(nT.color)+";");
        ui->note_16->setText(QString::fromStdString(nT.title));
    } else ui->note_16->setHidden(true);
}


void all_notes_dialog::on_note_1_clicked()
{
    displayNote(gGl.notes[0]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_2_clicked()
{
    displayNote(gGl.notes[1]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_3_clicked()
{
    displayNote(gGl.notes[2]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_4_clicked()
{
    displayNote(gGl.notes[3]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_5_clicked()
{
    displayNote(gGl.notes[4]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_6_clicked()
{
    displayNote(gGl.notes[5]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_7_clicked()
{
    displayNote(gGl.notes[6]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_8_clicked()
{
    displayNote(gGl.notes[7]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_9_clicked()
{
    displayNote(gGl.notes[8]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_10_clicked()
{
    displayNote(gGl.notes[9]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_11_clicked()
{
    displayNote(gGl.notes[10]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_12_clicked()
{
    displayNote(gGl.notes[11]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_13_clicked()
{
    displayNote(gGl.notes[12]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_14_clicked()
{
    displayNote(gGl.notes[13]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_15_clicked()
{
    displayNote(gGl.notes[14]);
    gGl.note = 0;
}

void all_notes_dialog::on_note_16_clicked()
{
    displayNote(gGl.notes[15]);
    gGl.note = 0;
}
