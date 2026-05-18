const int ledPin = 6; 
int timeDelay = 1000; 
bool batas = false;
void setup() { 
pinMode(ledPin, OUTPUT); 
} 
void loop() { 
// Nyalakan LED 
  digitalWrite(ledPin, HIGH); 
  delay(timeDelay); 
  // Matikan LED 
  digitalWrite(ledPin, LOW); 
  delay(timeDelay); 
  
  // Baru ubah delay (setelah 1 siklus kedip) 
  if (timeDelay >= 100){
    batas = false;
  	delay(3000);
    timeDelay=1000;
  }else if (timeDelay <= 100) { 
    batas = true;
    timeDelay += 100;   // reset ke awal 
  } else if (batas == false) { 
  timeDelay -= 100;   // percepatan bertahap 
  } else {
  	timeDelay += 100;
  }
} 
