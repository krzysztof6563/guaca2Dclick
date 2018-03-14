#include "inventory.h"

std::ifstream inItems;
std::ifstream inCombine;

bool addItem(){
    for (int i=0; i<invSize;i++){
        if (gGl.inventory[i] == 0){
            gGl.inventory[i] = gGl.itemObtained;
            MainWindow::showMsgBox("Przedmiot "+getItemProp(gGl.itemObtained, "t")+" dodano do ekwipunku", "Ekwipunek");
            gGl.itemObtained = 0;
            std::sort(gGl.inventory, gGl.inventory+invSize, std::greater<int>());
            return true;
        }
    }
    MainWindow::showMsgBox("Do ekwipunku nie dodano przedmiotu "+getItemProp(gGl.itemObtained, "t"), "Ekwipunek");
    return false;
}

bool removeItem(){
    for (int i=0; i<invSize;i++){
        if (gGl.inventory[i] == gGl.itemNeeded){
            gGl.inventory[i] = 0;
            MainWindow::showMsgBox("Przedmiot "+getItemProp(gGl.itemNeeded, "t")+" został użyty", "Ekwipunek");
            gGl.itemNeeded = 0;
            std::sort(gGl.inventory, gGl.inventory+invSize, std::greater<int>());
            return true;
        }
    }
    MainWindow::showMsgBox("Nie znaleziono potrzebnego przedmiotu.", "Ekwipunek");
    return false;
}

bool openItemsFile(){
    if (!inItems.is_open()){
        inItems.open("data/items");
    } else {
        inItems.clear();
        inItems.seekg(0, std::ios::beg);
    }
    if (inItems.good()){
        return true;
    } else {
        return false;
    }
}

QString getItemProp(int i, std::string f){
    std::string line2;
    if (openItemsFile()){
        while(!inItems.eof()){
            std::getline(inItems, line2);
            std::string s = std::to_string(i);
            if (line2.substr(0,line2.find("=")) == s){
                if (f == "t"){
                    std::getline(inItems, line2);
                    return QString::fromStdString(line2);
                }
                if (f == "i"){
                    std::getline(inItems, line2);
                    std::getline(inItems, line2);
                    return QString::fromStdString(line2);
                }
                if (f == "tt"){
                    std::getline(inItems, line2);
                    std::getline(inItems, line2);
                    std::getline(inItems, line2);
                    return QString::fromStdString(line2);
                }
            }
        }
        return "Nie znaleziono przedmiotu";
    }
    return "Nie otworzono pliku";
}

void extrLine(std::string &d,std::string &e,std::string &f,std::string line){
    d = line.substr(0, line.find(" "));
    line = line.substr(line.find(" ", 0)+1, line.length()-line.find(" ", 0)-1);
    e = line.substr(0, line.find(" "));
    line = line.substr(line.find(" ", 0)+1, line.length()-line.find(" ", 0)-1);
    f = line.substr(0, line.find(" "));
}

int combineItems(int a, int b){
    std::string line, d, e, f;
    inCombine.open("data/combined_items");
    if (inCombine.good()){
        while(!inCombine.eof()){
            std::getline(inCombine, line);
            extrLine(d, e, f, line);
            int d2 = atoi(d.c_str());
            int e2 = atoi(e.c_str());
            if ((a == d2 && b == e2) || (a == e2 && b == d2)){
                inCombine.close();
                return stoi(f);
            }
        }
        inCombine.close();
        return -1;
    } else {
        inCombine.close();
        return -2;
    }

}

