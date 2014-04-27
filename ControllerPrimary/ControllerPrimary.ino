#include <SPI.h>
#include <WiFi.h>
#include <SD.h>                      // need to include the SD library
#include <TMRpcm.h> 

//#include "WaveHC.h"
//#include "WaveUtil.h"

// ==================== Control
int controlType=2; 			// 0 - fully automate, 1 - automate but check the command  2 - wifi manual only 
#define DEBUG 2       	    // 0 - no response, 1 - only usb, 2 - usb and wifi detailed, 3 - usb and wifi only by request (manual control)
#define KeepWifiActive 1 	// 0 - close connection, 1 - don't close	   
boolean WifiEnabled = true;
// ====================

// ==================== Wifi
char ssid[] = "Stix"; //  your network SSID (name) 
char pass[] = "ZxEYjnQRhE";    // your network password (use for WPA, or use as key for WEP)
int wifiStatus = WL_IDLE_STATUS;
int keyIndex = 0;            // your network key Index number (needed only for WEP)

//IPAddress server(192,168,0,107);  // numeric (no DNS)
//IPAddress server(96,31,35,129);  // numeric (no DNS)
char server[] = "www.icedock.net";
//int serverPort = 81;
int serverPort = 80;
int status = WL_IDLE_STATUS;
boolean lastConnected = false;   
WiFiClient client;

// ==================== Music 
TMRpcm tmrpcm;   // create an object for use in this sketch
#define musicVolume 2     
#define musicQuality 1 
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328

// time to play each tone in milliseconds
#define PLAY_TIME 200

// ==================== Breaks data
unsigned char DistanceToBreakLimit=26; // cm
bool priorityMoving=false;
short DistanceFront;
short DistanceLeft;
short DistanceRight;
short DistanceBack;

// ==================== Technical data
int ping;
int light;
bool sleep = false;
int oldSerialData;
boolean detectorWorks=true;
#define SleepLimitValue 9

// ==================== Time between commands
#define ServiceTimerFast 20
#define ServiceTimerSlow 2000 


void setup() {
   // initialize both serial ports:
   Serial.begin(9600);
   Serial1.begin(9600);
   
   
   tmrpcm.speakerPin = 11; //11 on Mega, 9 on Uno, Nano, etc
   if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
   }
   tmrpcm.setVolume(musicVolume);
   tmrpcm.quality(musicQuality);

   ConfigureRnd();  
   
   //Serial.print("Free RAM: ");       // This can help with debugging, running out of RAM is bad

   if(WifiEnabled)
   {
	ConnectToWifi();
	ConnectToSite();
   }
   
   Serial1.setTimeout(1500); 
   delay(1000);  
   
  // PrintText("Start self-test");
  // Test();
   PrintText("Self-test is completed. Going to live!");
}

void loop() 
{
	if(WifiEnabled) 
	{
		//if(CheckConnection())
		//{
			boolean command = FindAndExecuteCommandFromWifi();
			if(!command && controlType==1)
			{
				BrainLoop();
			}					
		//}		
		//else
		//{
		//	ConnectToWifi();
		//}
	}

	// looks bad. redo
	if(!WifiEnabled || controlType==1)
	{
//		BrainLoop();
	}
  
  
	//delay(100);  
}


void PrintText(String text)
{
	if(DEBUG>0) 
	{
		Serial.println(text);
		if(DEBUG>1 && WifiEnabled) {sendResponse(text); delay(100);}
	}	        
}
