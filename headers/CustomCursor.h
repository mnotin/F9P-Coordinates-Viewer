#ifndef CUSTOMCURSOR_H
#define CUSTOMCURSOR_H

#include <QObject>
#include <QString>
#include <QtQml>

class CustomCursor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(bool latitudeIsSet READ latitudeIsSet WRITE setLatitudeIsSet NOTIFY latitudeIsSetChanged)
    Q_PROPERTY(bool longitudeIsSet READ longitudeIsSet WRITE setLongitudeIsSet NOTIFY longitudeIsSetChanged)
    QML_ELEMENT

public:
    explicit CustomCursor(QObject *parent = nullptr);

    double latitude() const;
    double longitude() const;
    bool latitudeIsSet() const;
    bool longitudeIsSet() const;

    void setLatitude(const double latitude);
    void setLongitude(const double longitude);
    void setLatitudeIsSet(const bool latitudeIsSet);
    void setLongitudeIsSet(const bool longitudeIsSet);

signals:
    void latitudeChanged();
    void longitudeChanged();
    void latitudeIsSetChanged();
    void longitudeIsSetChanged();

private:
    double m_latitude;
    double m_longitude;
    bool m_latitudeIsSet;
    bool m_longitudeIsSet;
};

#endif // CUSTOMCURSOR_H
