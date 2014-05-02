//#include <SoftwareServo.h>
#include <Servo.h> 

const int ledPin = 13; // the pin that the LED is attached to


// ==================== Engine
#define MRDf 11   
#define MRDb 12     
#define MLDf 9   //9  
#define MLDb 10
// ====================


// ==================== Head
Servo Head;
unsigned char HeadCurrent=90; 
unsigned char HeadTrigersCount=3;
#define HeadForward 90   // Position for head forward
#define HeadRight 130   // Position for head right
#define HeadLeft 50   // Position for head left
// ====================


// ==================== Sonic
#define ECHOPIN 3                
#define TRIGPIN 4 
// ====================


// ==================== Light
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
// ====================


// ==================== Trigers
long TimerTriger1=0;						// for stoping
long TimerTriger2=0;
long TimerTriger3=0;
long TimerTriger4=0;
long TimerTriger5=0;
unsigned long currentMillis;
bool priorityMoving=false;

#define EngineTimeTurn 1500 
#define EngineTimeTurnFull 3000 
#define EngineTimeBack 3000 
// ==================== Light
		
	  
// ==================== Read Serial 
char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
// ==================== 

bool DEBUG=true;   


void setup() {
  // initialize serial communication:
  Serial1.begin(9600);
  Serial.println("Begin config");
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT); 
      
  pinMode(MRDf, OUTPUT);
  pinMode(MRDb, OUTPUT);  
  pinMode(MLDf, OUTPUT);
  pinMode(MLDb, OUTPUT);  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);     
  
  Head.attach(2); 
    
  HeadMoving(HeadCurrent);
}

void loop() {
  digitalWrite(ledPin, LOW);
  CheckTrigers();

   // see if there's incoming serial data:
   if (Serial1.available()) 
   {          
     digitalWrite(ledPin, HIGH);
     int firstChar = Serial1.read();
     if (firstChar == 59) 
     { //send a ; before your string as a start byte     
        delay(100);
        Serial.write("Command started");        
        
        GetString();
        
        if (Compare("Ping")==0) {
          Serial.println("Ping");
          Serial1.println(1);
        }
        else if (Compare("MoveForvard")==0) {
          Serial.println("MoveForvard");
          MoveForvard();
        }
        else if (Compare("MoveBack")==0) {
          Serial.println("MoveBack");
          MoveBack();
        }
        else if (Compare("MoveRight")==0) {
          Serial.println("MoveRight");
          MoveRight();
        }
        else if (Compare("MoveLeft")==0) {
          Serial.println("MoveLeft");
          MoveLeft();
        }      
        else if (Compare("MoveRightTurn")==0) {
          Serial.println("MoveRightTurn");
          MoveRightTurn();
        }  
        else if (Compare("MoveLeftTurn")==0) {
          Serial.println("MoveLeftTurn");
          MoveLeftTurn();
        }  
        else if (Compare("MoveFullTurnLeft")==0) {
          Serial.println("MoveFullTurnLeft");
          MoveFullTurnLeft();
        }  
        else if (Compare("MoveFullTurnRight")==0) {
          Serial.println("MoveFullTurnRight");
          MoveFullTurnRight();
        } 
        else if (Compare("MoveStop")==0) {
          Serial.println("MoveStop");
          MoveStop();
        }
        else if (Compare("HeadMoveF")==0) {
          Serial.println("HeadMoveF");
          HeadMoving(HeadForward); 
        }
        else if (Compare("HeadMoveR")==0) {
          Serial.println("HeadMoveR");
          HeadMoving(HeadRight); 
        }
        else if (Compare("HeadMoveL")==0) {
          Serial.println("HeadMoveR");
          HeadMoving(HeadLeft); 
        }
        else if (Compare("HeadPing")==0) {
          Serial.println("HeadPing");
          int distance = CheckDistance();          
          Serial1.println(distance);
          Serial.println(distance);
        }
        else if (Compare("HeadPingF")==0) {
          Serial.println("HeadPingF");
          HeadMoving(HeadForward); 
          int distance = CheckDistance();          
          Serial1.println(distance);
          Serial.println(distance);
        } 
        else if (Compare("HeadPingR")==0) {
          Serial.println("HeadPingR");
          HeadMoving(HeadRight); 
          int distance = CheckDistance();          
          Serial1.println(distance);
          Serial.println(distance);
        }         
        else if (Compare("HeadPingL")==0) {
          Serial.println("HeadPingL");
          HeadMoving(HeadLeft); 
          int distance = CheckDistance();          
          Serial1.println(distance);
          Serial.println(distance);
        } 
        else if (Compare("HeadLight")==0) {
          Serial.println("HeadLight");
          CheckLight();
          int light = CheckLight();
          Serial1.println(light);
          Serial.println(light);
        }
        
        
     }
        
   }
}   
        
 void TestHeadMoving()
{
  Serial.println("Test head moving");
  HeadMoving(90); 
  TestHeadPing();
  CheckLight();
  delay(20); 
  HeadMoving(40);
  TestHeadPing();
  CheckLight();
  delay(20);  
  HeadMoving(140); 
  TestHeadPing();
  CheckLight();
  delay(20); 
  HeadMoving(90); 
  TestHeadPing();
  CheckLight();
  delay(20); 

  delay(1000); 
}
 
 
 void TestHeadPing()
{
  int distance = CheckDistance();
  Serial.println(distance);
  delay(1000); 
}
        
