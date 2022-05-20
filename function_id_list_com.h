#ifndef FUNCTION_ID_LIST_COM_H
#define FUNCTION_ID_LIST_COM_H

#include <header_com.h>

class id_list
{

public:
    id_list(uint8_t, void (*foo)(QByteArray));
    ~id_list();

    uint8_t Identifier;
    void (*callback)(QByteArray);
};

#endif // FUNCTION_ID_LIST_COM_H
