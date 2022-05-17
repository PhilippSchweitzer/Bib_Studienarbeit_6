#include "raw_com.h"


Raw_Com::~Raw_Com()
{
    if(Com_Port->isOpen())
       Com_Port->close();
}



Raw_Com::Raw_Com(QObject *parent)
{
    //Important Debug to Identify ID's!
    /*
        qDebug() << "Num of availabele Ports: " << QSerialPortInfo::availablePorts().length();
        foreach(const QSerialPortInfo &SerialPortInfo, QSerialPortInfo::availablePorts())
        {
            qDebug() << "Portname is: " << SerialPortInfo.portName()
                     << "Vender ID is: " << SerialPortInfo.vendorIdentifier()
                     << "Product ID is: " << SerialPortInfo.productIdentifier();
        }
    */

        Com_Port = new QSerialPort;
        bool Com_Port_Available = false;
        QString Com_Port_Name = "error";

        foreach(const QSerialPortInfo &SerialPortInfo, QSerialPortInfo::availablePorts())
        {
            if(SerialPortInfo.vendorIdentifier() == Vender_ID_ESP32 && SerialPortInfo.productIdentifier() == Product_ID_ESP32)
            {
                Com_Port_Name = SerialPortInfo.portName();
                Com_Port_Available = true;
            }
        }

        if(Com_Port_Available)
        {
            Com_Port->setPortName(Com_Port_Name);
            Com_Port->open(QSerialPort::ReadWrite);
            Com_Port->setBaudRate(QSerialPort::Baud115200);
            Com_Port->setDataBits(QSerialPort::Data8);
            Com_Port->setStopBits(QSerialPort::OneStop);
            Com_Port->setParity(QSerialPort::NoParity);
            Com_Port->setFlowControl(QSerialPort::NoFlowControl);
            QObject::connect(Com_Port, SIGNAL(readyRead()), this, SLOT(readSerial()));
        }
        else
        {
            //qDebug() << "Not connected!";
            //TODO: Error Handling mit Lamda funktion, damit Endnutzer festlegen kann was passieren soll
        }

}

void Raw_Com::readSerial()
{
    QByteArray serialData = Com_Port->read(1);

    //TODO: Übergabe des gelesenen Bytes
    return;
}


void Raw_Com::write(QByteArray out)
{
    Com_Port->write(out);
    return;
}
