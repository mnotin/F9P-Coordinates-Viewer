#include <QDate>
#include <iostream>

#include <CustomCursor.h>

using namespace std;

CustomCursor::CustomCursor(QObject *parent) :
    QObject(parent)
{
    m_latitude = 180.0;
    m_longitude = 360.0;
    m_latitudeIsSet = false;
    m_longitudeIsSet = false;
}

double CustomCursor::latitude() const
{
    return m_latitude;
}

double CustomCursor::longitude() const
{
    return m_longitude;
}

bool CustomCursor::latitudeIsSet() const
{
    return m_latitudeIsSet;
}

bool CustomCursor::longitudeIsSet() const
{
    return m_longitudeIsSet;
}


void CustomCursor::setLatitude(const double latitude)
{
    if (latitude == m_latitude || latitude < -90.0 || 90.0 < latitude)
        return;

    m_latitude = latitude;
    emit latitudeChanged();
    setLatitudeIsSet(true);
}

void CustomCursor::setLongitude(const double longitude)
{
    if (longitude == m_longitude || longitude < -180.0 || 180.0 < longitude)
        return;

    m_longitude = longitude;
    emit longitudeChanged();
    setLongitudeIsSet(true);
}

void CustomCursor::setLatitudeIsSet(const bool latitudeIsSet)
{
    if (latitudeIsSet == m_latitudeIsSet)
        return;

    if (!latitudeIsSet)
        m_latitude = 180.0;

    m_latitudeIsSet = latitudeIsSet;
    emit latitudeIsSetChanged();
}

void CustomCursor::setLongitudeIsSet(const bool longitudeIsSet)
{
    if (longitudeIsSet == m_longitudeIsSet)
        return;

    if (!longitudeIsSet)
        m_longitude = 360.0;

    m_longitudeIsSet = longitudeIsSet;
    emit longitudeIsSetChanged();
}
