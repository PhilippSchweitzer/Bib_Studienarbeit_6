#ifndef CRC_COM_H
#define CRC_COM_H

#include "header_com.h"

class CRC_Com
{

public:
    CRC_Com();
    virtual ~CRC_Com();

protected:
    char get_CRC(QByteArray);

private:
    uint8_t CRC8(uint8_t, uint8_t);

};

#endif // CRC_COM_H
