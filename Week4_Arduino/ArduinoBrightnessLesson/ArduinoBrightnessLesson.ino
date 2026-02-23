int v = 0; //0-255

//PWN = pulse with modulation
//aka turning power on and off very fast to fake brightness
//pin 13 is not a PWM pin so we fake it with timing
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    v = Serial.read(); //0-255
    Serial.print("Arduino Receved: ");
    Serial.println(v);
  }

  //software PWM on pin 13
  //turn LED on
  digitalWrite(13, HIGH);
  //wait sometime
  //if v = 255-> LED stays on longer
  //if v = 50-> LED stays on shorter
  delayMicroseconds(v * 10); //on time
  //turn LED off
  digitalWrite(13, LOW);
  //wait remaining time
  delayMicroseconds((255 - v) * 10); //off time

}
