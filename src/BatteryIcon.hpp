#ifndef BATTERYICON_HPP
#define BATTERYICON_HPP

#ifdef DEBUG_EN
#include <stdio.h>
#endif

#include <QObject>
#include <stdio.h>
#include <cstdint>
#include <unordered_map>

extern "C"
{
#include "INA219.h"
}

#define BI_MAX_ARR_SIZE 30

class BatteryIcon : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 isPercent READ isPercent WRITE refreshPercent NOTIFY isPercentChanged)

public:
    explicit BatteryIcon(QObject *parent = nullptr);
    ~BatteryIcon();

    // getter
    uint8_t     isPercent() const;

    // setter
    void        refreshPercent(uint8_t & _percent);

signals:
    void        isPercentChanged();

protected:
    void timerEvent(QTimerEvent *event);

private:
    uint8_t     _percent;           // Battery status converted to output in percentage, ready to be displayed to user

    int         _battTimerId;       // used for the interval timer
    uint16_t    _rawBattData[BI_MAX_ARR_SIZE];   // array holding the 16 bit data representing Voltage as retrieved directly from the INA219 chip
    uint8_t     _count;             // For counting the size of _rawBattData

    uint16_t    retrieveRawData();                      // get data from our batt driver lib
    uint8_t     rawDataToPercent(uint16_t & rawData);   // convert raw data to battery Percentage and store in _percent
};

#endif // BATTERYICON_HPP
