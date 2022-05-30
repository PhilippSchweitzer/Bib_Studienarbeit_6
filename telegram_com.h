#ifndef TELEGRAM_COM_H
#define TELEGRAM_COM_H

#include "header_com.h"
#include "crc_com.h"

/****************************************************************

    Telegram:
    Byte    Function
    0       How many Bytes does this Telegram contain
    1       Identifier (wich function should be called with this data)
    2 - X   Data
    X + 1   CRC

****************************************************************/

class Telegram_Com : public CRC_Com
{

public:
    Telegram_Com(QByteArray raw_telegram);
    Telegram_Com(char Identifier, int Data);
    Telegram_Com(char Identifier);
    virtual ~Telegram_Com();

    QByteArray raw_telegram;
    int lenght;
    char identifier;
    QByteArray data;
    bool crc_correct;
    bool async;
};

#endif // TELEGRAM_COM_H
