#ifndef TEMPCONVERTER_H
#define TEMPCONVERTER_H

#include <QObject>

class TempConverter : public QObject
{
    Q_OBJECT
public:
    explicit TempConverter(int tempCelsius, QObject *parent = 0);

    int tempCelsius() const;               //getter
    int tempFahrenheit() const;           //

signals:
    void tempCelsiusChanged(int);
    void tempFahrenheitChanged(int);

    void typeCelsiusChanged(double);
    void typeFahrenheitChanged(double);

public slots:
    void setTempCelsius(int);           //setter - temp
    void setTempFahrenheit(int);       //

    void setTypeCelsius(int);        //setter - type
    void setTypeFahrenheit(int);    //

private:
    int m_tempCelsius;
};

#endif // TEMPCONVERTER_H
