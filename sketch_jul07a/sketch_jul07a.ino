void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int colors[3] = {128,128,128};
    if (digitalRead(2) == LOW) {
      setColors(&colors[0]);
      digitalWrite(13,LOW);
      setCol(colors[0], colors[1], colors[2]);
    }
}

void setColors(int *mycol) {
  int count = 0;
  do {
    int slide = analogRead(A3);
    digitalWrite(13, HIGH);
    slide = map(slide, 0, 1023, 0, 255);
    if (digitalRead(12) == HIGH) {
      count++;
      delay(500);
    }
    // red
    if (count == 0) {
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      mycol[0] = slide;
      analogWrite(9, slide);
    }
    // green
    if (count == 1) {
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
      mycol[1] = slide;
      analogWrite(10, slide);
    }
    // blue
    if (count == 2) {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      mycol[2] = slide;
      analogWrite(11, slide);
    }
    if (count > 2) {
      count = 0;
    }
  } while ( digitalRead(2) == LOW );
}


void setCol(int red, int green, int blue) {
  analogWrite(9, red);
  analogWrite(10, green);
  analogWrite(11, blue);
}


void randomLED() {
  int pin = random(4, 9);
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);

}
void readData() {
  int light = analogRead(1);
  int temp = analogRead(0);
  int sound = analogRead(2);
  int slide = analogRead(3);
  String foo = "{\"light\": " + String(light) + ", \"temp\": " + String(temp) +
               ", \"sound\": " + String(sound) + ", \"slide\": " + String(slide) + "}";
  Serial.println(foo);
  digitalWrite(13, HIGH);
  delay(slide);
  digitalWrite(13, LOW);


}
void randCol() {
  int red = random(0, 256);
  int green = random(0, 256);
  int blue = random(0, 256);
  analogWrite(9, red);
  analogWrite(10, green);
  analogWrite(11, blue);
}

void colSweep(int slide, int light) {
  int red = map(slide, 0, 1023, 0, 255);
  int green = map(light, 0, 1023, 0, 255);
  int blue = map(slide, 0, 1023, 0, 255);
  analogWrite(9, red);
  analogWrite(10, green);
  analogWrite(11, blue);
}


