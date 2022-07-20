#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QTimer>

#include "../src/gps_driver/drotek_f9p_rover.cpp"

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow();

public slots:
    void UpdateData();
    void SwitchReadGpsData();

private:
    QLabel *m_latitude;
    QLabel *m_longitude;
    QLabel *m_altitude;
    QLabel *m_time;
    QLabel *m_status;

    QPushButton *m_pushButton;
    bool m_readGpsData;

    QTimer *m_timer;

    PyHALDrotekF9P *m_gnss;
};

#endif // MYWINDOW_H
