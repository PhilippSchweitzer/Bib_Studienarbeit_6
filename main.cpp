#include <QCoreApplication>
#include <write_com.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Write_Com ESP32;

    ESP32.send(0x03, 'a');
    ESP32.send(0x02, 'b');
    ESP32.send(0x01, 'c');



    qDebug() << "Return Value is:" << ESP32.send_async(0x03, 'd');
    qDebug() << "Return Value is:" << ESP32.send_async(0x02, 'f');
    qDebug() << "Return Value is:" << ESP32.send_async(0x01, 'g');

    return a.exec();
}

