/*! Klasa TempConverter ma dwa zastosowania - pierwsze to oczywiscie automatyczna konwersja skali temperatury (C->F, F->C),
a drugie to zmiana typu danych do kontrolki QLCDNumber.
Klasa ta posiada:
* sloty do ustawiania temperatury (uzytkownik korzysta z QDial)
* sygnaly do przesylania informacji o jakichkolwiek zmianach
* metody pomocnicze do pobierania temperatury w konkretnej skali
* zmienna prywatna do przechowywania wartosci aktualnej temperatury

Paweł Olbrycht, pazdziernik 2018

*/




#ifndef TEMPCONVERTER_H
#define TEMPCONVERTER_H

#include <QObject>

class TempConverter : public QObject
{
    Q_OBJECT
public:
    explicit TempConverter(int tempCelsius, QObject *parent = 0);

    int tempCelsius() const;               ///< pobranie temp. w skali C
    int tempFahrenheit() const;           ///< pobranie temp. w skali F

signals:
    void tempCelsiusChanged(int);           ///< sygnal zmiany wartosci temp. w skali C
    void tempFahrenheitChanged(int);        ///< sygnal zmiany wartosci temp. w skali F

    void typeCelsiusChanged(double);        ///< sygnal zmiany typu danej w skali C
    void typeFahrenheitChanged(double);     ///< sygnal zmiany typu danej w skali F

public slots:
    void setTempCelsius(int);           ///< setter dla temperatury w skali C
    void setTempFahrenheit(int);       ///< oraz w skali F

    void setTypeCelsius(int);        ///< setter dla typu danych w skali C
    void setTypeFahrenheit(int);    ///< oraz w skali F

private:
    int m_tempCelsius;              ///< zmienna prywatna przechowujaca temperature
};

#endif // TEMPCONVERTER_H
