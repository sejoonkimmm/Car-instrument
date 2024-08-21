#include "Speedometer.h"
#include <QDebug>
#include <QtMath>

Speedometer::Speedometer(QObject *parent)
    : QObject{parent}, m_newSpeed(0.0)
{}

int Speedometer::speed()
{
    return m_speed;
}

double Speedometer::newSpeed()
{
    return m_newSpeed;
}

void Speedometer::setSpeed(int newSpeed)
{
    double circumference = 2 * M_PI * 3.35;
    double rps = static_cast<double>(newSpeed) / 20;
    double speedCmPerSec = circumference * rps;

    // set new speed to speedCmPerSec
    setNewSpeed(speedCmPerSec);
}

void Speedometer::setNewSpeed(double speed)
{
    if (qFuzzyCompare(m_newSpeed, speed))
        return;
    m_newSpeed = speed;
    emit newSpeedChanged();
}
