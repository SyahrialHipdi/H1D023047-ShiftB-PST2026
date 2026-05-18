#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

struct readings {
    float temp;
    float hum;
};

QueueHandle_t my_queue;

void read_data(void *pvParameters);
void display(void *pvParameters);

void setup() {

    Serial.begin(9600);

    dht.begin();

    my_queue = xQueueCreate(5, sizeof(struct readings));

    xTaskCreate(
        read_data,
        "read sensors",
        128,
        NULL,
        1,
        NULL
    );

    xTaskCreate(
        display,
        "display",
        128,
        NULL,
        1,
        NULL
    );

    vTaskStartScheduler();
}

void loop() {
}

void read_data(void *pvParameters) {

    struct readings x;

    while (1) {

        x.temp = dht.readTemperature();
        x.hum = dht.readHumidity();

        // Cek apakah pembacaan gagal
        if (isnan(x.temp) || isnan(x.hum)) {

            Serial.println("Gagal membaca sensor DHT");

        } else {

            xQueueSend(my_queue, &x, portMAX_DELAY);
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void display(void *pvParameters) {

    struct readings x;

    while (1) {

        if (xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) {

            Serial.print("Temperature : ");
            Serial.print(x.temp);
            Serial.println(" C");

            Serial.print("Humidity    : ");
            Serial.print(x.hum);
            Serial.println(" %");

            Serial.println("-------------------");
        }
    }
}
