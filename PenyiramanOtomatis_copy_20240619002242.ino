// Moisture Sensor Arduino Code


//By Circuitdigest 


 


#define ledPin 6
#define sensorPin A0
#include <LiquidCrystal_r2C.h>
int pompa=7;

 


void setup() {


  Serial.begin(9600);


  pinMode(ledPin, OUTPUT);
  pinMode(pompa, OUTPUT);

  digitalWrite(ledPin, LOW);


}


 


void loop() {


  Serial.print("Analog output: ");


  


  delay(2000);
  int sv = analogRead(A0);
  Serial.println(sv);
  if((sv>400)&&(sv<1023)) {
    digitalWrite(pompa,LOW);
  }
  if((sv>100)&&(sv<400)) {
    digitalWrite(pompa,HIGH);
  }


}


 


//  This function returns the analog data to calling function


int readSensor() {


  int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor


  int outputValue = map(sensorValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data


  analogWrite(ledPin, outputValue); // generate PWM signal


  return outputValue;             // Return analog moisture value


}
