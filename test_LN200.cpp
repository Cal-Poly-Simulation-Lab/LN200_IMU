#include "LN200.h"
#include <iostream>
#include <synccom.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "Timer.h"
#include <fstream>

using namespace std;

int main(void)
{
    LN200* myLN200 = new LN200();

    cout << "Hello Eric, how's the IMU?" << endl;
    ofstream myFile;
    myFile.open("LN200_data.txt");
    Timer t; 
    
    int n = 5000;
    double ax[n] {0};
    double ay[n] {0};
    double az[n] {0};
    double ox[n] {0};
    double oy[n] {0};
    double oz[n] {0};
    double dt[n] {0};

    for (int i = 0; i < n; i++)
    {
        t.reset();
        ax[i] =  myLN200->GetAccelX();
        ay[i] =  myLN200->GetAccelY();
        az[i] =  myLN200->GetAccelZ();

        ox[i] =  myLN200->GetOmegaX();
        ox[i] =  myLN200->GetOmegaY();
        ox[i] =  myLN200->GetOmegaZ();
        dt[i] = t.elapsed();
    }

    for (int i = 0; i < n; i++)
    {
        myFile << ax[i] << "\t";
        myFile << ay[i] << "\t";
        myFile << az[i] << "\t";
        myFile << ox[i] << "\t";
        myFile << oy[i] << "\t";
        myFile << oz[i] << "\t";
        myFile << dt[i] << endl;
    }

    myFile.close();

    delete myLN200;
    
    return 0;
}
