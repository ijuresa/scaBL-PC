#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "serial_port.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum CommunicationType {
    UART = 0,
    CAN,
    USB,
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialPort serialPort;
    QString filePath; //!< Path to the .hex file
    QStringList fileData; //!< Data from .hex file
    int communicationType;

private slots:
    void on_pushButton_search_clicked();
    void on_radioButton_uart_clicked();
    void on_pushButton_download_clicked();
    void on_comboBox_UART_port_activated(const QString &arg1);
    void on_tabWidget_comSelector_tabBarClicked(int index);
};

#endif // MAINWINDOW_H
