#include <LiquidCrystal.h>
#include <Keypad.h>

const byte num_rows = 4; 
const byte num_cols = 4; 

// Define keypad layout
char keyLayout[num_rows][num_cols] = {
  {'7','8','9','D'},
  {'4','5','6','C'},
  {'1','2','3','B'},
  {'*','0','#','A'}
};

byte rowConnections[num_rows] = { 0, 1, 2, 3 };
byte colConnections[num_cols] = { 4, 5, 6, 7 };

// Initialize keypad
Keypad customKeypad = Keypad( makeKeymap(keyLayout), rowConnections, colConnections, num_rows, num_cols );

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; // LCD connections
LiquidCrystal display(rs, en, d4, d5, d6, d7);

long firstNum, secondNum, resultNum;
char keyPressed, operation;
bool shouldCalculate = false;

void setup() {
  display.begin(16, 2);
  display.print("Custom Calculator");
  display.setCursor(0, 1);
  display.print("-TechSavvy");

  delay(2000);
  display.clear();
}

void loop() {
 
  keyPressed = customKeypad.getKey();

  if (keyPressed != NO_KEY)
    processKey();

  if (shouldCalculate)
    computeResult();

  showResult();   
}

void processKey() {
  display.clear();

  if (keyPressed == '*') {
    Serial.println("Clear pressed");
    resultNum = firstNum = secondNum = 0;
    shouldCalculate = false;
  }

  if (keyPressed >= '0' && keyPressed <= '9') {
    Serial.print("Button "); Serial.println(keyPressed);
    if (resultNum == 0)
      resultNum = keyPressed - '0';
    else
      resultNum = (resultNum * 10) + (keyPressed - '0');
  }

  if (keyPressed == '#') {
    Serial.println("Equals pressed");
    secondNum = resultNum;
    shouldCalculate = true;
  }

  if (keyPressed >= 'A' && keyPressed <= 'D') {
    firstNum = resultNum;    
    resultNum = 0;
    if (keyPressed == 'A') {
      Serial.println("Add");
      operation = '+';
    }
    if (keyPressed == 'B') {
      Serial.println("Subtract");
      operation = '-';
    }
    if (keyPressed == 'C') {
      Serial.println("Multiply");
      operation = '*';
    }
    if (keyPressed == 'D') {
      Serial.println("Divide");
      operation = '/';
    }
    delay(100);
  }
}

void computeResult() {
  if (operation == '+')
    resultNum = firstNum + secondNum;

  if (operation == '-')
    resultNum = firstNum - secondNum;

  if (operation == '*')
    resultNum = firstNum * secondNum;

  if (operation == '/')
    resultNum = firstNum / secondNum; 
}

void showResult() {
  display.setCursor(0, 0);
  display.print(firstNum); display.print(operation); display.print(secondNum);

  if (shouldCalculate) {
    display.print(" ="); display.print(resultNum);
  }
 
  display.setCursor(0, 1);
  display.print(resultNum);
}
