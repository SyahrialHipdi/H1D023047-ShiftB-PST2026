#include <Arduino_FreeRTOS.h>

void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskPrint(void *pvParameters);

int delayLed1 = 200;
int delayLed2 = 300;

void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);

  xTaskCreate(
    TaskBlink1,
    "task1",
    128,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskBlink2,
    "task2",
    128,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskPrint,
    "task3",
    128,
    NULL,
    1,
    NULL
  );

  vTaskStartScheduler();
}

void loop() {
}

void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while (1) {
    digitalWrite(8, HIGH);
    vTaskDelay(delayLed1 / portTICK_PERIOD_MS);

    digitalWrite(8, LOW);
    vTaskDelay(delayLed1 / portTICK_PERIOD_MS);
  }
}

void TaskBlink2(void *pvParameters) {
  pinMode(9, OUTPUT);

  while (1) {
    digitalWrite(9, HIGH);
    vTaskDelay(delayLed2 / portTICK_PERIOD_MS);

    digitalWrite(9, LOW);
    vTaskDelay(delayLed2 / portTICK_PERIOD_MS);
  }
}

void TaskPrint(void *pvParameters) {
  while (1) {

    int potValue = analogRead(A0);

    // Mapping nilai potensiometer
    // 0 - 1023 menjadi 100 - 1000 ms
    int mappedDelay = map(potValue, 0, 1023, 100, 1000);

    delayLed1 = mappedDelay;
    delayLed2 = mappedDelay + 100;

    Serial.print("Potensiometer: ");
    Serial.print(potValue);

    Serial.print(" | Delay LED: ");
    Serial.println(mappedDelay);

    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}
