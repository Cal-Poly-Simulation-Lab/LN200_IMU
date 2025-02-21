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

int main(int argc, char *argv[])
{
    LN200* myLN200 = new LN200();

    cout << "Hello Eric, how's the IMU?" << endl;
    
    Timer t; 
    
    int sampleRate = 5; // Hz
    int sampelTime = 30; // seconds
    int n = sampleRate*sampelTime;
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
        t.pause(200);
        myLN200->ReadIMU();
        ax[i] =  myLN200->GetAccelX();
        ay[i] =  myLN200->GetAccelY();
        az[i] =  myLN200->GetAccelZ();

        ox[i] =  myLN200->GetOmegaX();
        oy[i] =  myLN200->GetOmegaY();
        oz[i] =  myLN200->GetOmegaZ();
        dt[i] = t.elapsed();
        cout << dt[i] << endl;
    }

    ofstream myFile;
    myFile.open("LN200_data.txt");

    for (int i = 0; i < n; i++)
    {
        myFile << ax[i] << "\t" << ay[i] << "\t" << az[i] << "\t" << ox[i] << "\t" << oy[i] << "\t" << oz[i] << "\t" << dt[i] << endl;
    }

    myFile.close();

    delete myLN200;
    
    return 0;
}
