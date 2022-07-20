#ifndef GPSDATA_H
#define GPSDATA_H

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QTimer>
#include <QObject>
#include <QString>
#include <QtQml>

#include "../src/gps_driver/drotek_f9p_rover.cpp"

class GPSData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(QString longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(QString altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    QML_ELEMENT

public:
    explicit GPSData(QObject *parent = nullptr);

    QString latitude();
    QString longitude();
    QString altitude();
    QString time();
    QString status();

    void setLatitude(const QString &latitude);
    void setLongitude(const QString &longitude);
    void setAltitude(const QString &altitude);
    void setTime(const QString &time);
    void setStatus(const QString &status);

signals:
    void latitudeChanged();
    void longitudeChanged();
    void altitudeChanged();
    void timeChanged();
    void statusChanged();

public slots:
    void UpdateData();

private:
    QString m_latitude;
    QString m_longitude;
    QString m_altitude;
    QString m_time;
    QString m_status;

    QTimer *m_timer;

    PyHALDrotekF9P *m_gnss;
};

#endif // GPSDATA_H
