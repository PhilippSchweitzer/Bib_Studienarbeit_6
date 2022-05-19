#ifndef READ_COM_H
#define READ_COM_H

#include "header_com.h"
#include "crc_com.h"

class Read_Com : public CRC_Com
{

public:
    Read_Com();
    virtual ~Read_Com();

protected:
    void read(QByteArray);
    void callback();    //TODO implementieren; Ruft die Funktion mit den Daten auf, erwartet Identifier und Daten

private:
    QByteArray Buffer;
    int current_Telegram_lenght;

};

/*
Telegram:
Byte    Function
0       Wie viele Bytes ist dieses Telegram lang
1       Identifier (Für welche Funktion sind die Daten bestimmt)
2 - X   Daten
X + 1   CRC
*/

#endif // READ_COM_H
