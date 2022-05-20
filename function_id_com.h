#ifndef FUNCTION_ID_COM_H
#define FUNCTION_ID_COM_H

#include "header_com.h"

class Function_Id_Com
{

public:
    Function_Id_Com(uint8_t, void (*foo)(QByteArray));
    ~Function_Id_Com();

    uint8_t Identifier;
    void (*callback)(QByteArray);
};



#endif // FUNCTION_ID_COM_H
