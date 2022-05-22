#ifndef RAW_COM_H
#define RAW_COM_H

#include "header_com.h"
#include "read_com.h"

//TODO: move defines and function list to one file (so that the user can configure all settings in one file)


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
    QByteArray readSerial_async();

private:
    QSerialPort *Com_Port;
    QString Com_Port_Name;
};


#endif // RAW_COM_H
