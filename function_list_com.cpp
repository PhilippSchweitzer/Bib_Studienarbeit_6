#include "main.cpp"
#include "write_com.h"


//TODO: Beispiele entfernen

void error_connection_loss(QByteArray Data)
{

    if(Data.toHex().toInt() == 0x00)
        qDebug() << "ERROR not connected";
    if(Data.toHex().toInt() == 0x01)
        qDebug() << "ERROR Handshake failed";
    return;
}

void do_handshake(QByteArray Data)
{
       if(Data.toHex().toInt() == 0x01)
           ESP32.send(ID_ASYNC_ANSWER, 0x01);

    return;
}

void example5(QByteArray Data)
{
    qDebug() << "example5 is called with Data: " << Data;
    return;
}

void example3(QByteArray Data)
{
    qDebug() << "example3 is called with Data: " << Data;
    return;
}

void example4(QByteArray Data)
{
    qDebug() << "example4 is called with Data: " << Data;
    return;
}

std::vector<Function_Id_Com> function_id_list =
{
    {ID_CONNECTION_ERROR, error_connection_loss},       //function for error handling; can receive different error codes

    {ID_ASYNC_ANSWER, nullptr},                         //ID_ASYNC_ANSWER must only be used in Answers to an send_async
                                                        //used to identify answer to an send_async (therefor no callback needed),
                                                        //these will come in an specific order so there is no need for
                                                        //a specific ID for each answer
    {ID_CONNECTION_TEST, do_handshake},

    {ID_EXAMPLE5, example5},                            //user implemented functions, can eighter directly do something or
    {ID_EXAMPLE3, example3},                            //convert the ByteArray to the needed datatype and then call another function
    {ID_EXAMPLE4, example4}
};
