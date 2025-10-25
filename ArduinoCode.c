int buzzer = 8;
char data;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == '1') {
      digitalWrite(buzzer, HIGH);  // Turn buzzer ON
    } else if (data == '0') {
      digitalWrite(buzzer, LOW);   // Turn buzzer OFF
    }
  }
}
