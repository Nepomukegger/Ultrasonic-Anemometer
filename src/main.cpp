#include <Arduino.h>

TaskHandle_t Task1;

void task(void * pvParameters);

void setup() {
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  pinMode(19, OUTPUT);
  Serial.print("core: ");
  Serial.print(xPortGetCoreID());
  Serial.print("Time");
  Serial.println(esp_timer_get_time());
  xTaskCreatePinnedToCore(
                    task,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */
}

void loop() {
  Serial.print("core: ");
  Serial.print(xPortGetCoreID());
  Serial.print("Time");
  Serial.println(esp_timer_get_time());
  delay(10000);
}

void task(void *pvParameters) {
  while (true){
    Serial.print("core: ");
    Serial.print(xPortGetCoreID());
    Serial.print("Time");
    Serial.println(esp_timer_get_time());
    delay(10000);
  }
}
