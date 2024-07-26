#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Instrument Cluster");
    this->setFixedSize(1280, 400);
    this->setStyleSheet("background-color: black");

    this->speedometer = new Speedometer(this);
    setCentralWidget(this->speedometer);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::testSpeedometer);
    timer->start(15);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testSpeedometer()
{
    double currSpeed = this->speedometer->getSpeed();
    if (currSpeed < 240)
    {
        this->speedometer->setSpeed(currSpeed + 0.2);
    }
    else
    {
        this->speedometer->setSpeed(0);
    }
}
