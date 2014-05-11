/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Mega 2560 or Mega ADK, Platform=avr, Package=arduino
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __AVR_ATmega2560__
#define ARDUINO 105
#define ARDUINO_MAIN
#define __AVR__
#define __avr__
#define F_CPU 16000000L
#define __cplusplus
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define __attribute__(x)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int
            
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
//
void configureMusic();
void BrainLoop();
void Brain();
void BrainMov();
void BrainMovBre(boolean danger);
void BrainMoveCarefullLeLeft();
void BrainMoveCarefullLeRight();
void BrainMovBreAnalize(boolean enclosed);
void BrainMovBreTurn();
int HeadLight();
int HeadPing();
int HeadPingF();
int HeadPingR();
int HeadPingL();
void MoveForvard();
void MoveBack();
void MoveRight();
void MoveLeft();
void MoveRightTurn();
void MoveLeftTurn();
void MoveFullTurnLeft();
void MoveFullTurnRight();
void MoveStop();
void HeadMoveF();
void HeadMoveR();
void HeadMoveL();
void BotOnPauseOnOff();
void EnableWifiModeOnOff();
void EnableBrainModeOnOff();
void MusicVolumeIncrease();
void MusicVolumeDecrease();
void MusicOnOff();
int CheckLight();
int CheckDistance();
boolean CheckMotion();
void playcomplete(char *name);
void playfile(char *name);
void playFileNoPriority(char *name);
void CheckAndPlayNextMusicInLine();
void AddMusicToLine(char* name);
void SleepStart();
void SleepEnd();
void ConfigureRnd();
void CleanSerial();
String FindCommandFromWifi();
String GetCommandFromString(String workZone);
String FindCommandFromIr(unsigned long command);
boolean ExecuteCommand(String command);
char Compare(char* This, String command);
void PrintText(String text);
void Test();
void TestMusic();
void TestLight();
void TestPing();
void TestPingWithAction();
void TestEngine();
void TestHeadMoving();
void printWifiStatus();
void ConnectToSite();
void ConnectToWifi();
String ReadDataFromWifi();
void sendResponse(String response);

#include "F:\Program Files My\Arduino\arduino-1.0.5\hardware\arduino\cores\arduino\arduino.h"
#include "F:\Program Files My\Arduino\arduino-1.0.5\hardware\arduino\variants\mega\pins_arduino.h" 
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\ControllerPrimary.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\BrainLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\CallSlaveServices.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\ComandLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\EnvironmentLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\IrControllerMapping.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\MusicMethods.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\SleepLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\SystemLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\TestMethods.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerPrimary\WifiLogic.ino"
#endif
