#include <SoftwareSerial.h>

// Pin assignments
const int pirPin = 2; // PIR sensor output pin
const int buzzerPin = 3; // Buzzer pin

// Custom RX and TX pins for the HC-06 Bluetooth module
SoftwareSerial bluetooth(10, 11); // RX, TX

// Variable to store PIR sensor state
int pirState = LOW; // Start with no motion detected

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize the Bluetooth communication on the custom pins
  bluetooth.begin(9600);

  // Set pin modes
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Print a startup message
  Serial.println("Motion Alarm System Initialized");
  bluetooth.println("System Ready...");
}

void loop() {
  // Read PIR sensor
  pirState = digitalRead(pirPin);

  // Show PIR sensor state in serial monitor
  Serial.print("PIR State: ");
  Serial.println(pirState);

  // Check if motion is detected
  if (pirState == HIGH) {
    // Send Bluetooth notification
    bluetooth.println("Detected!!! Motion Detected.");
    Serial.println("Motion Detected!");

    // Produce a "beep beep" sound with the buzzer
    for (int i = 0; i < 5; i++) { // Loop for 5 beeps
      digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
      delay(200); // Wait for 200ms
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(200); // Wait for 200ms before the next beep
    }
  } else {
    // Ensure the buzzer is off if no motion is detected
    digitalWrite(buzzerPin, LOW);
  }

  // Short delay before the next loop iteration
  delay(200);
}
