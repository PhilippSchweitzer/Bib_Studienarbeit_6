#ifndef READ_COM_H
#define READ_COM_H

#include "header_com.h"
#include "telegram_com.h"
#include "function_id_com.h"

class Read_Com
{

public:
    Read_Com();
    virtual ~Read_Com();

protected:
    void get_Data(QByteArray);
    void callback(uint8_t identifier, QByteArray Data);

private:
    QByteArray Buffer;
    int current_Telegram_lenght;
};


#endif // READ_COM_H
