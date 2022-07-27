#include <QDate>

#include <GPSData.h>

GPSData::GPSData(QObject *parent) :
    QObject(parent)
{
    m_latitude = 0.0;
    m_longitude = 0.0;
    m_altitude = 0.0;
    m_hasFix = false;
    m_hour = 0;
    m_minute = 0;
    m_second = 0.0;

    m_gnss = new PyHALDrotekF9P();

    if (m_gnss->init("/dev/ttyACM0")) {
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &GPSData::UpdateData);
        m_timer->start(250);

        std::cout << m_gnss->get_gnss_name() << std::endl;
    } else {
        std::cout << "No GPS Found !" << std::endl;
        std::cout << "Please make sure that the application is running as root and that the GNSS device is properly plugged." << std::endl;
    }
}

void GPSData::UpdateData() {
    double hasFix;

    double *gnss_info = new double[6];
    m_gnss->get_gnss_info(gnss_info);
    hasFix = m_gnss->has_fix();

    // We use the setters because they emit a signal
    // so that the UI gets refreshed
    setLongitude(gnss_info[0]);
    setLatitude(gnss_info[1]);
    setAltitude(gnss_info[2]);
    setHasFix(hasFix == 1);
    setSecond(m_gnss->getTimestamp().sec);
    setMinute(m_gnss->getTimestamp().min);
    setHour(m_gnss->getTimestamp().hour);

    delete [ ] gnss_info;
}


double GPSData::latitude() const
{
    return m_latitude;
}

double GPSData::longitude() const
{
    return m_longitude;
}
double GPSData::altitude() const
{
    return m_altitude;
}
bool GPSData::hasFix() const
{
    return m_hasFix;
}
int GPSData::hour() const
{
    return m_hour;
}
int GPSData::minute() const
{
    return m_minute;
}
double GPSData::second() const
{
    return m_second;
}

void GPSData::setLatitude(const double latitude)
{
    if (latitude == m_latitude)
        return;

    m_latitude = latitude;
    emit latitudeChanged();
}

void GPSData::setLongitude(const double longitude)
{
    if (longitude == m_longitude)
        return;

    m_longitude = longitude;
    emit longitudeChanged();
}

void GPSData::setAltitude(const double altitude)
{
    if (altitude == m_altitude)
        return;

    m_altitude = altitude;
    emit altitudeChanged();
}

void GPSData::setHasFix(const bool hasFix)
{
    if (hasFix == m_hasFix)
        return;

    m_hasFix = hasFix;
    emit hasFixChanged();
}

void GPSData::setHour(const int hour)
{
    if (hour == m_hour)
        return;

    m_hour = hour;
    emit hourChanged();
}

void GPSData::setMinute(const int minute)
{
    if (minute == m_minute)
        return;

    m_minute = minute;
    emit minuteChanged();
}

void GPSData::setSecond(const double second)
{
    if (second == m_second)
        return;

    m_second = second;
    emit secondChanged();
}
