# Ultrasonic anemometer

## Objective

The aim of the project is to develop an anemometer based on four
ultrasound transceivers that measures the wind direction,
wind speed and outside temperature. The wind speed
and direction are determined using the travel times (latencies) of the
ultrasound waves as a vector, with the length and direction of the
vector indicating the speed and direction. In addition,
the outside temperature is calculated from the speed of sound. The system
should be suitable for real-time measurements and be accessible wirelessly.

 

## Project scope and requirements

### Functional requirements

-   Wind speed measurement: The anemometer should measure the
    wind speed precisely in the shortest possible intervals
    and output the values ​​in real time.

-   Wind direction determination: The system should record and display the wind direction with high
    accuracy.

-   Temperature measurement: The outside temperature should also be measured and
    available via the wireless interface.

-   Wireless data transmission: All data should be available wirelessly at any time via WLAN
    or Bluetooth, ideally via a
    user-friendly interface.

-   Real-time feedback loop: A real-time feedback loop should ensure
    data processing continuously and without noticeable delay.

 

### Non-functional requirements

-   Sensitivity: The system should be able to detect small wind speeds from 0.1
    m/s.
    
-   Accuracy:

    -   Wind direction: Angular accuracy of \<0.1°.

    -   Wind speed: Accuracy of +/- 0.1 m/s.

    -   Temperature: Accuracy of +/- 0.5 °C.

    -   Response time: The measurements should be taken at intervals of a maximum of
        one second to enable real-time monitoring.

-   Software development: The software components should be developed in C++
    to ensure efficiency and compatibility with the ESP32.

 

### Safety requirements

-   Error diagnosis: In the event of a software or hardware error,
    a log file should be available for download to enable error diagnosis.

-   Automatic restart: In the event of a power failure or system crash,
    the system should restart automatically.

-   Error signaling: There should be an LED or other visual indicator
    to show the status of the system and errors.

 

### Framework conditions

-   Budget: The project budget is a maximum of 200 euros for
    hardware components such as sensors, microcontrollers and accessories.

-   Time frame: The project should be completed within six months,
    with a first function by Christmas being advantageous.

-   Hardware: An ESP32 microcontroller is used to control the
    sensors, to process the data and to output the calculated
    values. Four transceivers from SECO are used for the ultrasound measurement.

-   Software: The software is developed with PlatformIO, a
    compatible development environment for ESP32 and C++.

 

### Interfaces

-   Ultrasonic sensors: Four ultrasonic sensors for measuring the
    running times and determining the wind parameters.

-   Power supply: The system is operated by a power supply with 5V
    output voltage.

-   Communication:

    -   NMEA 2000: The measurement data is also transmitted via the NMEA 2000 standard (CAN bus) to enable efficient 
        integration into maritime networks. 
    -   Wireless connection: In parallel, the measurement data can be accessed in real time via WLAN or Bluetooth, 
        providing a user-friendly wireless interface.

-   Data format: The measurement data (wind speed, wind direction and
    temperature) are transmitted as PGNs (parameter group numbers) in NMEA
    2000 format.

-   Wind data: PGN 130306 (Wind Speed ​​and Angle)

-   Temperature: PGN 130312 (Environmental Parameters)

## Acceptance criteria

-   Functionality: The system reliably measures wind speed and wind direction and outputs these values ​​with an accuracy 
    of 0.1 m/s and \<0.1°.

-   Temperature measurement: The temperature is measured and provided precisely with an accuracy of +/- 0.5 °C.

-   Data transmission: The measurement data can be accessed via NMEA 2000 and is available in a binary format that is 
    compatible with other systems.

-   Response time: The measured values ​​are processed at intervals of one second or faster.

-   Wireless retrieval: The measurement data can be accessed at any time via WLAN or Bluetooth and is output in an 
    easy-to-read format.

-   Stability: In the event of a system error or power failure, an automatic restart occurs and error diagnostics are 
    available.