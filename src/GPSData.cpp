#include <QDate>

#include <GPSData.h>

GPSData::GPSData(QObject *parent) :
    QObject(parent)
{
    m_latitude = 0.0;
    m_longitude = 0.0;
    m_altitude = 0.0;
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
    setLongitude(res[0]);
    setLatitude(res[1]);
    setAltitude(res[2]);
    setTime(QDate::currentDate().toString("yyyy.MM.dd") + " " + QDateTime::currentDateTime().toString("hh:mm:ss"));
    setStatus(hasFix == 1 ? "True" : "False");

    delete [ ] res;
}


double GPSData::latitude()
{
    return m_latitude;
}

double GPSData::longitude()
{
    return m_longitude;
}
double GPSData::altitude()
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
