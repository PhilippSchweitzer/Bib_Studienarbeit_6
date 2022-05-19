#ifndef RAW_COM_H
#define RAW_COM_H

#include "header_com.h"
#include "read_com.h"

#define Vender_ID_ESP32 4292
#define Product_ID_ESP32 60000

//TODO Readcom+CRCcom einkommentieren und get_CRC einkommentieren
//TODO Linker Probleme fixen
class Raw_Com : public QObject, public Read_Com
{
            Q_OBJECT

public:
    Raw_Com(QObject *parent = nullptr);
    virtual ~Raw_Com();
    void write(QByteArray);

private slots:
    void readSerial();

protected:
    bool sync;

private:
    QSerialPort *Com_Port;
};


#endif // RAW_COM_H
