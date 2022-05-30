#include <QCoreApplication>
#include <write_com.h>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //each Com Port can only be opened once and needs to be accsessable for all functions that might need it
    //so it also would make sense to define it globally
    Write_Com ESP32;

    //Handshake at beginning to make shure the microcontroller uses the same protocoll

    //The microcontroller sends the same telegram back that it received so for this test
    //we need to send the expected answer
    //This is the Answer that the microcontroller will send back if the handshake worked
    if(ESP32.send_async(/*ID_HANDSHAKE*/ID_ASYNC_ANSWER, VERSION_TEST).toHex().toInt() != 1)
       qDebug() << "Handshake Failure";
    else
       qDebug() << "Handshake Successfull";

    ESP32.send(ID_EXAMPLE3, 'a');
    ESP32.send(ID_EXAMPLE5, 'b');
    ESP32.send(ID_EXAMPLE4, 'c');

    //At this point you will probably notice that this Computer has not received the answers to these send functions.
    //send_async will also detect that the first three Telegrams it receives are not meant to be an answer.
    //send_async will handle them as normal Telegrams and hand them to read_com. read_com will then get their data and call
    //the callback function.

    //ID_ASYNC_ANSWER must only be used for Answers to an send_async because the async answers come in an specific order.
    //So there is no need for IDs. If normal Telegrams are send with ID_ASYNC_ANSWER this order is inconsistent.

    //In this test the Microcontroller just sends the Telegram back as it is -> we need to send ID_ASYNC_ANSWER
    //so that the programm can identify the answer.
    //Be aware that answering an send_async with a send_async could end in an loop. Usually it should be answered with send.
    //ID_ASYNC_ANSWER will not cause an callback because the Data is the return value of the function.
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER, 'd');
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER, 'f');
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER, 'g');

    //This is the same test as above. But in this case without any return value. In practice ths makes no sense.
    //It is only used to test the send_async function.
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER);
    qDebug() << "Return Value is:" << ESP32.send_async(ID_ASYNC_ANSWER);


    ESP32.send(ID_EXAMPLE3);
    ESP32.send(ID_EXAMPLE5);
    ESP32.send(ID_EXAMPLE4);

    //send_async(ID_HANDSHAKE); is used when connection ends to wait until all telegrams that
    //the microcontroller sent before this was called are still received.
    //This is not needed if the last send is an async send because these will do that anyway.
    //The ID_ASYNC_ANSWER is used. The reason is the same as in the first Handshake procedure.
    //In this case the Answer does not need to contain any data.
    //ESP32.send_async(ID_ASYNC_ANSWER/*ID_HANDSHAKE*/);

    return a.exec();
}

