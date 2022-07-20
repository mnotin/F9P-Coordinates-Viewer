#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <QFile>
#include <QTextStream>

#include "MyWindow.h"

MyWindow::MyWindow()
{
    //setFixedSize(830, 200);
    //resize(830, 200);
    setWindowTitle("GPS");

    m_latitude = new QLabel("0.0");
    m_longitude = new QLabel("0.0");
    m_altitude = new QLabel("0.0");
    m_time = new QLabel("0");
    m_status = new QLabel("?");

    QVBoxLayout *vboxLayout = new QVBoxLayout;

    m_pushButton = new QPushButton("Pause");
    m_readGpsData = true;

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Latitude : ", m_latitude);
    formLayout->addRow("Longitude: ", m_longitude);
    formLayout->addRow("Altitude: ", m_altitude);
    formLayout->addRow("Time: ", m_time);
    formLayout->addRow("Has fix: ", m_status);

    vboxLayout->addLayout(formLayout);
    vboxLayout->addWidget(m_pushButton);

    setLayout(vboxLayout);


    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MyWindow::UpdateData);
    m_timer->start(1000);

    connect(m_pushButton, &QPushButton::clicked, this, &MyWindow::SwitchReadGpsData);
}

void MyWindow::UpdateData() {
    std::string latitude;
    std::string longitude;
    std::string altitude;
    std::string time;
    std::string hasFix;

    if (m_readGpsData) {
        QFile file("/home/user/Documents/HAL-Drotek-F9P-main/HAL-Drotek-F9P-main/demofile2.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);

        latitude = in.readLine().toStdString();
        longitude = in.readLine().toStdString();
        altitude = in.readLine().toStdString();
        time = in.readLine().toStdString();
        hasFix = in.readLine().toStdString();;
        file.close();


        m_longitude->setText(QString::fromStdString(latitude));
        m_latitude->setText(QString::fromStdString(longitude));
        m_altitude->setText(QString::fromStdString(altitude));
        m_time->setText(QString::fromStdString(time));
        m_status->setText(QString::fromStdString(hasFix));
    }
}

void MyWindow::SwitchReadGpsData() {
    m_readGpsData = !m_readGpsData;

    if (m_readGpsData) {
        m_pushButton->setText("Pause");
    } else {
        m_pushButton->setText("Resume");
    }
}
