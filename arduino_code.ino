const int gasSensorPin = A0; // Analog input pin for gas sensor
const int ledPin = 13; // Digital output pin for LED
const int buzzerPin = 12; // Digital output pin for buzzer
const int relayPin = 11; // Digital output pin for relay

int gasThreshold = 500; // Set gas threshold value (adjust as needed)

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(relayPin, OUTPUT); // Set relay pin as output
  digitalWrite(relayPin, HIGH); // Set relay pin HIGH to turn off appliances
}

void loop() {
  int gasValue = analogRead(gasSensorPin); // Read gas sensor value
  Serial.print("Gas value: "); // Print gas value for debugging
  Serial.println(gasValue);

  if (gasValue > gasThreshold) { // If gas value exceeds threshold
    digitalWrite(ledPin, HIGH); // Turn on LED
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    digitalWrite(relayPin, LOW); // Turn off appliances
  } else { // If gas value is below threshold
    digitalWrite(ledPin, LOW); // Turn off LED
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
    digitalWrite(relayPin, HIGH); // Turn on appliances
  }

  delay(1000); // Delay 1 second before reading again
}
