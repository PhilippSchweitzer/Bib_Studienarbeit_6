#ifndef FUNCTION_ID_COM_H
#define FUNCTION_ID_COM_H

#include "header_com.h"
/*
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
*/
class Function_Id_Com
{

public:
    Function_Id_Com(uint8_t, void (*foo)(QByteArray));
    ~Function_Id_Com();

    uint8_t Identifier;
    void (*callback)(QByteArray);
};


/*
std::vector<Function_Id_Com> function_id =
{
    {0x01, example1},
    {0x02, example2},
    {0x03, example3}
};
*/

#endif // FUNCTION_ID_COM_H
