#include <QCoreApplication>
#include <QSerialPort>
#include <write_com.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Write_Com ESP32;

    ESP32.send('w', 109);

    return a.exec();
}
