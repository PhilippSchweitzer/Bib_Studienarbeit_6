#include "function_id_com.h"
//TODO: Beispiele entfernen

void error_connection_loss(QByteArray Data)
{
    qDebug() << "ERROR not connected";
    return;
}

void example1(QByteArray Data)
{
    qDebug() << "example1 is called with Data: " << Data;
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

std::vector<Function_Id_Com> function_id_list =
{
    {0x00, error_connection_loss},
    {0x01, example1},
    {0x02, example2},
    {0x03, example3}
};

