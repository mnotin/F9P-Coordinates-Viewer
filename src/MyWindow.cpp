#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QDate>

#include "../headers/MyWindow.h"

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

    m_gnss = new PyHALDrotekF9P();

    if (!m_gnss->init("/dev/ttyACM0")) {
        std::cout << "No GPS Found !" << std::endl;
        std::cout << "Please make sure that the application is running as root and that the GPU is properly plugged." << std::endl;
    }

    std::cout << m_gnss->get_gnss_name() << std::endl;
}

void MyWindow::UpdateData() {
    double latitude;
    double longitude;
    double altitude;
    double hasFix;

    if (m_readGpsData) {
        double *res = new double[6];
        m_gnss->get_gnss_info(res);
        latitude = res[0];
        longitude = res[1];
        altitude = res[2];
        hasFix = m_gnss->has_fix();

        m_longitude->setText(QString::number(latitude));
        m_latitude->setText(QString::number(longitude));
        m_altitude->setText(QString::number(altitude));
        m_time->setText(QDate::currentDate().toString("yyyy.MM.dd") + " " + QDateTime::currentDateTime().toString("hh:mm:ss"));
        m_status->setText(hasFix == 1 ? "True" : "False");

        delete [ ] res;
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
