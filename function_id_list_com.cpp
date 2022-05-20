#include "function_id_list_com.h"

id_list::id_list(uint8_t id, void (*foo)(QByteArray))
{
     Identifier = id;
     callback = foo;
}

id_list::~id_list()
{

}

//TODO Beispiele entfernen
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
