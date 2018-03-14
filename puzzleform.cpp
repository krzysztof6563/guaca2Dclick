#include "puzzleform.h"
#include "ui_puzzleform.h"

std::fstream inPuzzle;
int puzzleTab[4][5]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

puzzleForm::puzzleForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::puzzleForm)
{
    ui->setupUi(this);
    connect(ui->label_0, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_1, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_2, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_3, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_4, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_5, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_6, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_7, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_8, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_9, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_10, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_11, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_12, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_13, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_14, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_15, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_16, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_17, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_18, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));
    connect(ui->label_19, SIGNAL(MouseClicked()), this, SLOT(qLClickedSlot()));

    std::string pixmapTab[5][4];

    loadFromFile();
    setQLabelImg();
}

puzzleForm::~puzzleForm()
{
    delete ui;
}

bool puzzleForm::openPuzzleFile(){
    if (!inPuzzle.is_open()){
        inPuzzle.open("data/puzzle");
    } else {
        inPuzzle.clear();
        inPuzzle.seekg(0, std::ios::beg);
    }
    if (inPuzzle.good()){
        return true;
    } else {
        return false;
    }
}

void puzzleForm::setQLabelImg()
{
    ui->label_0->setPixmap(pixmapTab[0][0]);
    ui->label_1->setPixmap(pixmapTab[0][1]);
    ui->label_2->setPixmap(pixmapTab[0][2]);
    ui->label_3->setPixmap(pixmapTab[0][3]);
    ui->label_4->setPixmap(pixmapTab[0][4]);
    ui->label_5->setPixmap(pixmapTab[1][0]);
    ui->label_6->setPixmap(pixmapTab[1][1]);
    ui->label_7->setPixmap(pixmapTab[1][2]);
    ui->label_8->setPixmap(pixmapTab[1][3]);
    ui->label_9->setPixmap(pixmapTab[1][4]);
    ui->label_10->setPixmap(pixmapTab[2][0]);
    ui->label_11->setPixmap(pixmapTab[2][1]);
    ui->label_12->setPixmap(pixmapTab[2][2]);
    ui->label_13->setPixmap(pixmapTab[2][3]);
    ui->label_14->setPixmap(pixmapTab[2][4]);
    ui->label_15->setPixmap(pixmapTab[3][0]);
    ui->label_16->setPixmap(pixmapTab[3][1]);
    ui->label_17->setPixmap(pixmapTab[3][2]);
    ui->label_18->setPixmap(pixmapTab[3][3]);
    ui->label_19->setPixmap(pixmapTab[3][4]);

}

void puzzleForm::checkForWin()
{
    if (    puzzleTab[0][0] == 0 &&
            puzzleTab[0][1] == 1 &&
            puzzleTab[0][2] == 2 &&
            puzzleTab[0][3] == 3 &&
            puzzleTab[0][4] == 4 &&
            puzzleTab[1][0] == 5 &&
            puzzleTab[1][1] == 6 &&
            puzzleTab[1][2] == 7 &&
            puzzleTab[1][3] == 8 &&
            puzzleTab[1][4] == 9 &&
            puzzleTab[2][0] == 10 &&
            puzzleTab[2][1] == 11 &&
            puzzleTab[2][2] == 12 &&
            puzzleTab[2][3] == 13 &&
            puzzleTab[2][4] == 14 &&
            puzzleTab[3][0] == 15 &&
            puzzleTab[3][1] == 16 &&
            puzzleTab[3][2] == 17 &&
            puzzleTab[3][3] == 18 &&
            puzzleTab[3][4] == 19 )

        MainWindow::showMsgBox("Wygrałeś", "Wygrałeś");
}

