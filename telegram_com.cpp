#include "telegram_com.h"



Telegram_Com::Telegram_Com(QByteArray raw_Data)
{
    raw_telegram = raw_Data;
    lenght = (int) raw_Data[0];
    identifier = (char) raw_Data[1];

    if(identifier == ID_ASYNC_ANSWER)
        async = true;
    else
        async = false;

    for(int i = 2; i < raw_Data.size() - 1; i++)
        data.push_back(raw_Data[i]);
    crc_correct = check_CRC(raw_Data);
}

Telegram_Com::Telegram_Com(char Identifier, int Data)
{
    QByteArray raw_Data;

    raw_Data.push_back(Identifier);
    raw_Data.push_back(Data);
    raw_Data.push_front(raw_Data.size() + 2);
    raw_Data.push_back(get_CRC(raw_Data, CRC_SALT));

    //qDebug() << "Telegram is:" << raw_Data;

    raw_telegram = raw_Data;
    lenght = (int) raw_Data[0];
    identifier = (char) raw_Data[1];
    for(int i = 2; i < raw_Data.size(); i++)
        data.push_back(raw_Data[i]);
    crc_correct = true;
}

Telegram_Com::Telegram_Com(char Identifier)
{
    QByteArray raw_Data;

    raw_Data.push_back(Identifier);
    raw_Data.push_front(raw_Data.size() + 2);
    raw_Data.push_back(get_CRC(raw_Data, CRC_SALT));

    //qDebug() << "Telegram is:" << raw_Data;

    raw_telegram = raw_Data;
    lenght = (int) raw_Data[0];
    identifier = (char) raw_Data[1];
    for(int i = 2; i < raw_Data.size(); i++)
        data.push_back(raw_Data[i]);
    crc_correct = true;
}

Telegram_Com::~Telegram_Com()
{

}


