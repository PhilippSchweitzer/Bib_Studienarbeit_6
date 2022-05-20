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
        Telegram_Com T = Buffer;
        current_Telegram_lenght = 0;
        callback((uint8_t)T.identifier, T.data);
    }

    return;
}

//TODO Liste aus configuration_com.h verwenden, eventuell auf lambda umstellen (unabhänig von Qt)
void Read_Com::callback(uint8_t Identifier, QByteArray Data)
{

    for(int i = 0; i < function_id.size(); i++)
    {
        if(function_id[i].Identifier == Identifier)
            function_id[i].callback(Data);
    }

    return;
}
