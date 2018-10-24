#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    converter = new TempConverter(0, this);

    ui->dialCelsius->setMinimum(-10100);
    ui->dialFahrenheit->setMinimum(-14900);

    ui->dialCelsius->setMaximum(10100);
    ui->dialFahrenheit->setMaximum(18132);

    // CELSIUS

    connect(ui->dialCelsius, SIGNAL(valueChanged(int)), converter, SLOT(setTypeCelsius(int)));            // converting from int to double
    connect(converter, SIGNAL(typeCelsiusChanged(double)), ui->LCDCelsius, SLOT(display(double)));        // displaying double-type value
    connect(ui->dialCelsius, SIGNAL(valueChanged(int)), converter, SLOT(setTempCelsius(int)));
    connect(converter, SIGNAL(tempCelsiusChanged(int)), ui->dialCelsius, SLOT(setValue(int)));

    // FAHRENHEIT

    connect(ui->dialFahrenheit, SIGNAL(valueChanged(int)), converter, SLOT(setTypeFahrenheit(int)));       // converting from int to double
    connect(converter, SIGNAL(typeFahrenheitChanged(double)), ui->LCDFahrenheit, SLOT(display(double)));   // displaying double-type value
    connect(ui->dialFahrenheit, SIGNAL(valueChanged(int)), converter, SLOT(setTempFahrenheit(int)));
    connect(converter, SIGNAL(tempFahrenheitChanged(int)), ui->dialFahrenheit, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
