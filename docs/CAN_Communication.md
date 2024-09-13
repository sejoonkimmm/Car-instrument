
# CAN Communication
This section describes the Setup we used for our PiRacer Instrument Cluster. 

## Materials
The following materials are used for this section. The Speed Sensor (LM393) is connected with Arduino Nano and the Arduino Nano is connected with MCP2515 CAN Module. The CAN BUS is established between the MCP2515 and the 2CH CAN BUS FD HAT. 
The 2CH CAN BUS FD HAT is connected with Raspberry Pi 4. 
The drivetrain of the PiRacer is connected via I2C with the Raspberry Pi 4.

| PiRacer | Raspberry Pi 4 | 2CH CAN-BUS FD HAT | MCP2515 | Arduino Nano | SpeedSensor |
|:-------:|:-------:|:-------------------:|:-------:|:-----------:|:------------------:|
|<img src="./imgs/piracer.jpg" alt="piracer" >|<img src="./imgs/raspberry-pi-4-modell-b.jpg" alt="RPi" width="70%" height="70%">|<img src="./imgs/2ch-can-fd-hat.jpg" alt="2ch CAN BUS FD HAT" width="70%" height="70%">|<img src="./imgs/MCP2515.png" alt="MCP2515" width="70%" height="70%">|<img src="./imgs/Arduino_Nano.jpg" alt="Arduino Nano" width="70%" height="50%">|<img src="./imgs/speedsensor.png" alt="speed sensor" width="70%" height="70%">|
