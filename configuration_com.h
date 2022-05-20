#ifndef CONFIGURATION_COM_H
#define CONFIGURATION_COM_H

#include "function_id_list_com.h"
#include "function_id_list_com.cpp"     //für Beispiele (alle Funktionen, die hier gelistet sind müssen eingebunden werden)
#include <vector>

#define Vender_ID 4292
#define Product_ID 60000

std::vector<id_list> function_id =
{
    {0x01, example1},               //TODO: Beispiele entfernen
    {0x02, example2},
    {0x03, example3}
};

#endif // CONFIGURATION_COM_H
