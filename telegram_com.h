#ifndef TELEGRAM_COM_H
#define TELEGRAM_COM_H

#include "header_com.h"
#include "crc_com.h"

/****************************************************************

    Telegram:
    Byte    Function
    0       Wie viele Bytes ist dieses Telegram lang
    1       Identifier (Für welche Funktion sind die Daten bestimmt)
    2 - X   Daten
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
    bool check_CRC(QByteArray);

};

#endif // TELEGRAM_COM_H
