#include <QCoreApplication>
#include <write_com.h>


//each Com Port can only be opened once and needs to be accsessable for all functions that might need it
//so it makes sense to define it globally
Write_Com ESP32;



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Handshake at beginning to make shure the microcontroller uses the same protocoll

    //The microcontroller sends the same telegram back that it received so for this test
    //we need to send the expected answer
    //This is the Answer that the microcontroller will send back if the handshake worked
    if(ESP32.send_async(/*ID_CONNECTION_TEST*/ID_ASYNC_ANSWER, 0x01).toHex().toInt() != 1)
        qDebug() << "Handshake Failure";

    ESP32.send(ID_EXAMPLE3, 'a');
    ESP32.send(ID_EXAMPLE5, 'b');
    ESP32.send(ID_EXAMPLE4, 'c');

    //bevor der erste return Value übernommen wird müssen noch die Antworten von send bearbeitet werden

    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER, 'd');
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER, 'f');
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER, 'g');

    ESP32.send(ID_EXAMPLE3);
    ESP32.send(ID_EXAMPLE5);
    ESP32.send(ID_EXAMPLE4);

    //ID_ASYNC_ANSWER normally only is used for Answers to an send_async because the async answers come in an specific order. So there is no need for IDs.

    //In this test the Microcontroller just sends the Telegram back as it is -> we need to send ID_ASYNC_ANSWER
    //so that the programm can identify the answer. ID_ASYNC_ANSWER will not cause an callback because the Data is the return value of the function.

    ESP32.send_async(ID_ASYNC_ANSWER);  //is used when connection ends to wait until all Telegrams that
                                        //the microcontroller sent before this was called are still received

    return a.exec();
}

