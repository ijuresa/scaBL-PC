#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>

class SerialPort : public QObject {
    Q_OBJECT
public:
    SerialPort();
    ~SerialPort();
    void findPorts();

private:

};

#endif // SERIALPORT_H
