// membuat variable konstanta bernama PIN_LED untuk pin nomor 12
const int PIN_LED = 12;

// kondisi untuk mode lampu berkedip
bool modeBlink = false;
// menyimpan detik terbaru
unsigned long previousMillis = 0;
// interval kedip yang dipake, setengah detil
const long interval = 500;
// status LED
int ledState = LOW;

void setup() {
  Serial.begin(9600);
  Serial.println("Ketik '1' untuk menyalakan LED, '0' untuk mematikan LED"); 
  pinMode (PIN_LED, OUTPUT);
}

void blink(){
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
  delay(500);
}


void loop() {
  if (Serial.available() > 0) {
  char data = Serial.read();

    if (data == '1') {
      modeBlink = false;
    digitalWrite (PIN_LED, HIGH);
    Serial.println("LED ON");
    }
    else if (data == '0') {
      modeBlink = false;
      digitalWrite (PIN_LED, LOW);
      Serial.println("LED OFF");
    }
    //menambah logika/pengkondisian tambahan
    else if (data == '2') {
      modeBlink = true;
      // blink();
      Serial.println("LED BLINK!");
    }
    else if (data != '\n' && data != '\r') {
    // Hanya muncul jika bukan 1, 0, atau ENTER
    Serial.println("Perintah tidak dikenal");
    }
  }

  //Jika modeBlink  == true, dinyalakan dengan  menginput 2, jalankan code ini
  if (modeBlink) {
    // ambil detik terbaru
    unsigned long currentMillis = millis();
    // jika detik terbaru - detik sebelumnya lebih besar dari 500 maka  lakukan code dibawah
    if (currentMillis - previousMillis >= interval) {
      //simpan detik terbaru ke variable previousMillis
      previousMillis = currentMillis;

      //balikan keadaan lampu
      ledState = !ledState;
      //tulis ke pin
      digitalWrite(PIN_LED, ledState);
    }
  }
}
