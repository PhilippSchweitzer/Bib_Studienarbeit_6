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
    //TODO testen
    sync = true;
    return;
}

void Write_Com::send_async(char Identifier)
{
    write(make_Telegram(Identifier));
    sync = false;
    //TODO blockieren bis Antwort ankommt, Antwort hier lesen und als QByteArray zurück geben
    //TODO testen
    sync = true;
    return;
}

QByteArray Write_Com::make_Telegram(char Identifier, int Data)
{
    QByteArray out;

    out.push_back(Identifier);
    out.push_back(Data);
    out.push_front(out.size() + 1);
    out.push_back(get_CRC(out));

    qDebug() << "Telegram is:" << out;

    return out;
}

QByteArray Write_Com::make_Telegram(char Identifier)
{
    QByteArray out;

    out.push_back(Identifier);
    out.push_back(get_CRC(out));

    qDebug() << "Telegram is:" << out;

    return out;
}

