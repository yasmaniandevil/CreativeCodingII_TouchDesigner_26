
int b = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0){
    b = Serial.read();
    Serial.println(b);
    digitalWrite(13, b == 1 ? HIGH : LOW);
  }

}
