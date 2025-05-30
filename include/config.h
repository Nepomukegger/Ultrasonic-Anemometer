#ifndef CONFIG_H
#define CONFIG_H

#include <unordered_map>
#include <string>

#include "Arduino.h"

// WiFi credentials
#define AP_SSID "Ultrasonic_Anemometer_AP"
#define AP_PASSWORD "!Test2345"

// Bluetooth settings
#define BLUETOOTH_NAME "Ultrasonic_Anemometer_BT"

// Data logging interval in milliseconds
#define LOG_INTERVAL 1000

// SD card settings
#define SD_CS_PIN 5

// LED pin
#define LED_PIN 2

// Clock settings
#define CLOCK_FREQUENCY 305000

// Sensor pins
//the sensor is selected by a multiplexer S1 and S0 are the select pins of the multiplexer to select the sensor
#define S1 21
#define S0 19

#define ENABLE 18

#define SIGNAL_OUT 2
#define SIGNAL_IN 15


//Sensor
#define SENSOR_MOUNT_ANGLE 45
#define SENSOR_MOUNT_ANGLE_IN_RADIANS (SENSOR_MOUNT_ANGLE * M_PI / 180.0)
#define SENSOR_DISTANCE 0.1  // Distance between the sensors must be specified in meters
#define DISTANCE_TO_REFLECTOR 0.05

// GPS settings
#define GPS_BAUD_RATE 9600

// NMEA2000 baud rate
#define NMEA2000_BAUD_RATE 250000

// NMEA2000 settings
// bus low 34
// bus high 35
#define NMEA2000_DEVICE_NAME "Ultrasonic Anemometer"
#define NMEA2000_DEVICE_INFORMATION "ESP32"
#define NMEA2000_DEVICE_CLASS 25
#define NMEA2000_DEVICE_INSTANCE 0
#define NMEA2000_DEVICE_FUNCTION 130
#define NMEA2000_DEVICE_MANUFACTURER "Ultrasonic Anemometer"
#define NMEA2000_DEVICE_MANUFACTURER_CODE 2046
#define NMEA2000_DEVICE_INSTALLATION_DESCRIPTION "Ultrasonic Anemometer"
#define NMEA2000_DEVICE_SOFTWARE_VERSION "1.0.0"
#define NMEA2000_DEVICE_MODEL_ID 130
#define NMEA2000_DEVICE_CERTIFICATION_LEVEL 1
#define NMEA2000_DEVICE_LOAD_EQUIVALANCE 1
#define NMEA2000_DEVICE_NMEA2000_VERSION 130
#define NMEA2000_DEVICE_PRODUCT_CODE 130
#define NMEA2000_DEVICE_TX_FRAME_TYPE 0
#define NMEA2000_DEVICE_RX_FRAME_TYPE 0
#define NMEA2000_DEVICE_GROUP_FUNCTION 130
#define NMEA2000_DEVICE_GROUP_INSTANCE 0
#define NMEA2000_DEVICE_UNIQUE_NUMBER 0
#define NMEA2000_DEVICE_SYSTEM_INSTANCE 0
#define NMEA2000_DEVICE_INDUSTRY_GROUP 4
#define NMEA2000_DEVICE_ARBITRARY_ADDRESS_CAPABLE 0

// NMEA2000 message settings
#define NMEA2000_MESSAGE_ID 130
#define NMEA2000_MESSAGE_PRIORITY 6
#define NMEA2000_MESSAGE_PERIOD 1000
#define NMEA2000_MESSAGE_DATA_LENGTH 8

#endif // CONFIG_H
