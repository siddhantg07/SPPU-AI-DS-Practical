// Write an Arduino/Raspberry pi program for interfacing with PIR Sensor
// PIR Sensor interfacing with Arduino
int pirPin = 2; // PIR sensor output pin
int ledPin = 13; // LED pin

void setup() {
pinMode(pirPin, INPUT); // Set PIR pin as input
pinMode(ledPin, OUTPUT); // Set LED pin as output

Serial.begin(9600); //Initialize serial communication for debugging
}
void loop() {
int motionState = digitalRead(pirPin); // Read PIR sensor state

if (motionState == HIGH) {
digitalWrite(ledPin, HIGH); // Turn on LED
Serial.println("Motion detected!");
delay(1000); // Delay for one second
} else {
digitalWrite(ledPin, LOW); // Turn off LED
Serial.println("No motion detected.");
}
}