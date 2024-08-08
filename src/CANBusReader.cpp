#include "CANBusReader.h"
#include <QDebug>

CANBusReader::CANBusReader(QString interface, QObject *parent)
    : QObject{parent}
{
    QString errorString;
    m_canDevice = QCanBus::instance()->createDevice(
        CAN_BUS_PLUGIN, interface, &errorString);
    if (!m_canDevice) {
        // TODO: Notify of the error
        qDebug() << errorString;
        return;
    } else {
        if (!m_canDevice->connectDevice()) {
            delete m_canDevice;
            m_canDevice = nullptr;
            return;
        }
    }
}

CANBusReader::~CANBusReader() {
    if (m_canDevice) {
        m_canDevice->disconnectDevice();
        delete m_canDevice;
    }
}

void CANBusReader::readCanData()
{
    while (m_canDevice->framesAvailable()) {
        QCanBusFrame frame = m_canDevice->readFrame();
        if (frame.isValid() && frame.frameId() == FRAME_ID_SPEED) {
            int speed = static_cast<int>(frame.payload().at(0));
            emit newData(speed);
        }
    }
}
