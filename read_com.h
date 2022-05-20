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
    void callback(uint8_t identifier, QByteArray Data);

signals:
//TODO: implementieren sonst linkerfehler, dann wieder einkommentieren
//    void callback1(QByteArray); // ID: 0x01
//    void callback2(QByteArray); // ID: 0x02

private:
    QByteArray Buffer;
    int current_Telegram_lenght;
};


#endif // READ_COM_H
