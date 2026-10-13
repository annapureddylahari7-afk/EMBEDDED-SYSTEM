int sensorPin = 2;
int relayPin = 8;

int sensorState = 0;
int lastState = 0;
bool lightState = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  Serial.begin(9600);
}


void loop() {
  sensorState = digitalRead(sensorPin);

  // Detect hand gesture (change in state)
  if (sensorState == HIGH && lastState == LOW) {
    lightState = !lightState;  // Toggle light
    digitalWrite(relayPin, lightState ? HIGH : LOW);
    delay(500); // debounce delay
  }

  lastState = sensorState;
}