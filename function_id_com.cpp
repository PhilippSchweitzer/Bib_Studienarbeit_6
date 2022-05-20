#include "function_id_com.h"

Function_Id_Com::Function_Id_Com(uint8_t id, void (*foo)(QByteArray))
{
     Identifier = id;
     callback = foo;
}

Function_Id_Com::~Function_Id_Com()
{

}
