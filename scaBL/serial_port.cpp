#include "serial_port.h"
#include <QDebug>
#include <QtSerialPort>

SerialPort::SerialPort() {

}

SerialPort::~SerialPort() {

}

void SerialPort::findPorts() {
     QList<QSerialPortInfo> qSerialPortInfo = QSerialPortInfo::availablePorts();

     for(QSerialPortInfo &info : qSerialPortInfo) {
         qDebug() << info.portName();
         qDebug() << info.description();
         qDebug() << info.manufacturer();
         qDebug() << info.serialNumber();
         qDebug() << info.vendorIdentifier();
         qDebug() << info.productIdentifier();
         qDebug() << "";
     }
}
