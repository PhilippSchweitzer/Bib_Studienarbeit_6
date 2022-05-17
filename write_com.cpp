#include "write_com.h"

Write_Com::Write_Com()
{

}

Write_Com::~Write_Com()
{

}


void Write_Com::send(char Identifier, int Data)
{
    QByteArray out = make_Telegram(Identifier, Data);
    write(out);

    return;
}


void Write_Com::send(char Identifier)
{
    QByteArray out = make_Telegram(Identifier);
    write(out);

    return;
}

void Write_Com::send_async(char Identifier, int Data)
{
    //TODO
}

void Write_Com::send_async(char Identifier)
{
    //TODO
}

QByteArray Write_Com::make_Telegram(char Identifier, int Data)
{
    QByteArray out;
    out.setRawData(&Identifier, Data);

    //TODO: CRC

    return out;
}

QByteArray Write_Com::make_Telegram(char Identifier)
{
    //TODO: CRC
    return QByteArray(1, Identifier);
}


char Write_Com::getCRC(QByteArray raw_Data)
{
    std::vector<uint8_t> Telegram;

    uint8_t remainder = 0;
    for (int i = 0; i < raw_Data.length(); i++)
        remainder = CRC8(remainder, Telegram[i]);

    return remainder;
}

/*
  This was found in
  https://barrgroup.com/Embedded-Systems/How-To/CRC-Calculation-C-Code

  This function is called from both: the sender and the receiver of a message.

  The sender initializes the remainder with 0 and then calls CRC8 for each
  byte of the message to send. the last result of the remainder is added to
  the message as the CRC value.

  The receiver initializes the remainder with 0 and then calls CRC8 for each
  byte of the message received including the CRC value. The last result of
  the remainder must be 0 for a correct message.
*/

uint8_t Write_Com::CRC8(uint8_t remainder, uint8_t nextByte)
{
#define GENERATOR 0x07 // CRC8 (ITU-T) generator polynomial 0x107
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
