#include <LiquidCrystal.h>
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A0; // MQ135 sensor connected to A0 pin
int buzzerPin = 9; // Buzzer connected to pin 9
int fanPin = 8; // Exhaust fan connected to pin 8
void setup() { analogWrite(6,Contrast);
lcd.begin(16, 2);
pinMode(buzzerPin, OUTPUT);
pinMode(fanPin, OUTPUT); // Set fan pin as output
Serial.begin(9600);}
void loop() {
float gasValue = analogRead(sensorPin); 
// Read gas value from sensor
Serial.print("Gas value: ");
Serial.println(gasValue); }
if (gasValue > 500) { 
// If gas value is above a certain threshold, turn on the 
buzzer and the fan
lcd.print("Leakage detected");
digitalWrite(buzzerPin, HIGH);
digitalWrite(fanPin, HIGH);
lcd.setCursor(0, 0);
} else{
digitalWrite(buzzerPin, LOW);
digitalWrite(fanPin, LOW); // Turn off the fan if gas 
value is below the threshold
lcd.setCursor(0, 0);
lcd.print("No Leakage detected");}
delay(1000); //Wait for 1 second before taking another 
reading }
