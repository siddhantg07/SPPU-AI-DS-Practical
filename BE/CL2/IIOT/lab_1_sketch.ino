// Program code for sending alert message

// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6)
const int potPin = 34;

// Variable for storing the potentiometer value
int potValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);
  
  // Check if potentiometer value exceeds threshold
  if (potValue > 2000) {
    Serial.println("Warning");
  }
  
  Serial.println(potValue);
  delay(500);
}


// Optional Code -------------------------------------------------------------


// const int sensorPin = 34;  // GPIO 34 (for ESP32)
// int sensorValue = 0;

// const int upperThreshold = 2000;
// const int lowerThreshold = 500;

// void setup() {
//   Serial.begin(115200);
//   delay(1000);
//   Serial.println("System initialized...");
// }

// void loop() {
//   sensorValue = analogRead(sensorPin);

//   if (sensorValue > upperThreshold) {
//     Serial.println("ALERT: Sensor value too high!");
//   }
//   else if (sensorValue < lowerThreshold) {
//     Serial.println("ALERT: Sensor value too low!");
//   }

//   Serial.print("Current sensor value: ");
//   Serial.println(sensorValue);

//   delay(500);
// }
