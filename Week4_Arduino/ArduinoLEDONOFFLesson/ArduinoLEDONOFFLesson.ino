int incomingByte = 0; //integer with variable starting it at 0
//we will be storing incoming data inside this variable

//in every coding language there is always a start method
void setup() {
  // put your setup code here, to run once:

  //pinMode means pin 13 will send electricity out
  //mode can be output-> send power
  //or input-> read sensors
  pinMode(13, OUTPUT); //onboard LED

  //starts communication over USB
  //9600 is communication speed
  //TD and arduino must match
  Serial.begin(9600);
  

}

// put your main code here, to run repeatedly:
void loop() {
  
  //built in ardunio function
  //means is data waitiing to be read?
  //returns the number of bytes available
  //so IF we have recieved something from touch designer
  if(Serial.available() > 0){
    //read the incoming byte send from TD
    //stores it in our var
    incomingByte = Serial.read(); //read one byte 0-255

    //if it is 1 then turn pin on
    if(incomingByte == 1) digitalWrite(13, HIGH);
    //if it is 0 then turn pin off (LED)
    if(incomingByte == 0) digitalWrite(13, LOW);

    
    //sends text back to TD used for debugging
    Serial.print("Arduino recieved: ");
    Serial.println(incomingByte);
  }

}
