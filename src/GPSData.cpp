#include <QDate>

#include <GPSData.h>

GPSData::GPSData(QObject *parent) :
    QObject(parent)
{
    m_latitude = "";
    m_longitude = "";
    m_altitude = "";
    m_time = QDate::currentDate().toString("yyyy.MM.dd") + " " + QDateTime::currentDateTime().toString("hh:mm:ss");
    m_status = "Unknown";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &GPSData::UpdateData);
    m_timer->start(1000);

    m_gnss = new PyHALDrotekF9P();

    if (!m_gnss->init("/dev/ttyACM0")) {
        std::cout << "No GPS Found !" << std::endl;
        std::cout << "Please make sure that the application is running as root and that the GNSS device is properly plugged." << std::endl;
    }

    std::cout << m_gnss->get_gnss_name() << std::endl;
}

void GPSData::UpdateData() {
    double hasFix;

    double *res = new double[6];
    m_gnss->get_gnss_info(res);
    hasFix = m_gnss->has_fix();

    // We use the setters because they emit a signal
    // so that the UI gets refreshed
    setLongitude(QString::number(res[0]));
    setLatitude(QString::number(res[1]));
    setAltitude(QString::number(res[2]));
    setTime(QDate::currentDate().toString("yyyy.MM.dd") + " " + QDateTime::currentDateTime().toString("hh:mm:ss"));
    setStatus(hasFix == 1 ? "True" : "False");

    delete [ ] res;
}


QString GPSData::latitude()
{
    return m_latitude;
}

QString GPSData::longitude()
{
    return m_longitude;
}
QString GPSData::altitude()
{
    return m_altitude;
}
QString GPSData::time()
{
    return m_time;
}
QString GPSData::status()
{
    return m_status;
}


void GPSData::setLatitude(const QString &latitude)
{
    if (latitude == m_latitude)
        return;

    m_latitude = latitude;
    emit latitudeChanged();
}

void GPSData::setLongitude(const QString &longitude)
{
    if (longitude == m_longitude)
        return;

    m_longitude = longitude;
    emit longitudeChanged();
}

void GPSData::setAltitude(const QString &altitude)
{
    if (altitude == m_altitude)
        return;

    m_altitude = altitude;
    emit altitudeChanged();
}

void GPSData::setTime(const QString &time)
{
    if (time == m_time)
        return;

    m_time = time;
    emit timeChanged();
}

void GPSData::setStatus(const QString &status)
{
    if (status == m_status)
        return;

    m_status = status;
    emit statusChanged();
}
