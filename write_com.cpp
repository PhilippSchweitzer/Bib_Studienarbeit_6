#include "write_com.h"

//TODO: int zu ByteArray ändern

Write_Com::Write_Com()
{

}

Write_Com::~Write_Com()
{

}

void Write_Com::send(char Identifier, int Data)
{
    write(Telegram_Com(Identifier, Data).raw_telegram);
    return;
}

void Write_Com::send(char Identifier)
{
    write(Telegram_Com(Identifier).raw_telegram);
    return;
}

QByteArray Write_Com::send_async(char Identifier, int Data)
{
    write(Telegram_Com(Identifier, Data).raw_telegram);
    sync = false;
    QByteArray answer = readSerial_async();
    sync = true;
    return answer;
}

QByteArray Write_Com::send_async(char Identifier)
{
    write(Telegram_Com(Identifier).raw_telegram);
    sync = false;
    QByteArray answer = readSerial_async();
    sync = true;
    return answer;
}


