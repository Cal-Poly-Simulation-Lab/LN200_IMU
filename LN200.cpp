#include "LN200.h"
#include <synccom.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using namespace std;

LN200::LN200()
{
    struct synccom_registers regs;

    _handle = open("/dev/synccom0", O_RDWR);
    fprintf(stdout, "%d\n", _handle);
    
    if (_handle == -1) {
        perror("open");
        //return EXIT_FAILURE;
    }

    
    SYNCCOM_REGISTERS_INIT(regs);

    /* Change the CCR0 and BGR elements to our desired values */
    regs.CCR0 = 0x00112104;
    regs.BGR = 0;

    /* Set the CCR0 and BGR register values */
    ioctl(_handle, SYNCCOM_SET_REGISTERS, &regs);

	// Purge the buffer
    ioctl(_handle, SYNCCOM_PURGE_RX);
}

LN200::~LN200()
{

}

int LN200::GetHandle()
{
    return this->_handle;
}

int16_t* LN200::GetBuffer()
{
    return this->_buffer;
}

void LN200::ReadIMU()
{
    int words = read(_handle, _rawBuffer, sizeof(_rawBuffer));

    for (int i = 0; i < 13; i++)
    {
        _buffer[i] = _rawBuffer[2*i] + (_rawBuffer[2*i+1] << 8);
    }

/*
    dVx[0] = _buffer[0];
    dVy[0] = _buffer[0];
    dVz[0] = _buffer[0];
    dOx[0] = _buffer[0];
    dOy[0] = _buffer[0];
    dOz[0] = _buffer[0];
    */
}

double LN200::GetOmegaZ()
{
    this->ReadIMU();
    return this->_buffer[5]/this->gyroScaleFactor;
}

double LN200::GetAccelZ()
{
    this->ReadIMU();
    return this->_buffer[2]/this->accelScaleFactor;
}
