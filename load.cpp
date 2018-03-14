#include "load.h"

std::ifstream inLevels;

void printInfo(QString stage){
    std::cout << "Stage=" << stage.toStdString() << std::endl
              << "text: " << gGl.gameText << std::endl
              << "image: " << gGl.gameImage << std::endl
              << "button1Text: " << gGl.button1Text << std::endl
              << "button1LevelLoad: " << gGl.button1LevelLoad << std::endl
              << "button1IsEnabled: " << gGl.button1IsEnabled << std::endl
              << "button2Text: " << gGl.button3Text << std::endl
              << "button2LevelLoad: " << gGl.button2LevelLoad << std::endl
              << "button2IsEnabled: " << gGl.button2IsEnabled << std::endl
              << "button3Text: " << gGl.button3Text << std::endl
              << "button3LevelLoad: " << gGl.button3LevelLoad << std::endl
              << "button3IsEnabled: " << gGl.button3IsEnabled << std::endl
              << "button4Text: " << gGl.button4Text << std::endl
              << "button4LevelLoad: " << gGl.button4LevelLoad << std::endl
              << "button4IsEnabled: " << gGl.button4IsEnabled << std::endl
              << "music: " << gGl.newMusic  << std::endl
              << "loopMusic: " << gGl.loopMusic  << std::endl
              << "SFX: " << gGl.SFX  << std::endl
              << "SFXLoc: " << gGl.SFXLoc << std::endl
              << "itemNeeded: " << gGl.itemNeeded  << std::endl
              << "itemObtained: " << gGl.itemObtained  << std::endl
              << "altStage: " << gGl.altStage << std::endl
              << "password: " << gGl.password << std::endl
              << "note: " << gGl.note << std::endl
              << "triggerAlt: " << gGl.triggerAlt << std::endl << std::endl;
}

void resetGlobals(){
    gGl.button1Text = "";
    gGl.button1LevelLoad = "";
    gGl.button1IsEnabled = "false";
    gGl.button2Text = "";
    gGl.button2LevelLoad = "";
    gGl.button2IsEnabled = "false";
    gGl.button3Text = "";
    gGl.button3LevelLoad = "";
    gGl.button3IsEnabled = "false";
    gGl.button4Text = "";
    gGl.button4LevelLoad = "";
    gGl.button4IsEnabled = "false";
    gGl.loopMusic = "true";
    gGl.newMusic = "";
    gGl.SFX = "";
    gGl.SFXLoc = "";
    gGl.itemNeeded = 0;
    gGl.itemObtained = 0;
    gGl.altStage = "";
    gGl.password = "";
    gGl.changeAlt = "true";
    gGl.note = 0;
    gGl.triggerAlt = "";
}

bool checkAltStage(std::string stage){
    for (int i=0; i<altTabSize;i++){
        if(stage == gGl.altStagesTab[i])
            return true;
    }
    return false;
}

bool openLevelsFile(){           //otwieranie pliku z definicjami poziomów
    if (!inLevels.is_open()){
        inLevels.open("data/levels");
    } else {
        inLevels.clear();
        inLevels.seekg(0, std::ios::beg);
    }
    if (inLevels.good()){
        return true;
    } else {
        return false;
    }
}

std::string extractLine(std::string line, int i){      //wyodrębnianie danych z ""
    if (i==0)
        return line.substr(line.find("\"")+1,(line.length()-line.find("\"")-2));
    else
        return line.substr(1, line.find_first_of(':')-1);
}

bool LoadStage(QString stage){      //ładowanie informacji
    bool foundStage = false;
    if (checkAltStage(stage.toStdString())){
        stage += "-alt";
    }
    if (checkAltStage(stage.toStdString())){
        stage += "-alt";
    }
    if (checkAltStage(stage.toStdString())){
        stage += "-alt";
    }
    if (openLevelsFile()){
        std::string line;
        while(!inLevels.eof()){
            std::getline(inLevels, line);
            if (QString::fromStdString(line.substr(0,line.find("="))) == stage){ //szukanie, czy stage jest w pliku
                resetGlobals();
                do{
                    std::getline(inLevels, line);
                    std::string sw = extractLine(line, 1);
                    if (sw == "text"){
                        gGl.gameText = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "image"){
                        gGl.gameImage = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button1Text"){
                        gGl.button1Text = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button1LevelLoad"){
                        gGl.button1LevelLoad = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button1IsEnabled"){
                        gGl.button1IsEnabled = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button2Text"){
                        gGl.button2Text = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button2LevelLoad"){
                        gGl.button2LevelLoad = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button2IsEnabled"){
                        gGl.button2IsEnabled = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button3Text"){
                        gGl.button3Text = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button3LevelLoad"){
                        gGl.button3LevelLoad = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button3IsEnabled"){
                        gGl.button3IsEnabled = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button4Text"){
                        gGl.button4Text = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button4LevelLoad"){
                        gGl.button4LevelLoad = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "button4IsEnabled"){
                        gGl.button4IsEnabled = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "music"){
                        gGl.newMusic = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "loopMusic"){
                        gGl.loopMusic = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "SFX"){
                        gGl.SFX = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "SFXLoc"){
                        gGl.SFXLoc = extractLine(line, 0);
                        continue;
                    }
                    if (sw ==  "itemNeeded"){
                        gGl.itemNeeded = stoi(extractLine(line, 0));
                        continue;
                    }
                    if (sw == "itemObtained"){
                        gGl.itemObtained = stoi(extractLine(line, 0));
                        continue;
                    }
                    if (sw == "altStage"){
                        gGl.altStage = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "password"){
                        gGl.password = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "changeAlt"){
                        gGl.changeAlt = extractLine(line, 0);
                        continue;
                    }
                    if (sw == "note"){
                        gGl.note = stoi(extractLine(line, 0));
                        continue;
                    }
                    if (sw == "triggerAlt"){
                        gGl.triggerAlt = extractLine(line, 0);
                        continue;
                    }
                }while(line != "}");
                printInfo(stage);
                gGl.currentStage = stage.toStdString(); //wczytanie zmiennej currentStage potrzebnej do załadowania saveu
                foundStage = true;
                break;
            }
        }
    } else {
        MainWindow::showMsgBox("Nie udało się wczytać pliku z poziomami", "Błąd");
    }
    if (foundStage)
        return true;
    else
        return false;
}

