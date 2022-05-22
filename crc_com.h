#ifndef CRC_COM_H
#define CRC_COM_H

#include "header_com.h"

#define CRC_SALT 0x5A

class CRC_Com
{

public:
    CRC_Com();
    virtual ~CRC_Com();

    char get_CRC(QByteArray, uint8_t);

private:
    uint8_t CRC8(uint8_t, uint8_t);

};

#endif // CRC_COM_H
