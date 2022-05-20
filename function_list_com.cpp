#include "function_id_com.h"

void example1(QByteArray)
{
    qDebug() << "example1 is called";
    return;
}

void example2(QByteArray)
{
    qDebug() << "example2 is called";
    return;
}

void example3(QByteArray)
{
    qDebug() << "example3 is called";
    return;
}

std::vector<Function_Id_Com> function_id_list =
{
    {0x01, example1},
    {0x02, example2},
    {0x03, example3}
};

