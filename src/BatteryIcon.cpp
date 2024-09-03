#include "BatteryIcon.hpp"

BatteryIcon::BatteryIcon(QObject *parent) :
                                QObject{parent},
                                _percent{96}, // 96 is just a test value. Will be set to 100 on completion
                                _rawData{0} {
}

uint8_t BatteryIcon::isPercent() const {
    return _percent;
}

// A pseudo setter but it's arg is default which
// is only there coz Q_PROPERTY requires WRITE to
// have one arg. We dont use it because it gets
// the value from the battery data
void BatteryIcon::refreshPercent(uint8_t percent) {
    // call these functions to do the job
    // _rawData = retrieveRawData();
    // _percent = rawDataToPercent();
    _percent = 1;
    emit isPercentChanged();
}
