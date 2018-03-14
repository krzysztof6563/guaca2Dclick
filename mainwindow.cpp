#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "load.h"
#include "inventory.h"
#include "sound.h"
#include "invform.h"
#include "keypad.h"
#include "note.h"
#include "note_dialog.h"
#include "all_notes_dialog.h"
#include "puzzleform.h"

struct gameGlobals gGl;
struct Note nT;
std::fstream inConfig;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setShortcuts();
    (this)->setStyleSheet("background-image: url('data/images/ui/bg.jpg')");
    ui->buttonAction1->setHidden(true);
    ui->buttonAction2->setHidden(true);
    ui->buttonAction3->setHidden(true);
    ui->buttonAction4->setHidden(true);
    ui->buttonAction1->setStyleSheet("border-radius: 5px;");
    connect(this->ui->ButtonInventory, SIGNAL(clicked()), this, SLOT(on_actionPoka_ekwipunek_triggered()));
    connect(this->ui->ButtonNotes, SIGNAL(clicked()), this, SLOT(on_actionNotatki_triggered()));
    connect(this->ui->ButtonSave, SIGNAL(clicked()), this, SLOT(on_actionSavePlik_1_triggered()));
    connect(this->ui->ButtonLoad, SIGNAL(clicked()), this, SLOT(on_actionPlik_1_triggered()));
}


MainWindow::~MainWindow(){
    saveConf();
    delete ui;
}

void MainWindow::setShortcuts(){
    QShortcut * shortcut = new QShortcut(QKeySequence(Qt::Key_1),ui->buttonAction1,SLOT(click()));
    shortcut = new QShortcut(QKeySequence(Qt::Key_2),ui->buttonAction2,SLOT(click()));
    shortcut = new QShortcut(QKeySequence(Qt::Key_3),ui->buttonAction3,SLOT(click()));
    shortcut = new QShortcut(QKeySequence(Qt::Key_4),ui->buttonAction4,SLOT(click()));
    shortcut = new QShortcut(QKeySequence(Qt::Key_I),this, SLOT(on_actionPoka_ekwipunek_triggered()));
    shortcut = new QShortcut(QKeySequence(Qt::Key_O),this, SLOT(on_actionNotatki_triggered()));
}

void MainWindow::setMsgBox(QMessageBox &msgBox, QString str, QString title){
    msgBox.setWindowFlags(Qt::Popup);
    msgBox.setWindowTitle(title);
    msgBox.setText("<p style='text-align: center;margin: auto; border: 0px; text-indent: 0px'>"+str+"</p>");
    msgBox.setStyleSheet("background: #222; text-align: center; margin: 0 auto");
    msgBox.setStandardButtons(0);
    auto qpb = msgBox.addButton(QMessageBox::Ok);
    qpb->setStyleSheet("width: 0px; height: 0px; color: #000; border: 0px solid #000; position: fixed; bottom: 10px; right: 10px;");
}

std::__cxx11::string MainWindow::toAscii(std::__cxx11::string str)
{
    std::string returnStr;
    for(unsigned int i=0;i<str.length();i++){
        returnStr += std::to_string((int)(str[i])+666)+" ";
    }

    return returnStr;
}

std::__cxx11::string MainWindow::fromAscii(std::__cxx11::string str)
{
    std::string returnStr;
    while (1==1){     //altStageTab
        if (str != ""){
            returnStr += (char)(std::stoi(str.substr(0, str.find(" ")))-666);
            if (str.find(" ") != std::string::npos)
                str = str.substr(str.find(" ", 0)+1);
            else
                break;
        }else{
            break;
        }

    }
    return returnStr;
}

void MainWindow::showMsgBox(QString str, QString title){
    QMessageBox msgBox;
    //ustawienie stylu
    setMsgBox(msgBox, str, title);
    //auto wyłączanie
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), &msgBox, SLOT(close()));
    timer.start(2000);
    msgBox.exec();
}

void MainWindow::showMsgBox(QString str, QString title, int duration){
    QMessageBox msgBox;
    //ustawienie stylu
    setMsgBox(msgBox, str, title);
    //auto wyłączanie
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), &msgBox, SLOT(close()));
    timer.start(1000*duration);
    msgBox.exec();
}

