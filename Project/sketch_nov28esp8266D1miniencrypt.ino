
/*Configured for the (gpio) pinout of esp8266 D1 mini (clone) (need a pulldown registor in D0 to use with sd card module). 
Arduino uno pinout is shown below*/

#define in1 11 // switch1
#define in2 10 // switch2
#define in3 9 // switch3
#define in4 8 // switch4

#define out1 5  //led1
#define out2 4  //led2
#define out3 3  //led3
#define out4 2 //led4

boolean val1 = false;      // variable to store the read value
boolean val2 = false;      // variable to store the read value
boolean val3 = false;      // variable to store the read value
boolean val4 = false;      // variable to store the read value

void setup() {
  Serial.begin(9600);
  delay(500);
  /*
  pinMode(in1, INPUT_PULLUP);
  pinMode(in2, INPUT_PULLUP);
  pinMode(in3, INPUT_PULLUP);
  pinMode(in4, INPUT_PULLUP);
  
  pinMode(out1, INPUT_PULLUP);
  pinMode(out2, INPUT_PULLUP);
  pinMode(out3, INPUT_PULLUP);
  pinMode(out4, INPUT_PULLUP);
  */
  pinMode(out1, OUTPUT);  // sets the digital pin 5 as output of arduino uno
  pinMode(out2, OUTPUT);  // sets the digital pin 4 as output of arduino uno
  pinMode(out3, OUTPUT);  // sets the digital pin 3 as output of arduino uno
  pinMode(out4, OUTPUT);  // sets the digital pin 2 as output of arduino uno
  
  pinMode(in4, INPUT);    // sets the digital pin 11 as input of arduino uno
  pinMode(in3, INPUT);    // sets the digital pin 10 as input of arduino uno
  pinMode(in2, INPUT);    // sets the digital pin 9 as input of arduino uno
  pinMode(in1, INPUT);    // sets the digital pin 8 as input of arduino uno

  digitalWrite(out4, LOW);  
  digitalWrite(out3, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out1, LOW);
  /*
  digitalWrite(in1, LOW);  
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  */
  delay(500);
}

void loop() {
          /*Boolean Function Implementation*/
  
  val1 = (!digitalRead(in3)*!digitalRead(in4))+
         (digitalRead(in1)*digitalRead(in2)*!digitalRead(in3))+
         (!digitalRead(in1)*!digitalRead(in2)*!digitalRead(in3))+        
         (digitalRead(in1)*!digitalRead(in2)*!digitalRead(in4))+
         (!digitalRead(in1)*digitalRead(in3)*digitalRead(in4));
  
  val2 = (digitalRead(in1)*digitalRead(in2))+
         (digitalRead(in1)*!digitalRead(in4))+
         (!digitalRead(in2)*digitalRead(in3)*digitalRead(in4));
         
  val3 = (digitalRead(in1)*!digitalRead(in2)*digitalRead(in4))+
         (!digitalRead(in1)*!digitalRead(in3)*!digitalRead(in4))+
         (digitalRead(in1)*digitalRead(in2)*digitalRead(in3)*!digitalRead(in4));
         
  val4 = (digitalRead(in1)*digitalRead(in2)*!digitalRead(in3))+
         (digitalRead(in1)*!digitalRead(in2)*digitalRead(in3))+
         (!digitalRead(in1)*digitalRead(in2)*digitalRead(in3))+
         (digitalRead(in2)*!digitalRead(in3)*digitalRead(in4))+
         (!digitalRead(in2)*!digitalRead(in3)*!digitalRead(in4));
  
  /* sets the LED to the button's value*/
  digitalWrite(out4, val1);
  delay(10);  
  digitalWrite(out3, val2);
  delay(10);
  digitalWrite(out2, val3);
  delay(10);
  digitalWrite(out1, val4);
  delay(10);
}
