#include "BatteryIcon.hpp"

BatteryIcon::BatteryIcon(QObject *parent) :
                                QObject{parent},
                                _percent{96} // 96 is just a test value. Will be set to 100 on completion
{
    _battTimerId = startTimer(2000);
}

BatteryIcon::~BatteryIcon() {
    killTimer(_battTimerId);
}

void BatteryIcon::timerEvent(QTimerEvent *event) {
    this->refreshPercent(_percent);
}

uint8_t BatteryIcon::isPercent() const {
    return _percent;
}

// A pseudo setter but it's arg is default which
// is only there coz Q_PROPERTY requires WRITE to
// have one arg. We dont use it because it gets
// the value from the battery data
void BatteryIcon::refreshPercent(uint8_t & _percent) {
    // _percent += 1;
    // Check if _rawBattData[] is filled.
    // Update the batt status for UI if yes
    if (_count >= BI_MAX_ARR_SIZE) {
        // call functions to perform percentage calculation and store data to _percent

        // reset count
        _count = 0;
    }

    // retrieve one data from
    if ( ! ina219_getRawBattData( &_rawBattData[_count] ) ) {
        ++_count;
    } else {
    #ifdef DEBUG_EN
        printf("%s\n", "failure to read");
    #endif
    }

    // refresh the UI
    emit isPercentChanged();
}
