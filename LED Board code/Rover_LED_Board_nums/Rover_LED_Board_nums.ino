int greenLED = A0;
int redLED = A1;
int blueLED = A2;
int leds[3] = {greenLED, redLED, blueLED};

void setup() 
{
  Serial.begin(115200);
  Serial.println("Welcome to the Serial Monitor!");
  Serial.println("---------------------------------");

  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
}

// green: 1
// red: 2
// blue: 3
// off: 0

void loop() 
{
  while (Serial.available() == 0) {}

  int value = Serial.parseInt();
  
  if (value == 2) {
    ledsOff();
    digitalWrite(leds[1], HIGH);
    digitalWrite(11, HIGH);
    Serial.read();
  }
  else if (value == 3) {
    ledsOff();
    digitalWrite(leds[2], HIGH);
    digitalWrite(12, HIGH);
    Serial.read();
  }
  else if (value == 1) {
    ledsOff();
    digitalWrite(leds[0], HIGH);
    digitalWrite(13, HIGH);
    Serial.read();
//    do {
//      blinkGreen();
//    } while (Serial.available() == 0);
  }
  else if (value == 0) {
    ledsOff();
  }
  else {
    Serial.println("Invalid Input");
    Serial.read();
  }

  Serial.println(value);
}

void ledsOff() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
    }
  digitalWrite(2, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
}

void blinkGreen() {
  digitalWrite(leds[0], HIGH);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(leds[0], LOW);
  digitalWrite(2, LOW);
  delay(500);
}
