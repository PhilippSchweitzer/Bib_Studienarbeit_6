#ifndef READ_COM_H
#define READ_COM_H

#include "header_com.h"
#include "crc_com.h"

class Read_Com : public CRC_Com
{

public:
    Read_Com();
    virtual ~Read_Com();

protected:
    void get_Input();

private:
    QByteArray Buffer;
    int Byte_Counter;

};

#endif // READ_COM_H
