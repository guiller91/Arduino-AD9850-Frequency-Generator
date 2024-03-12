#define W_CLK_PIN   8 // Word clock pin
#define FQ_UD_PIN   9 // Frequency update pin
#define DATA_PIN    10 // Serial data pin
#define RESET_PIN   11 // Reset pin
#define POT_PIN     A0 // Potentiometer pin
#define LED_PIN     13 // LED pin

void setup() {
  pinMode(W_CLK_PIN, OUTPUT);
  pinMode(FQ_UD_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  resetAD9850(); // Reset AD9850
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  int potValue = analogRead(POT_PIN); // Read potentiometer value
  double frequency = map(potValue, 0, 1023, 800000, 20000000); // Map it to desired frequency range

  setFrequency(frequency); // Set frequency of AD9850
  
  digitalWrite(LED_PIN, HIGH); // Indicate frequency is being set
  delay(200); // Short delay to visualize LED blink
  digitalWrite(LED_PIN, LOW);
  
  Serial.println(frequency); // Print frequency to Serial Monitor for debugging
  delay(800); // Wait a bit before next read
}

void resetAD9850() {
  digitalWrite(RESET_PIN, HIGH);
  digitalWrite(W_CLK_PIN, HIGH);
  digitalWrite(FQ_UD_PIN, HIGH);
  delay(10);
  digitalWrite(RESET_PIN, LOW);
  digitalWrite(W_CLK_PIN, LOW);
  digitalWrite(FQ_UD_PIN, LOW);
  delay(10);
}

void setFrequency(double frequency) {
  const double REF_FREQ = 125000000.0; // Reference frequency of AD9850
  uint32_t freq = (uint32_t)((frequency * (pow(2, 32))) / REF_FREQ);

  for (int b = 0; b < 32; b++) {
    digitalWrite(DATA_PIN, (freq & (1 << b)) ? HIGH : LOW);
    pulseHigh(W_CLK_PIN);
  }

  // Final bit configuration: phase and power down bit
  // Set to 0 for normal operation
  for (int b = 0; b < 8; b++) {
    digitalWrite(DATA_PIN, LOW);
    pulseHigh(W_CLK_PIN);
  }

  pulseHigh(FQ_UD_PIN); // Update frequency
}

void pulseHigh(uint8_t pin) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}
