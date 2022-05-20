#ifndef CALLBACK_COM_H
#define CALLBACK_COM_H

#include <QByteArray>
#include <QDebug>
#include "function_id_com.h"


void example1(QByteArray Data)
{
    qDebug() << "example 1 is called, Data is: " << Data;
    return;
}

void example2(QByteArray Data)
{
    qDebug() << "example 2 is called, Data is: " << Data;
    return;
}

void example3(QByteArray Data)
{
    qDebug() << "example 3 is called, Data is: " << Data;
    return;
}


std::vector<Function_Id_Com> function_id_list =
{
    {0x01, example1},               //TODO: Beispiele entfernen
    {0x02, example2},
    {0x03, example3}
};
#endif // CALLBACK_COM_H
