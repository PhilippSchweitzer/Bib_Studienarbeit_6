#ifndef RAW_COM_H
#define RAW_COM_H

#include "header_com.h"
#include "read_com.h"

#define Vender_ID 4292
#define Product_ID 60000

#define NOT_CONNECTED 0


class Raw_Com : public QObject, public Read_Com
{
            Q_OBJECT

public:
    Raw_Com(QObject *parent = nullptr);
    virtual ~Raw_Com();
    void write(QByteArray);
    bool Com_Available();

private slots:
    void readSerial();

protected:
    bool sync;

private:
    QSerialPort *Com_Port;
    QString Com_Port_Name;
};


#endif // RAW_COM_H
