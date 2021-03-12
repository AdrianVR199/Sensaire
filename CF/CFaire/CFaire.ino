#define aire    2
#define temperatura    A1
#define beeper    3
int gasLevel = 0;
float temp;
String quality = "";

void setup() {
  Serial.begin(9600);
  pinMode(aire, INPUT);
  pinMode(temperatura, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(beeper, OUTPUT);
}

void loop() {
  gasLevel = analogRead(aire);
  temp = analogRead(temperatura);
  if (gasLevel < 150) {
    quality = "Bueno";
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if (gasLevel > 150 && gasLevel < 175) {
    quality = "Regular";
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if (gasLevel > 175 && gasLevel < 300) {
    quality = "Malo";
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (gasLevel > 300) {
    quality = "TOXICO";
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    tone(beeper, 120);
    delay(1000);
    noTone(beeper);
  }
  temp = ((temp * 5000.0) / 1023) / 10;
  Serial.println("Aire : " + quality + " || " + temp + " C");
  delay(3000);
}
