#ifndef BATTERYICON_HPP
#define BATTERYICON_HPP

#include <QObject>
#include <stdio.h>
#include <cstdint>

class BatteryIcon : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 isPercent READ isPercent WRITE refreshPercent NOTIFY isPercentChanged)

public:
    explicit BatteryIcon(QObject *parent = nullptr);

    // getters
    uint8_t     isPercent() const;

    // setters
    void        refreshPercent(uint8_t percent = 0);

signals:
    void        isPercentChanged();

private:
    uint8_t     _percent;
    uint16_t    _rawData;

    uint16_t    retrieveRawData();                      // get data from our batt driver lib
    uint8_t     rawDataToPercent(uint16_t & rawData);   // convert raw data to battery Percentage and store in _percent
};

#endif // BATTERYICON_HPP
