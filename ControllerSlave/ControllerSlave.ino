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
#define HeadRight 120   // Position for head right
#define HeadLeft 60   // Position for head left
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
long TimerTriger1=0;						// for returns head to initial position
long TimerTriger2=0;						// for engine moving
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
  Serial1.begin(9600);
  Serial.println("Begin config");
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
  

  static char buffer[80];
  if (readline(Serial1.read(), buffer, 80) > 0) {
	  if (Compare("Ping", buffer) == 0) {
		  Serial.println("Ping");
		  Serial1.println(1);
	  }
	  else if (Compare("MoveForvard", buffer) == 0) {
		  Serial.println("MoveForvard");
		  MoveForvard();
	  }
	  else if (Compare("MoveBack", buffer) == 0) {
		  Serial.println("MoveBack");
		  MoveBack();
	  }
	  else if (Compare("MoveRight", buffer) == 0) {
		  Serial.println("MoveRight");
		  MoveRight();
	  }
	  else if (Compare("MoveLeft", buffer) == 0) {
		  Serial.println("MoveLeft");
		  MoveLeft();
	  }
	  else if (Compare("MoveRightTurn", buffer) == 0) {
		  Serial.println("MoveRightTurn");
		  MoveRightTurn();
	  }
	  else if (Compare("MoveLeftTurn", buffer) == 0) {
		  Serial.println("MoveLeftTurn");
		  MoveLeftTurn();
	  }
	  else if (Compare("MoveFullTurnLeft", buffer) == 0) {
		  Serial.println("MoveFullTurnLeft");
		  MoveFullTurnLeft();
	  }
	  else if (Compare("MoveFullTurnRight", buffer) == 0) {
		  Serial.println("MoveFullTurnRight");
		  MoveFullTurnRight();
	  }
	  else if (Compare("MoveStop", buffer) == 0) {
		  Serial.println("MoveStop");
		  MoveStop();
	  }
	  else if (Compare("HeadMoveF", buffer) == 0) {
		  Serial.println("HeadMoveF");
		  HeadMoving(HeadForward);
	  }
	  else if (Compare("HeadMoveR", buffer) == 0) {
		  Serial.println("HeadMoveR");
		  HeadMoving(HeadRight);
	  }
	  else if (Compare("HeadMoveL", buffer) == 0) {
		  Serial.println("HeadMoveR");
		  HeadMoving(HeadLeft);
	  }
	  else if (Compare("HeadPing", buffer) == 0) {
		  Serial.println("HeadPing");
		  int distance = CheckDistance();
		  Serial1.println(distance);
		  Serial.println(distance);
	  }
	  else if (Compare("HeadPingF", buffer) == 0) {
		  Serial.println("HeadPingF");
		  HeadMoving(HeadForward);
		  int distance = CheckDistance();
		  Serial1.println(distance);
		  Serial.println(distance);
	  }
	  else if (Compare("HeadPingR", buffer) == 0) {
		  Serial.println("HeadPingR");
		  HeadMoving(HeadRight);
		  int distance = CheckDistance();
		  Serial1.println(distance);
		  Serial.println(distance);
	  }
	  else if (Compare("HeadPingL", buffer) == 0) {
		  Serial.println("HeadPingL");
		  HeadMoving(HeadLeft);
		  int distance = CheckDistance();
		  Serial1.println(distance);
		  Serial.println(distance);
	  }
	  else if (Compare("HeadLight", buffer) == 0) {
		  Serial.println("HeadLight");
		  CheckLight();
		  int light = CheckLight();
		  Serial1.println(light);
		  Serial.println(light);
	  }
  }

  CheckTrigers();
}   
    