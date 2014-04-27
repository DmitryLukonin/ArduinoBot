char Compare(char* This)
{             
                  if (strcmp(inData,This)  == 0) 
                  {
                    index=0;
                    char inData[20];
                    return(0);
                  }
                  else 
                  {
                    index=0;
                    char inData[20];
                    return(1);
                  }     
}



void GetString(){
    while (Serial1.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial1.read(); // Read a character
                        
            if (inChar == 59)  //send a ; before your string as a start byte 
            {
              String test(inData);
              Serial.print("whole data: ");
              Serial.println(test);
              return;
            }
            else
            {
              inData[index] = inChar; // Store it
              index++; // Increment where to write next
              inData[index] = '\0'; // Null terminate the string
            }
        }      
    }
}



 //       Serial.print("Number of bytes: ");
 //       Serial.println(Serial1.available());
 //       
 //       int firstChar = Serial1.read();
 //       Serial.print("firstChar: ");
 //       Serial.println(firstChar);
 //       
 //       delay(20);
 //       if (firstChar == 59) { //send a ; before your string as a start byte                                           
 //           
 //         int commandType = Serial1.read();
 //         delay(20);
 //         Serial.print("commandType: ");
 //         Serial.println(commandType);
           
           
           
 //          //digitalWrite(ledPin, HIGH);
           
 //          switch (commandType) 
 //          {
 //            case 76:    
 //              {                          
 //                int commandvalue=Serial.parseInt();
 //                Serial.print("commandvalue: ");
 //                Serial.println(commandvalue);
 //            
 //              if(commandvalue>0)
 //              {
 //              digitalWrite(ledPin, HIGH);
 //              }
 //              else
 //              {
 //                digitalWrite(ledPin, LOW);
 //              }  
 //              }             
 //              break;
 //            case 77:  
 //              Serial1.println("Go");
 //              break;
 //            default:          
 //              // turn all the LEDs off:
 //              digitalWrite(ledPin, LOW);
 //          }   
          
          
          //digitalWrite(ledPin, LOW);
          
//          void loop() {
// if (Serial.available() > 0) { // something came across serial
// integerValue = 0; // throw away previous integerValue
// while(1) { // force into a loop until ‘n’ is received
// incomingByte = Serial.read();
// if (incomingByte == ‘n’) break; // exit the while(1), we’re done receiving
// if (incomingByte == -1) continue; // if no characters are in the buffer read() returns -1
// integerValue *= 10; // shift left 1 decimal place
// // convert ASCII to integer, add, and shift left 1 decimal place
// integerValue = ((incomingByte – 48) + integerValue);
// }
// Serial.println(integerValue); // Do something with the value
// }
// }
//
//        }
//        else
//        {
//
//          //Serial.println("Symbol is not ;");
//        }    
//   }
//}