void MainWindow::setPixmap(){
    QPixmap pixmap;                                                 //obraz
    pixmap.load(QString::fromStdString(gGl.gameImage));
    ui->gameImageLabel->setPixmap(pixmap.scaled(ui->gameImageLabel->width(), ui->gameImageLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::setGameText(){
    ui->gameTextLabel->setText(QString::fromStdString(gGl.gameText));
}

void MainWindow::resizeAll(){
    ui->buttonAction1->setStyleSheet("height: "+(QString)((this)->height()*50/700)+"px;");
    ui->buttonAction3->setStyleSheet("height: "+(QString)((this)->height()*50/700)+"px;");
    ui->gameImageLabel->setStyleSheet("height: "+(QString)((this)->height()*459/700)+"px;");
    ui->gameTextLabel->setStyleSheet("height: "+(QString)(((this)->height()*81/700)+20)+"px;");
    MainWindow::setPixmap();
}

void MainWindow::resizeEvent(){
    MainWindow::resizeAll();
}

void MainWindow::setButton(int i){
    switch (i){
    case 1:
        ui->buttonAction1->setText(QString::fromStdString(gGl.button1Text));    //przycisk 1
        if (gGl.button1IsEnabled == "true"){
            ui->buttonAction1->setHidden(false);
            ui->buttonAction1->setEnabled(true);
        }else{
            ui->buttonAction1->setHidden(true);
            ui->buttonAction1->setEnabled(false);
        }
        break;
    case 2:
        ui->buttonAction2->setText(QString::fromStdString(gGl.button2Text));    //przycisk 2
        if (gGl.button2IsEnabled == "true"){
            ui->buttonAction2->setHidden(false);
            ui->buttonAction2->setEnabled(true);
        }else{
            ui->buttonAction2->setHidden(true);
            ui->buttonAction2->setEnabled(false);
        }
        break;
    case 3:
        ui->buttonAction3->setText(QString::fromStdString(gGl.button3Text));    //przycisk 3
        if (gGl.button3IsEnabled == "true"){
            ui->buttonAction3->setHidden(false);
            ui->buttonAction3->setEnabled(true);
        }else{
            ui->buttonAction3->setHidden(true);
            ui->buttonAction3->setEnabled(false);
        }
        break;
    case 4:
        ui->buttonAction4->setText(QString::fromStdString(gGl.button4Text));    //przycisk 4
        if (gGl.button4IsEnabled == "true"){
            ui->buttonAction4->setHidden(false);
            ui->buttonAction4->setEnabled(true);
        }else{
            ui->buttonAction4->setHidden(true);
            ui->buttonAction4->setEnabled(false);
        }
        break;
    }
}

void MainWindow::addAltStage(){
    if (!checkAltStage(gGl.altStage)){
        for (int i=0; i<altTabSize;i++){
            if (gGl.altStagesTab[i] == ""){
                gGl.altStagesTab[i] = gGl.altStage;
                gGl.altStage = "";
                std::cout << gGl.altStagesTab[i];
                if (gGl.SFXLoc == "action") SDLSound::_playSFX();
                if (gGl.changeAlt == "true"){
                    LoadStage(QString::fromStdString(gGl.altStagesTab[i])+"-alt");
                    MainWindow::setStage();
                }
                return;
            }
        }
    }
}

void MainWindow::setStage(){
    if (gGl.SFXLoc == "enter") SDLSound::_playSFX();
    MainWindow::setPixmap();
    MainWindow::setGameText();
    MainWindow::setButton(1);
    MainWindow::setButton(2);
    MainWindow::setButton(3);
    MainWindow::setButton(4);
    if (gGl.itemObtained != 0 && addItem()){
        MainWindow::addAltStage();
    }
//    if (gGl.itemNeeded != 0){
//        if(removeItem() && gGl.altStage != ""){
//            addAltStage();
//        } else {
//            LoadStage(QString::fromStdString(gGl.currentStage.substr(0,gGl.currentStage.find_last_of('-'))));
//            MainWindow::setStage();
//        }
//    }
    if (gGl.password != ""){
        Keypad k;
        k.setWindowFlags(Qt::Popup);
        connect(&k, SIGNAL(Enter_clicked()), this, SLOT(passIsOk()));
        k.exec();
    }
    if (gGl.note != 0){
        displayNote();
        addNote();
    }
    if (gGl.altStage != "" && gGl.triggerAlt == "true"){
        addAltStage();
    }
    SDLSound::playMusic();
    MainWindow::resizeAll();
    if (checkAltStage(gGl.currentStage))
        (this)->setWindowTitle("Game "+QString::fromStdString(gGl.currentStage)+"-alt");
    else
        (this)->setWindowTitle("Game "+QString::fromStdString(gGl.currentStage));
}

void MainWindow::passIsOk(){
    addAltStage();
}

void MainWindow::addAltStageSlot()
{
    addAltStage();
}

void MainWindow::loadAltStageSlot()
{
    LoadStage(QString::fromStdString(gGl.currentStage.substr(0,gGl.currentStage.find_last_of('-'))));
    setStage();
}

void MainWindow::loadConf(){
    inConfig.open("data/config");
    std::string line;
    std::string l;
    if (inConfig.good()){
        std::getline(inConfig, line);
        //pełny ekran
        if (extractLine(line, 0) == "true"){
            gGl.fullscreen = true;
            ui->actionPe_ny_ekran->setChecked(true);
        } else {
            gGl.fullscreen = false;
            ui->actionPe_ny_ekran->setChecked(false);
        }
        inConfig.close();               //inaczej nie chciało wczytać drugiej linii
        inConfig.open("data/config");
        std::getline(inConfig, l);
        std::getline(inConfig, l);
        //audio
        if (extractLine(l, 0) == "true"){
            gGl.muted = true;
            ui->actionWycisz_gr->setChecked(true);
        } else {
            gGl.muted = false;
            ui->actionWycisz_gr->setChecked(false);
        }

    }
    inConfig.close();
    //przetwarzanie parametrów z lini poleceń
    if (gGl.argc > 1){
        for (auto str: gGl.argv){
            if (str == "-nosound"){
                gGl.muted = true;
                ui->actionWycisz_gr->setChecked(true);
                break;
            }

            if (str == "-sound"){
                gGl.muted = false;
                ui->actionWycisz_gr->setChecked(false);
                break;
            }

            if (str == "-fullscreen"){
                gGl.fullscreen = true;
                ui->actionPe_ny_ekran->setChecked(true);
                break;
            }

            if (str == "-window"){
                gGl.fullscreen = false;
                ui->actionPe_ny_ekran->setChecked(false);
                break;
            }
            if (str.find("-load=") != std::string::npos){
                gGl.currentStage = str.substr(str.find("=")+1);
                if (LoadStage(QString::fromStdString(gGl.currentStage))){
                     MainWindow::setStage();
                }else{
                    MainWindow::showMsgBox("Nie znaleziono żądanego poziomu: "+QString::fromStdString(gGl.currentStage), "");
                }
                break;
            }
        }
    }
    //włączanie/wyłączanie fullscreena
    if (gGl.fullscreen){
        MainWindow::showFullScreen();
    } else {
        MainWindow::showNormal();
    }
}

void MainWindow::saveConf(){
    inConfig.open("data/config",  std::fstream::out | std::fstream::trunc );
    if (inConfig.good()){
        if (gGl.fullscreen){
            inConfig << "fullscreen: \"true\"\n";
        } else {
            inConfig << "fullscreen: \"false\"\n";
        }
        if (gGl.muted){
            inConfig << "muted: \"true\"" << std::endl;
        } else {
            inConfig << "muted: \"false\"" << std::endl;
        }
    }
    inConfig.close();
}


bool MainWindow::checkDate(){
  /*  if(QDate::currentDate().toString("d").toStdString()=="13"){
        ui->menuBar->setHidden(true);
        LoadStage("troll");
        MainWindow::setStage();
        MainWindow::showMsgBox("Wygląda na to, że trolle przejeły władzę nad programem ...", "$1r13ve^&^8");
        return true;
    }else{
    */    return false;
    //}
}

void MainWindow::on_buttonAction1_clicked(){
    if (!MainWindow::checkDate()){
        if (LoadStage(QString::fromStdString(gGl.button1LevelLoad)) == true){
            MainWindow::setStage();
        }else{
            MainWindow::showMsgBox("Nie znaleziono żądanego poziomu: "+QString::fromStdString(gGl.button1LevelLoad), "");
        }
    }
}

void MainWindow::on_buttonAction2_clicked(){
    if (!MainWindow::checkDate()){
        if (LoadStage(QString::fromStdString(gGl.button2LevelLoad)) == true){
            MainWindow::setStage();
        }else{
            MainWindow::showMsgBox("Nie znaleziono żądanego poziomu: "+QString::fromStdString(gGl.button2LevelLoad), "");
        }
    }
}

void MainWindow::on_buttonAction3_clicked(){
    if (!MainWindow::checkDate()){
        if (LoadStage(QString::fromStdString(gGl.button3LevelLoad)) == true){
            MainWindow::setStage();
        }else{
            MainWindow::showMsgBox("Nie znaleziono żądanego poziomu: "+QString::fromStdString(gGl.button3LevelLoad), "");
        }
    }
}

void MainWindow::on_buttonAction4_clicked(){
    if (!MainWindow::checkDate()){
        if (LoadStage(QString::fromStdString(gGl.button4LevelLoad)) == true){
            MainWindow::setStage();
        }else{
            MainWindow::showMsgBox("Nie znaleziono żądanego poziomu: "+QString::fromStdString(gGl.button4LevelLoad), "");
        }
    }
}

void MainWindow::on_actionNowa_gra_triggered(){
    //resetowanie altTab
    for (int i=0;i<altTabSize;i++){
        gGl.altStagesTab[i] = "";
    }
    //reset inventory
    for (int i=0;i<invSize;i++){
        gGl.inventory[i] = 0;
    }
    //reset notatek
    for (int i=0;i<notesSize;i++){
        gGl.notes[i] = 0;
    }
    //ładowanie stagea i ustawienie go
    if (LoadStage("1")){
        MainWindow::setStage();
    }else{
        MainWindow::showMsgBox("Nie znaleziono żądanego poziomu.", "");
    }
}

void MainWindow::on_actionWyjd_triggered()
{
    (this)->close();
}

void MainWindow::on_actionO_autorze_triggered()
{
    if (Mix_Playing(1)){
        Mix_Pause(1);
    }
    QMessageBox msgBox(this);
    QString text = "Autor: Krzysztof Michalski<br><br>Czas kompilacji: ";
    text += __DATE__;
    text += " ";
    text += __TIME__;
    setMsgBox(msgBox, text, "O autorze");
    msgBox.exec();
    if (Mix_Paused  (1))
        Mix_Resume(1);
}

void MainWindow::on_actionSavePlik_1_triggered()
{
    saveGame('1');
}

void MainWindow::on_actionSavePlik_2_triggered()
{
    saveGame('2');
}

void MainWindow::on_actionSavePlik_3_triggered()
{
    saveGame('3');
}

void MainWindow::on_actionSavePlik_4_triggered()
{
    saveGame('4');
}

void MainWindow::on_actionSavePlik_5_triggered()
{
    saveGame('5');
}

void MainWindow::on_actionPlik_1_triggered()
{
    if (loadGame('1')){
        LoadStage(QString::fromStdString(gGl.currentStage));
        MainWindow::setStage();
    } else {
        MainWindow::showMsgBox("Nie udało się wczytać zapisu, plik nie istnieje lub jest uszkodzony.", "Błąd wczytywania", 4);
    }
}

void MainWindow::on_actionPlik_2_triggered()
{
    if (loadGame('2')){
        LoadStage(QString::fromStdString(gGl.currentStage));
        MainWindow::setStage();
    } else {
        MainWindow::showMsgBox("Nie udało się wczytać zapisu, plik nie istnieje lub jest uszkodzony.", "Błąd wczytywania", 4);
    }
}

void MainWindow::on_actionPlik_3_triggered()
{
    if (loadGame('3')){
        LoadStage(QString::fromStdString(gGl.currentStage));
        MainWindow::setStage();
    } else {
        MainWindow::showMsgBox("Nie udało się wczytać zapisu, plik nie istnieje lub jest uszkodzony.", "Błąd wczytywania", 4);
    }
}

void MainWindow::on_actionPlik4_triggered()
{
    if (loadGame('4')){
        LoadStage(QString::fromStdString(gGl.currentStage));
        MainWindow::setStage();
    } else {
        MainWindow::showMsgBox("Nie udało się wczytać zapisu, plik nie istnieje lub jest uszkodzony.", "Błąd wczytywania", 4);
    }
}

void MainWindow::on_actionPlik_5_triggered()
{
    if (loadGame('5')){
        LoadStage(QString::fromStdString(gGl.currentStage));
        MainWindow::setStage();
    } else {
        MainWindow::showMsgBox("Nie udało się wczytać zapisu, plik nie istnieje lub jest uszkodzony.", "Błąd wczytywania", 4);
    }
}

void MainWindow::on_actionPe_ny_ekran_toggled(bool arg1)
{
    if (arg1){
        QMainWindow::showFullScreen();
        gGl.fullscreen = true;
    } else {
        QMainWindow::showNormal();
        gGl.fullscreen = false;
    }

    saveConf();
}

void MainWindow::on_actionPoka_ekwipunek_triggered()
{
    invForm inv;
    inv.setWindowFlags(Qt::Popup);
    connect(&inv, SIGNAL(addAltStageSignal()), this, SLOT(addAltStageSlot()));
    connect(&inv, SIGNAL(loadAltStageSignal()), this, SLOT(loadAltStageSlot()));
    inv.exec();
}

void MainWindow::on_actionNotatki_triggered()
{
    all_notes_dialog an;
    an.setWindowFlags(Qt::Popup);
    an.exec();
}

void MainWindow::on_actionWycisz_gr_toggled(bool arg1)
{
    if (arg1){
        gGl.muted = true;
        SDLSound::playMusic();
    } else {
        gGl.muted = false;
        SDLSound::playMusic();
    }
    saveConf();
}

void MainWindow::on_actionReload_triggered()
{
    LoadStage(QString::fromStdString(gGl.currentStage));
    MainWindow::setStage();
}

void MainWindow::on_actionPuzlle_triggered()
{
    puzzleForm pF;
    pF.exec();
}
