#ifndef INVENTORY_H
#define INVENTORY_H

#include <QString>
#include <fstream>
#include "mainwindow.h"

bool addItem();
bool removeItem();
bool openItemsFile();

int combineItems(int a, int b);
void extrLine(std::string &a,std::string &b,std::string &c,std::string line);
QString getItemProp(int i, std::string f);

#endif // INVENTORY_H
