#include "tempconverter.h"

// konstruktor
TempConverter::TempConverter(int tempCelsius, QObject *parent) : QObject(parent)
{
    m_tempCelsius = tempCelsius;
}

//settery:
void TempConverter::setTempCelsius(int tempCelsius)
{
    if (m_tempCelsius == tempCelsius)
    {
        return;
    }

    m_tempCelsius = tempCelsius;
    emit tempCelsiusChanged(m_tempCelsius);
    emit tempFahrenheitChanged(tempFahrenheit());
}
void TempConverter::setTempFahrenheit(int tempFahrenheit)
{
    int tempCelsius = (5.0 / 9.0) * (tempFahrenheit - 32);
    setTempCelsius(tempCelsius);
}
void TempConverter::setTypeCelsius(int)
{
    double newValueTempCelsius = (double)((double)tempCelsius());
    emit typeCelsiusChanged(newValueTempCelsius);
}
void TempConverter::setTypeFahrenheit(int)
{
    double newValueTempFahrenheit = (double)((double)tempFahrenheit());
    emit typeFahrenheitChanged(newValueTempFahrenheit);
}


//gettery:
int TempConverter::tempCelsius() const
{
    return m_tempCelsius;
}
int TempConverter::tempFahrenheit() const
{
    int TempFahrenheit = m_tempCelsius * (9.0 / 5.0) + 32;
    return TempFahrenheit;
}

