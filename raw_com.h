#ifndef RAW_COM_H
#define RAW_COM_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


#define Vender_ID_ESP32 4292
#define Product_ID_ESP32 60000

class Raw_Com : public QObject
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
