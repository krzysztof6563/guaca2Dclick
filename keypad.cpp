#include "keypad.h"
#include "ui_keypad.h"

int count;
QString value = "";

Keypad::Keypad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Keypad)
{
    ui->setupUi(this);
    ui->codeDisplay->display("");
    (this)->setStyleSheet("background-image: url('data/images/ui/plate.jpg')");
    ui->b0->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b1->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b2->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b3->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b4->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b5->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b6->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b7->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b8->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->b9->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->bClear->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    ui->bEnter->setStyleSheet("background-image: url('data/images/ui/button.jpg')");
    Keypad::on_bClear_clicked();
}

Keypad::~Keypad()
{
    delete ui;
}

void Keypad::on_b1_clicked()
{
    if (count < 4){
        value+="1";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button1.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}



void Keypad::on_b2_clicked()
{
    if (count < 4){
        value+="2";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button2.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b3_clicked()
{
    if (count < 4){
        value+="3";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button3.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b4_clicked()
{
    if (count < 4){
        value+="4";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button4.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b5_clicked()
{
    if (count < 4){
        value+="5";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button5.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b6_clicked()
{
    if (count < 4){
        value+="6";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button6.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b7_clicked()
{
    if (count < 4){
        value+="7";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button7.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b8_clicked()
{
    if (count < 4){
        value+="8";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button8.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_b9_clicked()
{
    if (count < 4){
        value+="9";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button9.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_bClear_clicked()
{
    ui->codeDisplay->display("");
    value = "";
    count=0;
}

void Keypad::on_b0_clicked()
{
    if (count < 4){
        value+="0";
        ui->codeDisplay->display(value);
        count++;
        gGl.SFX = "data/sfx/keypad_button0.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
    }
}

void Keypad::on_bEnter_clicked()
{
    if (QString::fromStdString(gGl.password) == value && value != ""){
        gGl.SFX = "data/sfx/keypad_correct.wav";
        SDLSound::_playSFX();
        gGl.SFX = "";
        MainWindow::showMsgBox("<b>Kod poprawny</b>", "Kod");
        emit Enter_clicked();
        value = "";
        (this)->close();
    } else {
        MainWindow::showMsgBox("<b>Niepoprawny kod</b>", "Kod");
    }

}
