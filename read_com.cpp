#include "read_com.h"
#include "function_list_com.cpp"

Read_Com::Read_Com()
{

}


Read_Com::~Read_Com()
{

}


void Read_Com::get_Data(QByteArray in)
{

    Buffer.push_back(in);

    qDebug() << "Buffer is:" << Buffer;

    if(Buffer.size() == 1)
        current_Telegram_lenght = in.toHex().toInt();
    qDebug() << "Buffer size:" << Buffer.size();
    qDebug() << "Complete Telegram will be:" << current_Telegram_lenght;

    if(Buffer.size() == current_Telegram_lenght)
    {
        Telegram_Com T = Buffer;
        current_Telegram_lenght = 0;
        Buffer.clear();
        callback((uint8_t)T.identifier, T.data);
    }

    return;
}

void Read_Com::callback(uint8_t Identifier, QByteArray Data)
{

    for(int i = 0; i < function_id_list.size(); i++)
    {
        if(function_id_list[i].Identifier == Identifier)
            function_id_list[i].callback(Data);
    }

    return;
}
