#ifndef HEADER_COM_H
#define HEADER_COM_H

#pragma once

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

#define Vender_ID 4292
#define Product_ID 60000

#define SerialTimeout 2000              //2000ms

#define NOT_CONNECTED 0x00              //Microcntroller is not connected
#define HANDSHAKE_FAILURE 0x01          //Handshake Failed
#define ID_CONNECTION_ERROR 0x00        //ID for error handling callback
#define ID_ASYNC_ANSWER 0x01            //Identifys Answers to send_async and must only be used for that purpose
#define ID_CONNECTION_TEST 0x02         //ID for Handshake

//User defined IDs:

#define ID_EXAMPLE3 0x03
#define ID_EXAMPLE4 0x04
#define ID_EXAMPLE5 0x05

#endif // HEADER_COM_H
