#ifndef WRITE_COM_H
#define WRITE_COM_H

#include "header_com.h"
#include "raw_com.h"

#define CRC_SALT 0x5A

class Write_Com : public Raw_Com
{

public:
    Write_Com();
    virtual ~Write_Com();

    void send(char Identifier, int Data);
    void send(char Identifier);

    QByteArray send_async(char Identifier, int Data);
    QByteArray send_async(char Identifier);
};

#endif // WRITE_COM_H
