// ---------- Déclaration des pins ----------
int sensorPin = A0;    // LM35 connecté à A0
int ledPin = 13;       // LED connectée à D13
int buzzerPin = 12;    // Buzzer connecté à D12 (optionnel)

// ---------- Variables ----------
float temperature;     

void setup() {
  Serial.begin(9600);       // Pour afficher sur le moniteur série
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Lire la valeur analogique du capteur
  int reading = analogRead(sensorPin);

  // Convertir la valeur en température (en °C)
  temperature = (reading * 5.0 * 100.0) / 1024.0;

  // Afficher la température
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Condition : si température > 30°C
  if (temperature > 30) {
    digitalWrite(ledPin, HIGH);    // Allume LED
    digitalWrite(buzzerPin, HIGH); // Active buzzer
  } else {
    digitalWrite(ledPin, LOW);     // Éteint LED
    digitalWrite(buzzerPin, LOW);  // Éteint buzzer
  }

  delay(1000); // Actualiser chaque seconde
}