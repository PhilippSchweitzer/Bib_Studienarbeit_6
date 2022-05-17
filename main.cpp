#include <QCoreApplication>
#include <QSerialPort>
#include <raw_com.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Raw_Com ESP32;

    return a.exec();
}
