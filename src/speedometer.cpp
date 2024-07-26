#include "speedometer.h"

#include <QTimer>

Speedometer::Speedometer(QWidget *parent)
    : QWidget(parent), speed(0)
{
    setMinimumSize(300, 300);
}

Speedometer::~Speedometer()
{}

double Speedometer::getSpeed() const
{
    return this->speed;
}

void Speedometer::setSpeed(double speed)
{
    this->speed = speed;
    this->repaint();
}

void Speedometer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2,
                        (height() - side) / 2, side, side);
    painter.setWindow(-150, -190, 300, 300);

    drawBackground(&painter);
    drawScale(&painter);
    drawNeedle(&painter);
    drawSpeedText(&painter);
}

void Speedometer::drawBackground(QPainter *painter)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(-140, -140, 280, 280);
}

void Speedometer::drawScale(QPainter *painter)
{
    QPen pen(Qt::white);
    painter->setPen(pen);

    for (int i = 0; i <= 240; i += 4)
    {
        if (i % 40 == 0)
        {
            drawScaleMark(painter, i, 2, -120, -140, true);
        }
        else if (i % 20 == 0)
        {
            drawScaleMark(painter, i, 1, -125, -140, false);
        }
        else
        {
            drawScaleMark(painter, i, 1, -130, -140, false);
        }
    }
}

void Speedometer::drawScaleMark(QPainter *painter, int angle, int penWidth, int lineStart, int lineEnd, bool drawText)
{
    QPen pen = painter->pen();
    pen.setWidth(penWidth);
    painter->setPen(pen);

    painter->save();
    painter->rotate(START_ANGLE + angle);
    painter->drawLine(0, lineStart, 0, lineEnd);
    painter->restore();

    if (drawText)
    {
        painter->save();
        painter->rotate(START_ANGLE + angle);
        painter->translate(0, -107);
        painter->rotate(-START_ANGLE - angle);
        painter->drawText(-13, -6, 26, 12, Qt::AlignCenter, QString::number(angle));
        painter->restore();
    }
}

void Speedometer::drawNeedle(QPainter *painter)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->save();
    painter->rotate(START_ANGLE + speed);
    painter->drawPolygon(QPolygon() << QPoint(-3, 0) << QPoint(0, -100) << QPoint(3, 0));
    painter->restore();

    painter->setBrush(Qt::black);
    painter->setPen(Qt::white);
    painter->drawEllipse(-10, -10, 20, 20);
}

void Speedometer::drawSpeedText(QPainter *painter)
{
    QFont font;

    font.setItalic(true);
    painter->setFont(font);
    painter->drawText(20, 35, 30, 15, Qt::AlignCenter, QString("cm/s"));
    font.setPointSize(20);
    painter->setFont(font);
    painter->drawText(-20, 30, 40, 20, Qt::AlignCenter,
                      QString::number(static_cast<int>(this->speed)));
}
