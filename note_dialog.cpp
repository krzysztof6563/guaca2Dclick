#include "note_dialog.h"
#include "ui_note_dialog.h"

std::fstream inNotes;

note_dialog::note_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::note_dialog)
{
    ui->setupUi(this);
    loadNote(gGl.note);
    setBackground();
    setText();
    setTitle();
    setColor();
    QShortcut * shortcut = new QShortcut(QKeySequence(Qt::Key_Escape | Qt::Key_Return),this,SLOT(close()));
}

note_dialog::~note_dialog()
{
    delete ui;
}

void note_dialog::setBackground(){
    qDebug() << gGl.note;
    this->setStyleSheet("border-image: url('"+QString::fromStdString(nT.bg)+"') 0 0 0 0 stretch stretch;");
    this->ui->label->setFixedWidth(ui->scrollArea->width());
    this->ui->label->setFixedHeight(ui->scrollArea->height());
//    this->ui->label->setStyleSheet("border-color: url('data/images/eq/0.png') 0 0 0 0 stretch stretch;");
//    this->ui->scrollArea->setStyleSheet("border-color: url('data/images/eq/0.png') 0 0 0 0 stretch stretch;");
}

void note_dialog::setText(){
    this->ui->label->setText(QString::fromStdString(nT.text));
}
void note_dialog::setTitle(){
    this->setWindowTitle(QString::fromStdString(nT.title));
}

void note_dialog::setColor(){
    ui->label->setStyleSheet("color : "+QString::fromStdString(nT.color)+"; border-image: none");
}

bool openNotesFile(){
    if (!inNotes.is_open()){
        inNotes.open("data/notes");
    } else {
        inNotes.clear();
        inNotes.seekg(0, std::ios::beg);
    }
    if (inNotes.good()){
        return true;
    } else {
        return false;
    }
}

QString loadNote(int i){
    std::string line2;
    if (openNotesFile()){
        while(!inNotes.eof()){
            std::getline(inNotes, line2);
            std::string s = std::to_string(i);
            if (line2.substr(0,line2.find("=")) == s){
                do{
                    std::getline(inNotes, line2);
                    std::string sw = extractLine(line2, 1);
                    if (sw == "text"){
                        nT.text = extractLine(line2, 0);
                        continue;
                    }
                    if (sw == "title"){
                        nT.title = extractLine(line2, 0);
                        continue;
                    }
                    if (sw == "bg"){
                        nT.bg = extractLine(line2, 0);
                        continue;
                    }
                    if (sw == "thumb"){
                        nT.thumb = extractLine(line2, 0);
                        continue;
                    }
                    if (sw == "color"){
                        nT.color = extractLine(line2, 0);
                        continue;
                    }
                }while(line2 != "}");
            }
        }
        return "Nie znaleziono notatki";
    }
    return "Nie otworzono pliku";
}
