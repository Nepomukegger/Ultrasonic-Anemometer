#ifndef CONFIG_H
#define CONFIG_H

// WiFi credentials
#define WIFI_SSID "Ultrasonic_Anemometer_AP"
#define WIFI_PASSWORD "!Test2345"

// Data logging interval in milliseconds
#define LOG_INTERVAL 1000

// GPS settings
#define GPS_BAUD_RATE 9600

// SD card settings
#define SD_CS_PIN 5

// LED pin
#define LED_PIN 2

//Sensor pins
//Every sensor has a write and read enable pin to select which sensor to read from and send the CLK signal to
#define ULTRASONIC_SENSOR_1_WRITE_ENABLE 16
#define ULTRASONIC_SENSOR_1_READ_ENABLE 17

#define ULTRASONIC_SENSOR_2_WRITE_ENABLE 18
#define ULTRASONIC_SENSOR_2_READ_ENABLE 19

#define ULTRASONIC_SENSOR_3_WRITE_ENABLE 21
#define ULTRASONIC_SENSOR_3_READ_ENABLE 22

#define ULTRASONIC_SENSOR_4_WRITE_ENABLE 25
#define ULTRASONIC_SENSOR_4_READ_ENABLE 26

#define ULTRASONIC_SENSOR_CLK 32
#define ULTRASONIC_SENSOR_READ 33

#endif // CONFIG_H
