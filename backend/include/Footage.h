#ifndef FOOTAGE_H
#define FOOTAGE_H

#include <iostream>
#include <fstream>
using namespace std;

class Footage {
    int cameraId;
    char date[12];
    char time[10];
    int duration;
    char location[50];

public:
    void addFootage();
    void displayFootage() const;
    int getCameraId() const;
};


void searchFootage(int id);
void deleteFootage(int id);

#endif
