#ifndef CONFIG_H
#define CONFIG_H

// Globale Konfigurationen
#define BAUD_RATE 115200

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

// Pins für die Sensoren
#define SENSOR_1_TRIGGER_PIN 2
#define SENSOR_1_ECHO_PIN 4

#define SENSOR_2_TRIGGER_PIN 5
#define SENSOR_2_ECHO_PIN 18

#define SENSOR_3_TRIGGER_PIN 19
#define SENSOR_3_ECHO_PIN 21

#define SENSOR_4_TRIGGER_PIN 22
#define SENSOR_4_ECHO_PIN 23

#endif
