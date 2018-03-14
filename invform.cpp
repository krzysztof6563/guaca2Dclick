#include "invform.h"
#include "ui_invform.h"

int sel[2] = {0,0};

invForm::invForm(QWidget *parent) : QDialog(parent),
    ui(new Ui::invForm)
{
    ui->setupUi(this);

    connect(ui->label_1, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_2, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_3, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_4, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_5, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_6, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_7, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_8, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_9, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));
    connect(ui->label_10, SIGNAL(MouseClicked()), this, SLOT(QLClicked()));

    setItems();
    this->adjustSize();
    ui->exitButton->setDefault(true);
}

invForm::~invForm()
{
    delete ui;
    sel[0] = 0;
    sel[1] = 0;
}

void invForm::setItems(){
    QPixmap p;

    if (gGl.inventory[0] != 0 ){
        p.load(getItemProp(gGl.inventory[0], "i"));
        ui->label_1->setPixmap(p.scaled(ui->label_1->width(), ui->label_1->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel1->setText(getItemProp(gGl.inventory[0], "t"));
        ui->label_1->setToolTip(getItemProp(gGl.inventory[0], "tt"));
        ui->label_1->setHidden(false);

        ui->textLabel1->setHidden(false);
    } else {
        ui->label_1->setHidden(true);
        ui->textLabel1->setHidden(true);
    }

    if (gGl.inventory[1] != 0 ){
        p.load(getItemProp(gGl.inventory[1], "i"));
        ui->label_2->setPixmap(p.scaled(ui->label_2->width(), ui->label_2->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel2->setText(getItemProp(gGl.inventory[1], "t"));
        ui->label_2->setToolTip(getItemProp(gGl.inventory[1], "tt"));
        ui->label_2->setHidden(false);
        ui->textLabel2->setHidden(false);
    } else {
        ui->label_2->setHidden(true);
        ui->textLabel2->setHidden(true);
    }

    if (gGl.inventory[2] != 0 ){
        p.load(getItemProp(gGl.inventory[2], "i"));
        ui->label_3->setPixmap(p.scaled(ui->label_3->width(), ui->label_3->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel3->setText(getItemProp(gGl.inventory[2], "t"));
        ui->label_3->setToolTip(getItemProp(gGl.inventory[2], "tt"));
        ui->label_3->setHidden(false);
        ui->textLabel3->setHidden(false);
    } else {
        ui->label_3->setHidden(true);
        ui->textLabel3->setHidden(true);
    }

    if (gGl.inventory[3] != 0 ){
        p.load(getItemProp(gGl.inventory[3], "i"));
        ui->label_4->setPixmap(p.scaled(ui->label_4->width(), ui->label_4->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel4->setText(getItemProp(gGl.inventory[3], "t"));
        ui->label_4->setToolTip(getItemProp(gGl.inventory[3], "tt"));
        ui->label_4->setHidden(false);
        ui->textLabel4->setHidden(false);
    } else {
        ui->label_4->setHidden(true);
        ui->textLabel4->setHidden(true);
    }

    if (gGl.inventory[4] != 0 ){
        p.load(getItemProp(gGl.inventory[4], "i"));
        ui->label_5->setPixmap(p.scaled(ui->label_5->width(), ui->label_5->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel5->setText(getItemProp(gGl.inventory[4], "t"));
        ui->label_5->setToolTip(getItemProp(gGl.inventory[4], "tt"));
        ui->label_5->setHidden(false);
        ui->textLabel5->setHidden(false);
    } else {
        ui->label_5->setHidden(true);
        ui->textLabel5->setHidden(true);
    }

    if (gGl.inventory[5] != 0 ){
        p.load(getItemProp(gGl.inventory[5], "i"));
        ui->label_6->setPixmap(p.scaled(ui->label_6->width(), ui->label_6->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel6->setText(getItemProp(gGl.inventory[5], "t"));
        ui->label_6->setToolTip(getItemProp(gGl.inventory[5], "tt"));
        ui->label_6->setHidden(false);
        ui->textLabel6->setHidden(false);
    } else {
        ui->label_6->setHidden(true);
        ui->textLabel6->setHidden(true);
    }

    if (gGl.inventory[6] != 0 ){
        p.load(getItemProp(gGl.inventory[6], "i"));
        ui->label_7->setPixmap(p.scaled(ui->label_7->width(), ui->label_7->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel7->setText(getItemProp(gGl.inventory[6], "t"));
        ui->label_7->setToolTip(getItemProp(gGl.inventory[6], "tt"));
        ui->label_7->setHidden(false);
        ui->textLabel7->setHidden(false);
    } else {
        ui->label_7->setHidden(true);
        ui->textLabel7->setHidden(true);
    }

    if (gGl.inventory[7] != 0 ){
        p.load(getItemProp(gGl.inventory[7], "i"));
        ui->label_8->setPixmap(p.scaled(ui->label_8->width(), ui->label_8->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel8->setText(getItemProp(gGl.inventory[7], "t"));
        ui->label_8->setToolTip(getItemProp(gGl.inventory[7], "tt"));
        ui->label_8->setHidden(false);
        ui->textLabel8->setHidden(false);
    } else {
        ui->label_8->setHidden(true);
        ui->textLabel8->setHidden(true);
    }

    if (gGl.inventory[8] != 0 ){
        p.load(getItemProp(gGl.inventory[8], "i"));
        ui->label_9->setPixmap(p.scaled(ui->label_9->width(), ui->label_9->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel9->setText(getItemProp(gGl.inventory[8], "t"));
        ui->label_9->setToolTip(getItemProp(gGl.inventory[8], "tt"));
        ui->label_9->setHidden(false);
        ui->textLabel9->setHidden(false);
    } else {
        ui->label_9->setHidden(true);
        ui->textLabel9->setHidden(true);
    }

    if (gGl.inventory[9] != 0 ){
        p.load(getItemProp(gGl.inventory[9], "i"));
        ui->label_10->setPixmap(p.scaled(ui->label_10->width(), ui->label_10->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->textLabel10->setText(getItemProp(gGl.inventory[9], "t"));
        ui->label_10->setToolTip(getItemProp(gGl.inventory[9], "tt"));
        ui->label_10->setHidden(false);
        ui->textLabel10->setHidden(false);
    } else {
        ui->label_10->setHidden(true);
        ui->textLabel10->setHidden(true);
    }
}

int isSel(int i){
    //sprawdzenie czy są już zaznaczone itemy
    if (sel[0] == i)
        return 0;
     else if (sel[1] == i)
        return 1;
        else return -1;
}

void invForm::QLClicked()
{
    //obsługa kliknięć (ramki itp.)
    if (sender() == ui->label_1){
        if (isSel(1) == -1){
                    if (sel[0] == 0){
                        sel[0] = 1;
                        ui->label_1->setStyleSheet(selected1Style);
                    } else{
                        if (sel[1] == 0){
                            sel[1] = 1;
                            ui->label_1->setStyleSheet(selected2Style);
                        }
                    }

                } else {
                    ui->label_1->setStyleSheet(nonSelectedStyle);
                    sel[isSel(1)] = 0;
                }
    }
    if (sender() == ui->label_2){
        if (isSel(2) == -1){
                    if (sel[0] == 0){
                        sel[0] = 2;
                        ui->label_2->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 2;
                            ui->label_2->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_2->setStyleSheet(nonSelectedStyle);
                    sel[isSel(2)] = 0;
                }
    }
    if (sender() == ui->label_3){
        if (isSel(3) == -1){
                    if (sel[0] == 0){
                        sel[0] = 3;
                        ui->label_3->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 3;
                            ui->label_3->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_3->setStyleSheet(nonSelectedStyle);
                    sel[isSel(3)] = 0;
                }
    }
    if (sender() == ui->label_4){
        if (isSel(4) == -1){
                    if (sel[0] == 0){
                        sel[0] = 4;
                        ui->label_4->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 4;
                            ui->label_4->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_4->setStyleSheet(nonSelectedStyle);
                    sel[isSel(4)] = 0;
                }
    }
    if (sender() == ui->label_5){
        if (isSel(5) == -1){
                    if (sel[0] == 0){
                        sel[0] = 5;
                        ui->label_5->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 5;
                            ui->label_5->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_5->setStyleSheet(nonSelectedStyle);
                    sel[isSel(5)] = 0;
                }
    }
    if (sender() == ui->label_6){
        if (isSel(6) == -1){
                    if (sel[0] == 0){
                        sel[0] = 6;
                        ui->label_6->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 6;
                            ui->label_6->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_6->setStyleSheet(nonSelectedStyle);
                    sel[isSel(6)] = 0;
                }
    }
    if (sender() == ui->label_7){
        if (isSel(7) == -1){
                    if (sel[0] == 0){
                        sel[0] = 7;
                        ui->label_7->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 7;
                            ui->label_7->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_7->setStyleSheet(nonSelectedStyle);
                    sel[isSel(7)] = 0;
                }
    }
    if (sender() == ui->label_8){
        if (isSel(8) == -1){
                    if (sel[0] == 0){
                        sel[0] = 8;
                        ui->label_8->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 8;
                            ui->label_8->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_8->setStyleSheet(nonSelectedStyle);
                    sel[isSel(8)] = 0;
                }
    }
    if (sender() == ui->label_9){
        if (isSel(9) == -1){
                    if (sel[0] == 0){
                        sel[0] = 9;
                        ui->label_9->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 9;
                            ui->label_9->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_9->setStyleSheet(nonSelectedStyle);
                    sel[isSel(9)] = 0;
                }
    }
    if (sender() == ui->label_10){
        if (isSel(10) == -1){
                    if (sel[0] == 0){
                        sel[0] = 10;
                        ui->label_10->setStyleSheet(selected1Style);
                    }  else{
                        if (sel[1] == 0){
                            sel[1] = 10;
                            ui->label_10->setStyleSheet(selected2Style);
                        }
                    }
                } else {
                    ui->label_10->setStyleSheet(nonSelectedStyle);
                    sel[isSel(10)] = 0;
                }
    }
}

void invForm::uncheckAll()
{
    ui->label_1->setStyleSheet(nonSelectedStyle);
    ui->label_2->setStyleSheet(nonSelectedStyle);
    ui->label_3->setStyleSheet(nonSelectedStyle);
    ui->label_4->setStyleSheet(nonSelectedStyle);
    ui->label_5->setStyleSheet(nonSelectedStyle);
    ui->label_6->setStyleSheet(nonSelectedStyle);
    ui->label_7->setStyleSheet(nonSelectedStyle);
    ui->label_8->setStyleSheet(nonSelectedStyle);
    ui->label_9->setStyleSheet(nonSelectedStyle);
    ui->label_10->setStyleSheet(nonSelectedStyle);
}

void invForm::clearAndSort()
{
    std::sort(gGl.inventory, gGl.inventory+invSize, std::greater<int>());
    uncheckAll();
    sel[0] = 0;
    sel[1] = 0;
    setItems();
    this->adjustSize();
}

void invForm::on_combineButton_clicked()
{
    if (sel[0] == 0 && sel[1] != 0){
        MainWindow::showMsgBox("Wybrałeś tylko jeden przedmiot.","Błąd");
        return;
    }else{
        if (sel[0] != 0 && sel[1] == 0){
            MainWindow::showMsgBox("Wybrałeś tylko jeden przedmiot.","Błąd");
            return;
        }else{
            if (sel[0] == 0 && sel[1] == 0){
                MainWindow::showMsgBox("Wybierz przedmioty do połączenia.","Błąd");
                return;
            }
        }
    }

    if (sel[0] != 0 && sel[1] != 0){
        int r = combineItems(gGl.inventory[sel[0]-1], gGl.inventory[sel[1]-1]);
        if (r == -2){
            MainWindow::showMsgBox("Nie można wczytać pliku.","Błąd");
        } else {
            if (r == -1){
                MainWindow::showMsgBox("Tych przedmiotów nie połączysz ze sobą", "Błąd");
            } else {
                gGl.SFX = "data/sfx/combine.wav";
                SDLSound::_playSFX();
                gGl.inventory[sel[0]-1] = r;
                gGl.inventory[sel[1]-1] = 0;
                clearAndSort();
            }
        }
    }
}


void invForm::on_exitButton_clicked()
{
    this->close();
}

void invForm::on_pushButton_clicked()
{
    //używanie itemów
    if (gGl.itemNeeded != 0 && gGl.inventory[sel[0]-1] == gGl.itemNeeded && sel[0] != 0){
        if(removeItem() && gGl.altStage != ""){
            emit addAltStageSignal();
        } else {
            emit loadAltStageSignal();
        }
        clearAndSort();
    } else {
        if (sel[0] != 0)
            MainWindow::showMsgBox("Nie możesz teraz użyć tego przedmiotu.", "Ekwipunek");
    }
}
