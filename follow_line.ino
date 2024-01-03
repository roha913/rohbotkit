int rightMotorA = 8;   // Right motor pin A
int rightMotorB = 9;   // Right motor pin B
int leftMotorA = 10;   // Left motor pin A
int leftMotorB = 11;   // Left motor pin B
int rightSensor = 6;   // Right side sensor pin
int leftSensor = 7;    // Left side sensor pin
int rightSensorVal = 0;
int leftSensorVal = 0;
int indicatorLED = 13;
int rightMotorSpeed = 3;  
int leftMotorSpeed = 5;

int baseSpeed = 200;    
int turnSpeed = 300;
int turnDelay = 10;

void setup()
{
  pinMode(rightMotorA, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(leftMotorA, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(indicatorLED, OUTPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);

  delay(5000);  // Initial delay after power up
}

void loop()
{
  rightSensorVal = digitalRead(rightSensor);
  leftSensorVal = digitalRead(leftSensor);

  if (leftSensorVal == LOW && rightSensorVal == LOW)
  {
    moveForward();
  }
  else if (leftSensorVal == HIGH && rightSensorVal == LOW)
  {
    turnLeft();
  }
  else if (leftSensorVal == LOW && rightSensorVal == HIGH)
  {
    turnRight();
  }
  else
  {
    halt();  // Stop robot if both sensors detect a line
  }
}

void moveForward()
{
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(leftMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  analogWrite(rightMotorSpeed, baseSpeed);
  analogWrite(leftMotorSpeed, baseSpeed);
}

void moveBackward()
{
  digitalWrite(rightMotorA, LOW);
  digitalWrite(rightMotorB, HIGH);
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  analogWrite(rightMotorSpeed, baseSpeed);
  analogWrite(leftMotorSpeed, baseSpeed);
}

void turnRight()
{
  digitalWrite(rightMotorA, LOW);
  digitalWrite(rightMotorB, HIGH);
  digitalWrite(leftMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  analogWrite(rightMotorSpeed, turnSpeed);
  analogWrite(leftMotorSpeed, turnSpeed);
  delay(turnDelay);  // Short delay for turning
}

void turnLeft()
{
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  analogWrite(rightMotorSpeed, turnSpeed);
  analogWrite(leftMotorSpeed, turnSpeed);
  delay(turnDelay);  // Short delay for turning
}

void halt()
{
  analogWrite(rightMotorSpeed, 0);
  analogWrite(leftMotorSpeed, 0);
}

​