void puzzleForm::loadFromFile()
{
    if(openPuzzleFile()){
        std::string line, s;
        while(!inPuzzle.eof()){
            std::getline(inPuzzle, line);
            if (QString::fromStdString(line.substr(0,line.find("="))) == "1"){
                for (int i=0;i<4;i++){
                    for(int j=0;j<5;j++){
                        inPuzzle >> s;
                        puzzleTab[i][j] = atoi(s.c_str());
                    }

                }
                for (int i=0;i<4;i++){
                    for(int j=0;j<5;j++){
                        qDebug() << puzzleTab[i][j];
                    }
                    qDebug() << "\n";
                }

                for (int i=0;i<4;i++){
                    for(int j=0;j<5;j++){
                        inPuzzle >> s;
                        qDebug() << QString::fromStdString(s);
                        pixmapTab[i][j].load(QString::fromStdString(s));
                    }
                }
                for (int i=0;i<4;i++){
                    for(int j=0;j<5;j++){
                        qDebug() << pixmapTab[i][j];
                    }
                }
            }
        }
    }
}

void puzzleForm::qLClickedSlot()
{
    int i,j;
    if (sender() == ui->label_0){
        i=0;j=0;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i+1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_1){
        i=0;j=1;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i+1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_2){
        i=0;j=2;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i+1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_3){
        i=0;j=3;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i+1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_4){
        i=0;j=4;
        if (puzzleTab[i+1][j] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
            std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
        } else {
            if (puzzleTab[i][j-1] == 0) {
                std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
            }

        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_5){
        i=1;j=0;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_6){
        i=1;j=1;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                } else {
                    if (puzzleTab[i][j-1] == 0){
                        std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                        std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                    }
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_7){
        i=1;j=2;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                } else {
                    if (puzzleTab[i][j-1] == 0){
                        std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                        std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                    }
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_8){
        i=1;j=3;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                } else {
                    if (puzzleTab[i][j-1] == 0){
                        std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                        std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                    }
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_9){
        i=1;j=4;
        if (puzzleTab[i-1][j] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
            std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
        } else {
            if (puzzleTab[i+1][j] == 0) {
                std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0){
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_10){
        i=2;j=0;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_11){
        i=2;j=1;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                } else {
                    if (puzzleTab[i][j-1] == 0){
                        std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                        std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                    }
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_12){
        i=2;j=2;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                } else {
                    if (puzzleTab[i][j-1] == 0){
                        std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                        std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                    }
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_13){
        i=2;j=3;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i+1][j] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                    std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
                } else {
                    if (puzzleTab[i][j-1] == 0){
                        std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                        std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                    }
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_14){
        i=2;j=4;
        if (puzzleTab[i-1][j] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
            std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
        } else {
            if (puzzleTab[i+1][j] == 0) {
                std::swap(pixmapTab[i][j], pixmapTab[i+1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i+1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0){
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_15){
        i=3;j=0;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_16){
        i=3;j=1;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_17){
        i=3;j=2;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_18){
        i=3;j=3;
        if (puzzleTab[i][j+1] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i][j+1]);
            std::swap(puzzleTab[i][j], puzzleTab[i][j+1]);
        }else{
            if (puzzleTab[i-1][j] == 0){
                std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
                std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
            } else {
                if (puzzleTab[i][j-1] == 0) {
                    std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                    std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
                }
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
    if (sender() == ui->label_19){
        i=3;j=4;
        if (puzzleTab[i-1][j] == 0){
            std::swap(pixmapTab[i][j], pixmapTab[i-1][j]);
            std::swap(puzzleTab[i][j], puzzleTab[i-1][j]);
        } else {
            if (puzzleTab[i][j-1] == 0) {
                std::swap(pixmapTab[i][j], pixmapTab[i][j-1]);
                std::swap(puzzleTab[i][j], puzzleTab[i][j-1]);
            }
        }
        setQLabelImg(); checkForWin();
        return;
    }
}


//wczytujemy układ z tablicy gdzie są poszczególne elementy, potem przypisujemy im obrazy za pomocą QPixmap (tablica)?
