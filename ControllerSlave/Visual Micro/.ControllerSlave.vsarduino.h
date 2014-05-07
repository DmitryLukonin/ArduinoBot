/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Micro, Platform=avr, Package=arduino
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __AVR_ATmega32u4__
#define __AVR_ATmega32U4__
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
int CheckDistance();
long PingDistance();
int microsecondsToCentimeters(long microseconds);
void MoveStop();
void MoveForvard();
void MoveBack();
void MoveRight();
void MoveLeft();
void MoveRightTurn();
void MoveLeftTurn();
void MoveFullTurnLeft();
void MoveFullTurnRight();
void MRf();
void MRb();
void MLf();
void MLb();
int CheckLight();
char Compare(char* This, char* RecievedCommand);
int readline(int readch, char *buffer, int len);
void HeadMoving(int value);
void CheckTrigers();
void ConfigureRnd();
void ConfigureTriger(unsigned char TrigerId, unsigned long TrigerStopTime);
unsigned long GetStopTimeForTriger(unsigned long TrigerStopTime);
void TestHeadMoving();
void TestHeadPing();

#include "F:\Program Files My\Arduino\arduino-1.0.5\hardware\arduino\cores\arduino\arduino.h"
#include "F:\Program Files My\Arduino\arduino-1.0.5\hardware\arduino\variants\micro\pins_arduino.h" 
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\ControllerSlave.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\DistanceLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\EngineLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\LightLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\SerialParcer.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\ServoLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\SystemLogic.ino"
#include "F:\Users\Demon\Documents\Visual Studio 2013\Projects\ArduinoBot\ControllerSlave\Test.ino"
#endif
