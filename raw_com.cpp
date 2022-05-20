#include "raw_com.h"


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
        sync = true;

        Com_Port = new QSerialPort;
        bool Com_Port_Available = false;
        QString Com_Port_Name = "error";

        foreach(const QSerialPortInfo &SerialPortInfo, QSerialPortInfo::availablePorts())
        {
            if(SerialPortInfo.vendorIdentifier() == Vender_ID && SerialPortInfo.productIdentifier() == Product_ID)
            {
                Com_Port_Name = SerialPortInfo.portName();
                Com_Port_Available = true;
            }
        }

        if(Com_Port_Available)
        {
            Com_Port->setPortName(Com_Port_Name);
            Com_Port->open(QSerialPort::ReadWrite);
            Com_Port->setBaudRate(QSerialPort::Baud9600);
            Com_Port->setDataBits(QSerialPort::Data8);
            Com_Port->setStopBits(QSerialPort::OneStop);
            Com_Port->setParity(QSerialPort::NoParity);
            Com_Port->setFlowControl(QSerialPort::NoFlowControl);
            QObject::connect(Com_Port, SIGNAL(readyRead()), this, SLOT(readSerial()));
        }
        else
        {
            callback(0x00, NOT_CONNECTED);
        }

}

Raw_Com::~Raw_Com()
{
    if(Com_Port->isOpen())
       Com_Port->close();
}

void Raw_Com::write(QByteArray out)
{
    Com_Port->write(out);
    qDebug() << "Writing: " << out;
    return;
}

bool Raw_Com::Com_Available()
{
    if(QSerialPortInfo(*Com_Port).vendorIdentifier() == Vender_ID
       && QSerialPortInfo(*Com_Port).productIdentifier() == Product_ID)
    {
        return true;
    }

    qDebug() << "Disconnected!";
    return false;
}

void Raw_Com::readSerial()
{

    if(sync == true)
    {
        QByteArray serialData = Com_Port->read(1);
        qDebug() << "Reading: " << serialData;
        get_Data(serialData);
    }

    return;
}

QByteArray Raw_Com::readSerial_async()
{
    QByteArray answer;

    Com_Port->waitForReadyRead(2000);
    QByteArray serialData = Com_Port->read(1);
    answer.push_back(serialData);
    //qDebug() << "Lengt of Answer is: " << serialData;
    //qDebug() << "Answer is: " << answer;

    for(int i = 0; i < serialData.toHex().toInt() - 1; i++)
    {
        Com_Port->waitForReadyRead(2000);
        answer.push_back(Com_Port->read(1));
        //qDebug() << "Answer is: " << answer;
    }

    Telegram_Com T (answer);
    //qDebug() << "Final Answer is: " << T.data;

    if(T.async)
        return T.data;
    else
    {
        callback((uint8_t)T.identifier, T.data);
        return readSerial_async();
    }
}
















