#include "LN200.h"
#include <iostream>
#include <synccom.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(void)
{
    LN200* myLN200 = new LN200();

    cout << "Hello Eric, how's the IMU?" << endl;
    /*
    cout << myLN200->GetBuffer() << endl;
    uint8_t odata[26];
    int words = read(myLN200->GetHandle(), odata, sizeof(odata));
    int16_t raw_LN200_data[13];
    for (int i = 0; i < 13; i++)
    {
        raw_LN200_data[i] = odata[2*i] + (odata[2*i+1] << 8);
    }
    fprintf(stdout, "%f\n", raw_LN200_data[2]/16384.0/(1./400.));
    */
    ///myLN200->ReadIMU();
    //int16_t buffer[];
    //buffer = myLN200->GetBuffer();



    for (int i = 0; i < 10; i++)
    {
        cout << "Accel_z(" << i << "): " << myLN200->GetAccelZ() << endl;
    }

    delete myLN200;
    
    return 0;
}
