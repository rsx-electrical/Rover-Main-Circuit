//Wokwi Serial terminal simulation - Wokwi Arduino Simulator
//D13, D12, D11 (big)
//D2, 3, 4 (small)

int bigGreenLED = 13;
int bigRedLED = 12;
int bigBlueLED = 11;
int smallBlueLED = 2;
int smallGreenLED = 3;
int smallRedLED = 4;

String command;
String commands[4] = {"red\n", "blue\n", "green\n", "off\n"};

void setup() 
{
  Serial.begin(115200);
  Serial.println("Welcome to the Serial Monitor!");
  Serial.println("---------------------------------");

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

// green: 1
// red: 2
// blue: 3
// off: 0

void loop() 
{
  while (Serial.available() == 0) {}

  command = Serial.readString();

//  int value = Serial.parseInt();
  
  if (command.equals(commands[0])) {
    ledsOff();
    digitalWrite(smallRedLED, HIGH);
    digitalWrite(bigRedLED, HIGH);
    Serial.read();
  }
  else if (command.equals(commands[1])) {
    ledsOff();
    digitalWrite(smallBlueLED, HIGH);
    digitalWrite(bigBlueLED, HIGH);
    Serial.read();
  }
  else if (command.equals(commands[2])) {
    ledsOff();
    Serial.read();
    do {
      blinkGreen();
    } while (Serial.available() == 0);
  }
  else if (command.equals(commands[3])) {
    ledsOff();
  }
  else {
    Serial.println("Invalid Input");
    Serial.read();
  }

  Serial.println(command);
}

void ledsOff() {
  digitalWrite(smallGreenLED, LOW);
  digitalWrite(smallRedLED, LOW);
  digitalWrite(smallBlueLED, LOW);
  digitalWrite(bigBlueLED, LOW);
  digitalWrite(bigRedLED, LOW);
  digitalWrite(bigGreenLED, LOW);
}

void blinkGreen() {
  digitalWrite(smallGreenLED, HIGH);
  digitalWrite(bigGreenLED, HIGH);
  delay(500);
  digitalWrite(smallGreenLED, LOW);
  digitalWrite(bigGreenLED, LOW);
  delay(500);
}

/////////////////////////

/*
int greenLED = A0;
int redLED = A1;
int blueLED = A2;
int leds[3] = {greenLED, redLED, blueLED}; //red = 6, 
String command;
String commands[4] = {"red\n", "blue\n", "green\n", "off\n"};

void setup() 
{
  Serial.begin(115200);
  Serial.println("Welcome to the Serial Monitor!");
  Serial.println("---------------------------------");

  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(2, OUTPUT); // 
  pinMode(6, OUTPUT); // red
  pinMode(10, OUTPUT); //
}

// green: 1
// red: 2
// blue: 3
// off: 0

void loop() 
{
  while (Serial.available() == 0) {}

  command = Serial.readString();

//  int value = Serial.parseInt();
  
  if (command.equals(commands[0])) {
    ledsOff();
    digitalWrite(leds[1], HIGH);
    digitalWrite(6, HIGH);
    Serial.read();
  }
  else if (command.equals(commands[1])) {
    ledsOff();
    digitalWrite(leds[2], HIGH);
    digitalWrite(10, HIGH);
    Serial.read();
  }
  else if (command.equals(commands[2])) {
    ledsOff();
    Serial.read();
    do {
      blinkGreen();
    } while (Serial.available() == 0);
  }
  else if (command.equals(commands[3])) {
    ledsOff();
  }
  else {
    Serial.println("Invalid Input");
    Serial.read();
  }

  Serial.println(command);
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
*/
