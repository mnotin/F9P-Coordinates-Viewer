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

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow();

public slots:
    void UpdateData();

private:
    QLabel *m_latitude;
    QLabel *m_longitude;
    QLabel *m_altitude;
    QLabel *m_time;
    QLabel *m_status;

    QTimer *m_timer;
};

#endif // MYWINDOW_H
