#include "crc_com.h"

CRC_Com::CRC_Com()
{

}

CRC_Com::~CRC_Com()
{

}

char CRC_Com::get_CRC(QByteArray raw_Data, uint8_t remainder)
{

    for (int i = 0; i < raw_Data.length(); i++)
        remainder = CRC8(remainder, (uint8_t)raw_Data[i]);

    //qDebug() << "CRC is:" << remainder << " / " << (char) remainder;

    return (char) remainder;
}

/*
  This was found in
  https://barrgroup.com/Embedded-Systems/How-To/CRC-Calculation-C-Code

  This function is called from both: the sender and the receiver of a message.

  The sender initializes the remainder with CRC_SALT and then calls CRC8 for each
  byte of the message to send. the last result of the remainder is added to
  the message as the CRC value.

  The receiver initializes the remainder with CRC_SALT and then calls CRC8 for each
  byte of the message received including the CRC value. The last result of
  the remainder must be 0 for a correct message.
*/

uint8_t CRC_Com::CRC8(uint8_t remainder, uint8_t nextByte)
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

bool CRC_Com::check_CRC(QByteArray raw_Data)
{
    //qDebug() << "CRC is:" << (int)get_CRC(raw_Data, CRC_SALT);

    if(get_CRC(raw_Data, CRC_SALT) == 0)
        return true;
    else
        return false;
}
