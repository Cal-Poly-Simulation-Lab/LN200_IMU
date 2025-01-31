#include "LN200.h"
#include <iostream>

using namespace std;

int main(void)
{
    LN200* myLN200 = new LN200();

    cout << "Hello Eric, how's the IMU?" << endl;
    cout << myLN200->GetBuffer() << endl;

    delete myLN200;
    
    return 0;
}
