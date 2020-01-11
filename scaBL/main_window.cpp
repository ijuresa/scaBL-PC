#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Setup UART (As it is default)
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_search_clicked() {
    this->filePath = QFileDialog::getOpenFileName(this,
                                                  tr("Search .hex"),
                                                  "../", tr("Hex files (*.hex)"));
    QFile file(this->filePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream inData(&file);

        while(!inData.atEnd()) {
            this->fileData += inData.readLine().split(";");
            qDebug() << this->fileData.last();
        }
    } else {
        qDebug() << "Failed to open!";
    }

    file.close();
}

void MainWindow::on_radioButton_uart_clicked() {
    qDebug() << "Entered to UART";
    this->communicationType = UART;
}

void MainWindow::on_pushButton_download_clicked() {
    switch(this->communicationType) {
        case UART:
            break;

        case CAN:
            break;

        case USB:
            break;

        default:
            break;
    }
}

void MainWindow::on_comboBox_UART_port_activated(const QString &arg1) {

}

void MainWindow::on_tabWidget_comSelector_tabBarClicked(int index) {
    qDebug() << "Clicked " << index;
    this->communicationType = index;

    // Fill the data
    this->serialPort.findPorts();
}
