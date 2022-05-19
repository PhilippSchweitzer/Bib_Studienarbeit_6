#include "read_com.h"

Read_Com::Read_Com()
{

}


Read_Com::~Read_Com()
{

}


void Read_Com::read(QByteArray in)
{
    Buffer.push_back(in);

    if(Buffer.size() == 1)
        current_Telegram_lenght = in.toInt();

    else if(Buffer.size() == current_Telegram_lenght)
    {
        //make Telgram out of Buffer
        current_Telegram_lenght = 0;
        callback(/*TODO*/);
    }



    return;
}

void Read_Com::callback()
{

}
