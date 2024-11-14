#include<LiquidCrystal.h>

// Pin for the buzzer
unsigned long previousMillis = 0;  // Stores the last time the buzzer was activated
const long interval = 500;  // Interval for buzzer tone (in milliseconds)


#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define UP_THRESHOLD    400
#define DOWN_THRESHOLD  800

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08

int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis
int command = COMMAND_NO;


int redLED = 6;
int blueLED = 5;
int yellowLED = 4;
int greenLED = 3;

LiquidCrystal lcd(7, 8, 9, 10,11,12);


String regionString = "REGION1";

void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600) ;
}


void loop() {

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // converts the analog value to commands
  // reset commands
  command = COMMAND_NO;

  // check left/right commands
  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;

  // check up/down commands
  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  // NOTE: AT A TIME, THERE MAY BE NO COMMAND, ONE COMMAND OR TWO COMMANDS

  // print command to serial and process command
  if (command & COMMAND_LEFT) {
    Serial.println("LEFT");
    // TODO: add your task here
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("RIGHT");
    // TODO: add your task here
  }

  if (command & COMMAND_UP) {
    Serial.println("UP");
    // TODO: add your task here
  }

  if (command & COMMAND_DOWN) {
    Serial.println("DOWN");
    // TODO: add your task here
  }
  // Check the serial message received from unity.
  switch (Serial.read())
  {
      case '1': 
          // Turn off all LEDs when stopping the system;
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
        digitalWrite(blueLED, LOW);
        regionString = "REGION 1";
        break;
      case '2':
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(redLED, LOW);
        digitalWrite(blueLED, LOW);
        regionString = "REGION 2";
        break;
      case '3':
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
        digitalWrite(blueLED, HIGH);
        regionString = "REGION 3";
        break;
      case '4':
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, HIGH);
        digitalWrite(blueLED, LOW);
        regionString = "REGION 4";
        break;
  }
  lcd.setCursor(0,0);
  lcd.print(regionString);
}

// void triggerBuzzer(int region)
// {
// 	// Alto Do (523Hz), Re (587Hz), Mi (659Hz), Fa (698Hz),
// 	// (784Hz), La (880Hz), Si (988Hz) and Treble Do (1047Hz).
// 	int notes[] = {523, 587, 659, 698, 784, 880, 988, 1047};
// 	int notes2[] = {500, 500, 500, 500, 500, 500, 500, 500};


// 	for (int i = 0; i < 8; i++) {
//       unsigned long currentMillis = millis();

//     // Check if the time has elapsed (interval has passed)
//     if (currentMillis - previousMillis >= interval) {
//       if (region == 1)
//         tone(buzzerPin, notes[i]);	// Play the note
//       else
//         tone(buzzerPin, notes2[i]);	// Play the note
//       previousMillis = currentMillis;
//       noTone(buzzerPin);        	// Stop the tone
//     }
//     else
//      i--;
// 	}
    
// }
