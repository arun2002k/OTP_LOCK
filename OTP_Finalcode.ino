
#include <Servo.h>
String dicid;
String pwd;
String letters[6] = {"adv", "fdfdb", "fdfc", "fdfd", "efdf", "fmbff"};
String otpp = "";
String numbers[4]={"3213", "213213", "9999", "543646"};
int sled1=12;
int sled2=13;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9); 
pinMode(sled1,1);
pinMode(sled2,1);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available()==0);
dicid=Serial.readStringUntil('\n');
if (dicid== "asdfg"){
  otp();
  digitalWrite(sled1,1);
}
check();

}

void otp(){
    otpp =  letters[random(0, 6)] + numbers [random(0, 4)] ;
  Serial.println(otpp+"\n");
 
}
void check(){
  while (Serial.available()==0);
 pwd=Serial.readStringUntil('\n'); 
 
if (pwd == otpp ){
  Serial.println ("unlocked");
  myservo.write(120); 
  digitalWrite(sled2,1);
  digitalWrite(sled1,0);
}
if (pwd != otpp ){
  Serial.println ("reset try again");
  myservo.write(50); 
  digitalWrite(sled2,0);
  digitalWrite(sled1,1);
} 
}
