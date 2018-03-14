#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QShortcut>
#include <QDate>
#include <QTimer>
#include <vector>
#include "saving.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class saving;

public:
    explicit MainWindow(QWidget *parent = 0 );
    ~MainWindow();
    static void showMsgBox(QString str, QString title);
    static void showMsgBox(QString str, QString title, int duration);
    static void setMsgBox(QMessageBox &msgBox, QString str, QString title);

    static std::string toAscii(std::string str);
    static std::string fromAscii(std::string str);
public slots:
    void passIsOk();

    void addAltStageSlot();

    void loadAltStageSlot();

    void loadConf();
private slots:
    void on_buttonAction1_clicked();
    void on_buttonAction2_clicked();
    void on_buttonAction3_clicked();
    void on_buttonAction4_clicked();

    void on_actionNowa_gra_triggered();

    void on_actionWyjd_triggered();

    void on_actionO_autorze_triggered();

    void on_actionSavePlik_1_triggered();
    void on_actionSavePlik_2_triggered();
    void on_actionSavePlik_3_triggered();
    void on_actionSavePlik_4_triggered();
    void on_actionSavePlik_5_triggered();

    void on_actionPlik_1_triggered();
    void on_actionPlik_2_triggered();
    void on_actionPlik_3_triggered();
    void on_actionPlik4_triggered();
    void on_actionPlik_5_triggered();

    void on_actionPe_ny_ekran_toggled(bool arg1);

    void resizeEvent();

    void on_actionPoka_ekwipunek_triggered();

    void on_actionNotatki_triggered();

    void on_actionWycisz_gr_toggled(bool arg1);    
    void on_actionReload_triggered();

    void on_actionPuzlle_triggered();

private:
    Ui::MainWindow *ui;

    void setStage();
    void setShortcuts();
    void setPixmap();
    void setGameText();
    void setButton(int i);
    void addAltStage();
    bool checkDate();
    void resizeAll();
    void saveConf();

};

static const int notesSize = 16;
static const int invSize = 10;
static const int altTabSize = 50;


struct gameGlobals {
    std::string currentStage;
    std::string gameText;
    std::string gameImage;
    std::string button1Text;
    std::string button1LevelLoad;
    std::string button1IsEnabled;
    std::string button2Text;
    std::string button2LevelLoad;
    std::string button2IsEnabled;
    std::string button3Text;
    std::string button3LevelLoad;
    std::string button3IsEnabled;
    std::string button4Text;
    std::string button4LevelLoad;
    std::string button4IsEnabled;
    std::string currentMusic = "null";
    std::string newMusic;
    std::string loopMusic;
    std::string SFX;
    std::string playSFX;
    std::string SFXLoc;
    int itemNeeded;
    int itemObtained;
    std::string altStage;
    std::string changeAlt;
    std::string password;
    int note;
    std::string triggerAlt;

    bool muted;
    bool fullscreen;
    std::string line;

    int argc;
    std::vector<std::string> argv;

    int inventory[invSize];
    int notes[notesSize];
    std::string altStagesTab[altTabSize];
    std::string _b = "hax00r124[p5jkhjofhgo42hasfovbwrvnfisobkvpwinbg0qwhbfjoqbv0q3rhg8hvqfubn"; //72
    std::string _b2= "1337fkafgvbvrb93864gf93468fvb8246gfvr34fv634fv893f4v84vf893f4v34fvtqvrf9"; //72
};

struct Note {
    std::string text;
    std::string title;
    std::string bg;
    std::string thumb;
    std::string color;
};

extern struct gameGlobals gGl;
extern struct Note nT;
#endif // MAINWINDOW_H
