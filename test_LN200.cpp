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
    double ang = 0;
    for (int i = 0; i < 5000; i++)
    {
        t.reset();

        //cout << "Accel_z(" << i << "): " << dang*400 << endl;
        //cout << "Time elapsed: " << dt << " seconds\n";
        myFile << myLN200->GetAccelX() << "\t";
        myFile << myLN200->GetAccelY() << "\t";
        myFile << myLN200->GetAccelZ() << "\t";
        myFile << myLN200->GetOmegaX() << "\t";
        myFile << myLN200->GetOmegaY() << "\t";
        myFile << myLN200->GetOmegaZ() << endl;
    }

    myFile.close();

    delete myLN200;
    
    return 0;
}
