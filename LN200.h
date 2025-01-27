#include <cstdint>


class LN200
{
    public:
        LN200();
        int16_t* GetBuffer();
        void ClearBuffer();
        void GetEulerAngles(double phi, double theta, double psi);
        void GetQuaternion(double eta, double* epsilon);
        void GetOmega(double* omega);
        double GetOmegaZ();

        ~LN200();

    private:
        // Scale Factors for LN200 at 400 Hz
        double gyroScaleFactor = 524228.0;
        double accelScaleFactor = 16384.0;
        uint8_t _rawBuffer[26];
        int16_t _buffer[13];
        double _phi;
        double _theta;
        double _psi;
        double _eta;
        double _epsilon[3];
        double _omega[3];

        int handle;

        void ReadIMU();

};
