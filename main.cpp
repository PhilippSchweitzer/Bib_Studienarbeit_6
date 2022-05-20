#include <QCoreApplication>
#include <write_com.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Write_Com ESP32;

    ESP32.send(0x03, 'o');

    return a.exec();
}

