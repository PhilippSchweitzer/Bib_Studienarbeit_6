#ifndef READ_COM_H
#define READ_COM_H

#include "header_com.h"
#include "telegram_com.h"

class Read_Com
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


#endif // READ_COM_H
