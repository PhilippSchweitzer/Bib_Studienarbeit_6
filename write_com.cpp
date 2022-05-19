#include "write_com.h"

Write_Com::Write_Com()
{

}

Write_Com::~Write_Com()
{

}


void Write_Com::send(char Identifier, int Data)
{
    write(make_Telegram(Identifier, Data));
    return;
}


void Write_Com::send(char Identifier)
{
    write(make_Telegram(Identifier));
    return;
}

void Write_Com::send_async(char Identifier, int Data)
{
    write(make_Telegram(Identifier, Data));
    sync = false;
    //TODO blockieren bis Antwort ankommt, Antwort hier lesen und als QByteArray zurück geben
    sync = true;
    return;
}

void Write_Com::send_async(char Identifier)
{
    write(make_Telegram(Identifier));
    sync = false;
    //TODO blockieren bis Antwort ankommt, Antwort hier lesen und als QByteArray zurück geben
    sync = true;
    return;
}

QByteArray Write_Com::make_Telegram(char Identifier, int Data)
{
    QByteArray out;

    out.push_back(Identifier);
    out.push_back(Data);
    out.push_back(getCRC(out));

    qDebug() << "Telegram is:" << out;

    return out;
}

QByteArray Write_Com::make_Telegram(char Identifier)
{
    QByteArray out;

    out.push_back(Identifier);
    out.push_back(getCRC(out));

    qDebug() << "Telegram is:" << out;

    return out;
}

//TODO eigene Klasse für CRC damit es für Senden und Empfangen genutzt werden kann.
char Write_Com::getCRC(QByteArray raw_Data)
{
    uint8_t remainder = 0;
    for (int i = 0; i < raw_Data.length(); i++)
        remainder = CRC8(remainder, raw_Data[i]);

    qDebug() << "CRC is:" << remainder << " / " << (char) remainder;

    return (char) remainder;
}

/*
  This was found in
  https://barrgroup.com/Embedded-Systems/How-To/CRC-Calculation-C-Code

  This function is called from both: the sender and the receiver of a message.

  The sender initializes the remainder with 0 and then calls CRC8 for each
  byte of the message to send. the last result of the remainder is added to
  the message as the CRC value.

  The receiver initializes the remainder with CRC_SALT = 0x5A and then calls CRC8 for each
  byte of the message received including the CRC value. The last result of
  the remainder must be 0 for a correct message.
*/

uint8_t Write_Com::CRC8(uint8_t remainder, uint8_t nextByte)
{
#define GENERATOR 0x07
    remainder ^= nextByte;
    for (uint8_t bit = 7; bit; --bit)
    {
        if (remainder & 0x80)
            remainder = (remainder << 1) ^ GENERATOR;
        else
            remainder = (remainder << 1);
    }
    return remainder;
}
