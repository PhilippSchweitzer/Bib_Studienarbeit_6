#ifndef WRITE_COM_H
#define WRITE_COM_H

#include "raw_com.h"
#include <bitset>

#define CRC_SALT 0x5A

class Write_Com : public Raw_Com
{

public:
    Write_Com();
    ~Write_Com();

    void send(char Identifier, int Data);
    void send(char Identifier);

    void send_async(char Identifier, int Data);
    void send_async(char Identifier);

private:
    QByteArray make_Telegram(char Identifier, int Data);
    QByteArray make_Telegram(char Identifier);

    char getCRC(QByteArray);
    uint8_t CRC8(uint8_t remainder, uint8_t nextByte);
};

#endif // WRITE_COM_H
