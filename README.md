# Car-instrument

[Assignment Link](https://github.com/SEA-ME/DES_Instrument-Cluster)

[![Contributors](https://img.shields.io/badge/Contributors-4-blue.svg)](#contributors)

## Contributors
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/sejoonkimmm">
        <img src="https://avatars.githubusercontent.com/sejoonkimmm" width="100px;" alt=""/><br />
        <sub><b>Sejoon Kim</b></sub>
        <br />
        DevOps Engineer <br>Software Architecture
      </a>
      <br />
      <a href="https://github.com/sejoonkimmm" title="Code">💻</a>
      <a href="https://github.com/sejoonkimmm" title="Documentation">📖</a>
    </td>
    <td align="center">
      <a href="https://github.com/Adinkra-Ideas">
        <img src="https://avatars.githubusercontent.com/Adinkra-Ideas" width="100px;" alt=""/><br />
        <sub><b>Adinkra Ideas</b></sub>
      </a>
      <br />
      <a href="https://github.com/Adinkra-Ideas" title="Code">💻</a>
      <a href="https://github.com/Adinkra-Ideas" title="Documentation">📖</a>
    </td>
    <td align="center">
      <a href="https://github.com/BadrKC">
        <img src="https://avatars.githubusercontent.com/BadrKC" width="100px;" alt=""/><br />
        <sub><b>Badr KC</b></sub>
      </a>
      <br />
      <a href="https://github.com/BadrKC" title="Code">💻</a>
      <a href="https://github.com/BadrKC" title="Documentation">📖</a>
    </td>
    <td align="center">
      <a href="https://github.com/AmosAidoo">
        <img src="https://avatars.githubusercontent.com/AmosAidoo" width="100px;" alt=""/><br />
        <sub><b>Amos Aidoo</b></sub>
      </a>
      <br />
      <a href="https://github.com/AmosAidoo" title="Code">💻</a>
      <a href="https://github.com/AmosAidoo" title="Documentation">📖</a>
    </td>
  </tr>
</table>

## Introduction

The PiRacer instrument cluster Qt application project is aimed at creating a real-time speedometer for a PiRacer car. The application will run on a Raspberry Pi and receive speed data from a speed sensor via the in-vehicle communication using Controller Area Network (CAN) protocol. This project will provide an opportunity for students to gain practical experience in software engineering, specifically in the areas of embedded systems, software architecture, and communication protocols. The project will also allow students to gain knowledge of the GUI frameworks (eg. Qt), that are widely used in the automotive industry for developing many embedded applications. The successful completion of this project will demonstrate the students' ability to design and implement a real-world software solution, and their ability to effectively communicate their results.

## Background Information

This section provides background information on the technologies and tools used in the project, including the Raspberry Pi, in-vehicle communication using CAN (Controller Area Network) protocol, and the Qt framework.

The Raspberry Pi is a small, low-cost computer that is commonly used for hobbyist and educational projects. It provides a versatile platform for developing a wide range of applications, including those in the automotive industry. The Qt framework is a popular cross-platform application development framework that is widely used in the automotive industry for developing embedded applications, such as instrument clusters and infotainment systems. The CAN protocol is a communication standard that is widely used in the automotive industry for interconnecting different ECUs (Electronic Control Units) in a vehicle.

## Project Goals and Objectives

The main goal of the PiRacer Instrument Cluster Qt Application project is to create a functioning instrument cluster for a PiRacer car that displays real-time speed data from a speed sensor via CAN bus.

The following are the specific objectives of the project:

- To design and implement a Qt-based graphical user interface (GUI) for the instrument cluster.
- To integrate an Arduino-based speed sensor system with the Raspberry Pi using the CAN bus protocol.
- To display real-time speed data on the instrument cluster GUI.
- To test the functionality of the instrument cluster using realistic driving scenarios.
- To document the project in a comprehensive manner, including a detailed explanation of the system architecture, software design, implementation, results, and conclusions.

### BONUS Part
- To display the battery level of PiRacer on the Instrument Cluster.

## Technical Requirements

- **Raspberry Pi**: A Raspberry Pi 3 Model B or later is recommended for this project, as it provides sufficient processing power and memory for running the instrument cluster application and receiving data from the speed sensor via CAN.
- **Qt (Open Source version)**: Qt Creator is a powerful, cross-platform integrated development environment (IDE) for developing applications with the Qt framework. The Qt libraries for Raspberry Pi include all of the necessary components for building Qt applications for the Raspberry Pi.
- **CAN bus interface**: A CAN bus interface is required for connecting the Raspberry Pi to the vehicle's CAN bus and receiving speed data from the speed sensor. Suitable CAN bus interfaces for the Raspberry Pi include the MCP2515 and the TJA1050.
- **Speed sensor**: A speed sensor capable of transmitting speed data via CAN is required for this project. The type of speed sensor required will depend on the vehicle being used for testing.
- **OBD-II cable**: An OBD-II cable is required for connecting the Raspberry Pi and the speed sensor to the vehicle's CAN bus. This cable provides a convenient and reliable way to tap into the vehicle's CAN bus and receive data from the speed sensor.
- **Voltage regulator**: A 12V to 5V voltage regulator is required for powering the Raspberry Pi from the vehicle's electrical system. The voltage regulator ensures that the Raspberry Pi receives a stable, regulated power supply, even when the vehicle's electrical system voltage fluctuates.
- **Display**: A display is required for the instrument cluster application. Suitable displays include LCD and OLED displays, and the size and resolution of the display will depend on the specific requirements of the instrument cluster application.
- **Mounting hardware**: A suitable method of mounting the display and Raspberry Pi in the vehicle is required. This may involve mounting brackets, enclosures, or other hardware, depending on the specific requirements of the instrument cluster application.
- **Vehicle for testing**: Access to a PiRacer for testing the instrument cluster application is required. The PiRacer should have a CAN bus system and should be compatible with the speed sensor and other hardware components.

## Software Design

The software design of the PiRacer instrument cluster application is based on the Qt framework, which is a popular cross-platform application development framework. Qt provides a wide range of tools and libraries that make it easy to create user-friendly graphical user interfaces (GUIs) and communicate with hardware devices.

The software design of the PiRacer instrument cluster consists of several key components, including the main application, the CAN communication module, and the data display module.

- **Main Application**: Responsible for managing the overall functionality of the instrument cluster. It creates the GUI, manages the communication with the speed sensor via the CAN bus, and displays the speed data on the screen.
- **CAN Communication Module**: Responsible for communicating with the speed sensor via the CAN bus. It receives speed data from the speed sensor and passes it on to the main application for display. This module uses the CAN library provided by Qt to communicate with the speed sensor.
- **Display Module**: Responsible for displaying the speed data on the screen. It receives speed data from the main application and displays it in an easy-to-read format on the screen. This module can be customized to display the speed data in various ways, such as using a speedometer or a numerical display.

The software design of the PiRacer instrument cluster application is designed to be flexible and scalable, allowing for future modifications and additions. The use of the Qt framework and modular design also makes it easy to maintain and update the application.

## Implementation

The implementation of the PiRacer instrument cluster application involves several key steps, including writing the code for the various components, testing the code, and deploying the application on the Raspberry Pi.

- **Writing the code**: The first step in the implementation process is writing the code for the various components of the application. This includes writing the code for the main application, the CAN communication module, and the display module. The code should be written in a clear and organized manner, making use of best practices in software engineering.
- **Testing the code**: After writing the code, it is important to test it to ensure that it works correctly and meets the technical requirements. This can be done by running the code on the Raspberry Pi and verifying that it correctly receives speed data from the speed sensor and displays it on the screen.
- **Deploying the application**: Once the code has been tested and verified, the application can be deployed on the Raspberry Pi. This involves copying the code to the Raspberry Pi and executing it. The Raspberry Pi should be configured to boot up and run the application automatically upon startup.

The implementation process should be carefully planned and executed to ensure that the final product meets the technical requirements and provides a user-friendly interface for monitoring the speed of the vehicle. The implementation process should also be carefully documented, so that any future modifications or updates to the application can be made easily.

## Results

The results of the PiRacer instrument cluster application can be evaluated based on the following factors:

- **Functionality**: The most important factor in evaluating the results of the project is the functionality of the application. Does the application receive speed data from the speed sensor via CAN and display it on the screen in a user-friendly manner? If the answer is yes, then the application can be considered a success.
- **Usability**: Another important factor in evaluating the results of the project is the usability of the application. Is the application user-friendly and easy to use? Does it provide a clear and intuitive interface for monitoring the speed of the vehicle? If the answer is yes, then the application can be considered a success.
- **Reliability**: The reliability of the application is another important factor in evaluating the results of the project. Does the application run smoothly and consistently without any errors or crashes? If the answer is yes, then the application can be considered a success.
- **Maintainability**: The maintainability of the application is another important factor in evaluating the results of the project. Is the code well-organized and easy to modify? Can future updates and modifications be made easily? If the answer is yes, then the application can be considered a success.


## CI/CD Pipeline

We have set up a CI/CD pipeline using GitHub Actions. The pipeline ensures that the code is automatically built, tested, and deployed. When the PiRacer is turned on and connected to the internet, the project is automatically executed, ensuring seamless updates and deployment.

## Monitoring

We use Prometheus and Grafana to monitor the resource usage and performance of the PiRacer. Prometheus collects time-series data, which is then visualized using Grafana dashboards. This setup helps in analyzing the performance metrics and ensures the system operates efficiently.




