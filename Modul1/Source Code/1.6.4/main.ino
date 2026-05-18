int timer = 500;

// LED kiri
int kiri[] = {2, 3, 4};

// LED kanan
int kanan[] = {5, 6, 7};

void setup()
{
  // Inisialisasi LED kiri
  for (int i = 0; i < 3; i++) {
    pinMode(kiri[i], OUTPUT);
  }

  // Inisialisasi LED kanan
  for (int i = 0; i < 3; i++) {
    pinMode(kanan[i], OUTPUT);
  }
}

void loop()
{
  // Menyalakan LED kiri
  for (int i = 0; i < 3; i++) {
    digitalWrite(kiri[i], HIGH);
    digitalWrite(kanan[i], LOW);
  }

  delay(timer);

  // Menyalakan LED kanan
  for (int i = 0; i < 3; i++) {
    digitalWrite(kiri[i], LOW);
    digitalWrite(kanan[i], HIGH);
  }

  delay(timer);
}
