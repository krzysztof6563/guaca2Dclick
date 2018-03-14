#include "saving.h"

bool loadGame(char n){
    std::string savePath = "SAVE.";
    savePath = "saves/"+savePath+n;
    std::ifstream saveFile (savePath);
    if (saveFile.good()){
        qDebug() << "Otworzono plik z zapisem (in)";
        std::getline(saveFile, gGl.currentStage);
        gGl.currentStage = MainWindow::fromAscii(gGl.currentStage);
        int l = gGl.currentStage.length();
        gGl.currentStage = gGl.currentStage.substr(gGl._b.length()*12, l-28*gGl._b.length()-1);
        std::string s;
        std::getline(saveFile, s);
        s = MainWindow::fromAscii(s);
        for (int i=0;i<invSize;i++){     //inventory
            gGl.inventory[i] = atoi(s.substr(0, s.find(" ")).c_str());
            s = s.substr(s.find(" ", 0)+1, s.length()-s.find(" ", 0)-1);
        }
        std::getline(saveFile, s);
        s = MainWindow::fromAscii(s);
        for (int i=0;i<altTabSize;i++){     //altStageTab
            gGl.altStagesTab[i] = s.substr(0, s.find(" ")).c_str();
            s = s.substr(s.find(" ", 0)+1, s.length()-s.find(" ", 0)-1);
        }
        std::getline(saveFile, s);
        s = MainWindow::fromAscii(s);
        for (int i=0;i<notesSize;i++){     //notes
            gGl.notes[i] = atoi(s.substr(0, s.find(" ")).c_str());
            s = s.substr(s.find(" ", 0)+1, s.length()-s.find(" ", 0)-1);
        }
        saveFile.close();
        return true;
    } else {
        return false;
    }
}

void saveGame(char n){
    std::string savePath = "SAVE.";
    savePath = "saves/"+savePath+n;
    std::cout << savePath;
    std::ofstream saveFile (savePath.c_str());
    if (saveFile.good()){
        saveFile << MainWindow::toAscii(gGl._b+gGl._b2+gGl._b+gGl._b+gGl._b2+gGl._b+gGl._b+gGl._b2+gGl._b+gGl._b+gGl._b2+gGl._b+gGl.currentStage+gGl._b2+gGl._b+gGl._b2+gGl._b+gGl._b2+gGl._b+gGl._b2+gGl._b+gGl._b2+gGl._b+gGl._b2+gGl._b+gGl._b2+gGl._b+gGl._b2+gGl._b+" ") << std::endl;
        for (int i=0;i<invSize;i++){     //inventory
            std::string s = std::to_string(gGl.inventory[i]);
            saveFile << MainWindow::toAscii(s+" ");
        }
        saveFile << std::endl;
        for (int i=0;i<altTabSize;i++){     //altStageTab
            saveFile << MainWindow::toAscii(gGl.altStagesTab[i]+" ");
        }
        saveFile << std::endl;
        for (int i=0;i<notesSize;i++){     //notes
            std::string s = std::to_string(gGl.notes[i]);
            saveFile << MainWindow::toAscii(s+" ");
        }
        MainWindow::showMsgBox("Pomyślnie zapisano grę", "Zapis gry");
    } else {
        MainWindow::showMsgBox("Nie udało się zapisać gry", "Zapis gry");
        return;
    }
    saveFile.close();
}
