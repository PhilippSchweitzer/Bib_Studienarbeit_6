#ifndef HEADER_COM_H
#define HEADER_COM_H

#pragma once

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
//TODO: QByteArray durch eigene Alternative ersetzen

#define Vender_ID 4292
#define Product_ID 60000

#define VERSION_TEST 0x01               //This version number will be send back as an answer to the Handshake
                                        //If you want to make shure that the microcontroller and the PC use the same IDs
                                        //you should add your own Version IDs and test for them in the Handshake procedure

#define SerialTimeout 2000              //2000ms

#define NOT_CONNECTED 0x00              //Microcntroller is not connected
#define HANDSHAKE_FAILURE 0x01          //Handshake Failed
#define ID_CONNECTION_ERROR 0x00        //ID for error handling callback
#define ID_ASYNC_ANSWER 0x01            //Identifys Answers to send_async and must only be used for that purpose
#define ID_HANDSHAKE 0x02               //ID for Handshake

//User defined IDs:

#define ID_EXAMPLE3 0x03
#define ID_EXAMPLE4 0x04
#define ID_EXAMPLE5 0x05

#endif // HEADER_COM_H
