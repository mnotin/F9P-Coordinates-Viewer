#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

#include "MyWindow.h"

MyWindow::MyWindow()
{
    setFixedSize(830, 200);

    // Create a text string, which is used to output the text file
    std::string myText;

    // Read from the text file
    std::ifstream MyReadFile("/home/user/Documents/HAL-Drotek-F9P-main/HAL-Drotek-F9P-main/demofile2.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
      // Output the text from the file
      std::cout << myText;
    }

    // Close the file
    MyReadFile.close();

    m_latitude = new QLabel("0.0");
    m_longitude = new QLabel("0.0");
    m_altitude = new QLabel("0.0");
    m_time = new QLabel("0");
    m_status = new QLabel("?");

    QVBoxLayout *vboxLayout = new QVBoxLayout;

    QPushButton *pushButton = new QPushButton("Pause");

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Latitude : ", m_latitude);
    formLayout->addRow("Longitude: ", m_longitude);
    formLayout->addRow("Altitude: ", m_altitude);
    formLayout->addRow("Time: ", m_time);
    formLayout->addRow("Has fix: ", m_status);

    vboxLayout->addLayout(formLayout);
    vboxLayout->addWidget(pushButton);

    setLayout(vboxLayout);


    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MyWindow::UpdateData);
    m_timer->start(1000);
}

void MyWindow::UpdateData() {
    std::string latitude;
    std::string longitude;
    std::string altitude;
    std::string time;
    std::string hasFix;

    std::ifstream MyReadFile("/home/user/Documents/HAL-Drotek-F9P-main/HAL-Drotek-F9P-main/demofile2.txt");
    getline(MyReadFile, latitude);
    getline(MyReadFile, longitude);
    getline(MyReadFile, altitude);
    getline(MyReadFile, time);
    getline(MyReadFile, hasFix);
    MyReadFile.close();

    if (latitude != "") {
        m_longitude->setText(QString::fromStdString(latitude));
        m_latitude->setText(QString::fromStdString(longitude));
        m_altitude->setText(QString::fromStdString(altitude));
        m_time->setText(QString::fromStdString(time));
        m_status->setText(QString::fromStdString(hasFix));
    }
}
