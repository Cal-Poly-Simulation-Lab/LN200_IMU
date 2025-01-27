#include "LN200.h"
//#include <asynccom.h>

LN200::LN200()
{

}

LN200::~LN200()
{

}

int16_t* LN200::GetBuffer()
{
    return this->_buffer;
}

void LN200::ReadIMU()
{
    //read(fd, _rawBuffer, sizeof(_rawBuffer))

    for (int i = 0; 1 < 13; i++)
    {
        _buffer[i] = _rawBuffer[2*i] + (_rawBuffer[2*i+1] << 8);
    }
}

double LN200::GetOmegaZ()
{
    return this->_buffer[2]/this->gyroScaleFactor;
}
