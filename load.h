#ifndef LOAD_H
#define LOAD_H

#include <QString>
#include <string>
#include <fstream>
#include "sound.h"
#include "mainwindow.h"

bool openLevelsFile();
bool LoadStage(QString stage);
std::string extractLine(QString lin, int i);
void setStage();
bool checkAltStage(std::string stage);
void printInfo(QString stage);
void resetGlobals();

//int loadMusic(QString stage);
#endif // LOAD_H
