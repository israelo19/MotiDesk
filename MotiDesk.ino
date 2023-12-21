#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  const int trigPin = 8;
  const int echoPin  = 9;
  const int buzzer = 6;
  long dur;
  int distance;
  long duration;
int distanceCm, distanceInch;
char message1 = "Hi Welcome!";
char message2 = "The Sky is the Limit!";
char message3 = "Come back later!";
char message4 = "See you soon!";

void setup() {
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Starting...");
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

//--------------------------------------------------------------
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

if (distanceInch > 10.0) {

    lcd.clear();
    lcd.setCursor(0, 0);
 for(int i =0; i<16; i++){
   lcd.print("Come back later!");
    delay(500);

      lcd.scrollDisplayLeft();
      lcd.setCursor(0, 0);
 }
  } else {
    // Clear the LCD if the distance is not greater than 10 inches
    
    lcd.clear();
    lcd.setCursor(0,0);

   for(int i =0; i<16; i++){
    
    lcd.print("Sky is the limit!");
    delay(250);
    lcd.scrollDisplayLeft();
    lcd.setCursor(0,0);
  
  //this is the buzzer
   tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
 delay(1000);   
// it simulates music that will play
 

    delay(500);
  }

  delay(1000);

  }
}
