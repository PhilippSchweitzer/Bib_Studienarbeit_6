#include "write_com.h"


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

void Write_Com::send_async(char Identifier, int Data)
{
    write(Telegram_Com(Identifier, Data).raw_telegram);
    sync = false;
    //TODO blockieren bis Antwort ankommt, Antwort hier lesen und als QByteArray zurück geben
    //TODO testen
    sync = true;
    return;
}

void Write_Com::send_async(char Identifier)
{
    write(Telegram_Com(Identifier).raw_telegram);
    sync = false;
    //TODO blockieren bis Antwort ankommt, Antwort hier lesen und als QByteArray zurück geben
    //TODO testen
    sync = true;
    return;
}


