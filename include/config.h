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
//Sensor PIN A for the red wire and PIN B for the black wire
#define ULTRASONIC_SENSOR_1_PIN_A 16
#define ULTRASONIC_SENSOR_1_PIN_B 17

#define ULTRASONIC_SENSOR_2_PIN_A 18
#define ULTRASONIC_SENSOR_2_PIN_B 19

#define ULTRASONIC_SENSOR_3_PIN_A 21
#define ULTRASONIC_SENSOR_3_PIN_B 22

#define ULTRASONIC_SENSOR_4_PIN_A 25
#define ULTRASONIC_SENSOR_4_PIN_B 26

#endif // CONFIG_H
