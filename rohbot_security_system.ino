#define triggerPin 8
#define receiverPin 9
#define redLED 10
#define yellowLED 11
#define greenLED 12
#define alarmBuzzer 13
int beepFrequency = 500;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(receiverPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(alarmBuzzer, OUTPUT);
}

void loop() {
  long pulseDuration, measuredDistance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pulseDuration = pulseIn(receiverPin, HIGH);
  measuredDistance = (pulseDuration / 2) / 29.1;

  if (measuredDistance < 50) {
    digitalWrite(greenLED, HIGH);
  } else {
    digitalWrite(greenLED, LOW);
  }

  if (measuredDistance < 20) {
    digitalWrite(yellowLED, HIGH);
  } else {
    digitalWrite(yellowLED, LOW);
  }

  if (measuredDistance < 5) {
    digitalWrite(redLED, HIGH);
    beepFrequency = 1000;
  } else {
    digitalWrite(redLED, LOW);
  }

  if (measuredDistance > 5 || measuredDistance <= 0) {
    Serial.println("Out of effective measurement range");
    noTone(alarmBuzzer);
  } else {
    Serial.print(measuredDistance);
    Serial.println(" cm");
    tone(alarmBuzzer, beepFrequency);
  }

  delay(500);
}