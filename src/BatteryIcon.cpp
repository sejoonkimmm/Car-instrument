#include "BatteryIcon.hpp"

BatteryIcon::BatteryIcon(QObject *parent) :
                                QObject{parent},
                                _percent{97} // 96 is just a test value. Will be set to 100 on completion
{
    _battTimerId = startTimer(2000);

    // init transmission with both I2C Bus and Chip Address
    if ( ina219_begin_txv() ) {
      qDebug() << "Failed to initialize INA219";
    }
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

uint16_t getLowestMostOccuring(uint16_t * arr, uint8_t len, uint16_t cutOff) {
    // Insert all elements in hash Table
    // using format element=>frequency
    // Also, filter out junks using cutOff
    std::unordered_map<uint16_t, uint8_t> myHash;
    for (uint8_t i = 0; i < len; i++) {
        if(arr[i] > cutOff) {
            myHash[arr[i]]++;
        }
    }

    // find the max frequency.
    // Take element with lower val if max freq more than 1
    uint8_t max_count = 0;
    uint16_t res = 0;
    for (auto j : myHash) {
        if (max_count < j.second) {
            res = j.first;
            max_count = j.second;
        } else if (max_count == j.second && res > j.first) {
            res = j.first;
        }
    }

    return res;
}

// A pseudo setter but it's arg is default which
// is only there coz Q_PROPERTY requires WRITE to
// have one arg. We dont use it because it gets
// the value from the battery data
void BatteryIcon::refreshPercent(uint8_t & _percent) {
    // Check if _rawBattData[] is filled.
    // Update the batt status for UI if yes
    if (_count >= BI_MAX_ARR_SIZE) {
        // call functions to perform percentage calculation and store data to _percent
        uint16_t mostOccuringBattData = getLowestMostOccuring(_rawBattData, BI_MAX_ARR_SIZE, 10000);

        // reset count
        _count = 0;

        qDebug() << "mostOccuringBattData: " << mostOccuringBattData;

    }

    // retrieve one battery status data from ina219,
    // and store to _rawBattData[]
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
