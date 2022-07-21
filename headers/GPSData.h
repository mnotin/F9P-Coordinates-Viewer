#ifndef GPSDATA_H
#define GPSDATA_H

#include <QTimer>
#include <QObject>
#include <QString>
#include <QtQml>

#include "../src/gps_driver/drotek_f9p_rover.cpp"

class GPSData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(double altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(bool hasFix READ hasFix WRITE setHasFix NOTIFY hasFixChanged)
    QML_ELEMENT

public:
    explicit GPSData(QObject *parent = nullptr);

    double latitude() const;
    double longitude() const;
    double altitude() const;
    QString time() const;
    bool hasFix() const;

    void setLatitude(const double latitude);
    void setLongitude(const double longitude);
    void setAltitude(const double altitude);
    void setTime(const QString &time);
    void setHasFix(const bool status);

signals:
    void latitudeChanged();
    void longitudeChanged();
    void altitudeChanged();
    void timeChanged();
    void hasFixChanged();

public slots:
    void UpdateData();

private:
    double m_latitude;
    double m_longitude;
    double m_altitude;
    QString m_time;
    bool m_hasFix;

    QTimer *m_timer;

    PyHALDrotekF9P *m_gnss;
};

#endif // GPSDATA_H
