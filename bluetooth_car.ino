char receivedChar;

void setup() {
  pinMode(13, OUTPUT);   // Left motors forward
  pinMode(12, OUTPUT);   // Left motors reverse
  pinMode(11, OUTPUT);   // Right motors forward
  pinMode(10, OUTPUT);   // Right motors reverse
  pinMode(9, OUTPUT);    // LED
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    receivedChar = Serial.read();
    Serial.println(receivedChar);
  }

  if (receivedChar == 'F') {  // Move forward (all motors rotate in forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  } 
  else if (receivedChar == 'B') {  // Move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  } 
  else if (receivedChar == 'L') {  // Turn right (left side motors rotate in forward direction, right side motors don't rotate)
    digitalWrite(11, HIGH);
  } 
  else if (receivedChar == 'R') {  // Turn left (right side motors rotate in forward direction, left side motors don't rotate)
    digitalWrite(13, HIGH);
  } 
  else if (receivedChar == 'W') {  // Turn LED on
    digitalWrite(9, HIGH);
  } 
  else if (receivedChar == 'w') {  // Turn LED off
    digitalWrite(9, LOW);
  } 
  else if (receivedChar == 'S') {  // STOP (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  delay(100);
}
