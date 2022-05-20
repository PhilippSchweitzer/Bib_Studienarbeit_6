#include "function_id_com.h"
//TODO: Beispiele entfernen

void error_connection_loss(QByteArray Data)
{
    qDebug() << "ERROR not connected";
    return;
}

void example2(QByteArray Data)
{
    qDebug() << "example2 is called with Data: " << Data;
    return;
}

void example3(QByteArray Data)
{
    qDebug() << "example3 is called with Data: " << Data;
    return;
}

void example4(QByteArray Data)
{
    qDebug() << "example4 is called with Data: " << Data;
    return;
}

void async_id(QByteArray Data)
{
    return;
}

std::vector<Function_Id_Com> function_id_list =
{
    {0x00, error_connection_loss},  //function for error handling; can receive different error codes
    {0x01, async_id},               //no callback
    {0x02, example2},
    {0x03, example3},
    {0x04, example4}
};
