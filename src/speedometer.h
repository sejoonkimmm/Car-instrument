#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include <QPainter>

class Speedometer : public QWidget
{
    Q_OBJECT
public:
    explicit Speedometer(QWidget *parent = nullptr);
    ~Speedometer();

    double	getSpeed() const;
    void	setSpeed(double speed);

protected:
    void	paintEvent(QPaintEvent *) override;

private:
    double	speed;

    static const int START_ANGLE = 240;

    void	drawBackground(QPainter *painter);
    void	drawScale(QPainter *painter);
    void	drawScaleMark(QPainter *painter, int angle,
                       int penWidth, int lineStart,
                       int lineEnd, bool drawText);
    void	drawNeedle(QPainter *painter);
    void	drawSpeedText(QPainter *painter);
};

#endif // SPEEDOMETER_H
