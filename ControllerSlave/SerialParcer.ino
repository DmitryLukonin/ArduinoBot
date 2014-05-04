//char Compare(char* This)
//{             
//                  if (strcmp(inData,This)  == 0) 
//                  {
//                    index=0;
//                    char inData[20];
//                    return(0);
//                  }
//                  else 
//                  {
//                    index=0;
//                    char inData[20];
//                    return(1);
//                  }     
//}

char Compare(char* This, char* RecievedCommand)  // replace for compare
{
	if (strcmp(RecievedCommand, This) == 0)
	{
		index = 0;
		char RecievedCommand[80];
		return(0);
	}
	else
	{
		index = 0;
		char RecievedCommand[80];
		return(1);
	}
}



//void GetString(){
//    while (Serial1.available() > 0) // Don't read unless
//                                   // there you know there is data
//    {
//        if(index < 19) // One less than the size of the array
//        {
//            inChar = Serial1.read(); // Read a character
//                        
//            if (inChar == 59)  //send a ; before your string as a start byte 
//            {
//              String test(inData);
//              Serial.print("whole data: ");
//              Serial.println(test);
//              return;
//            }
//            else
//            {
//              inData[index] = inChar; // Store it
//              index++; // Increment where to write next
//              inData[index] = '\0'; // Null terminate the string
//            }
//        }      
//    }
//}


int readline(int readch, char *buffer, int len)   // replace for GetString
{
	digitalWrite(ledPin, HIGH);
	static int pos = 0;
	int rpos;

	if (readch > 0) {
		switch (readch) {
		case '\n': // Ignore new-lines
			break;
		case '\r': // Return on CR
			rpos = pos;
			pos = 0;  // Reset position index ready for next time
			return rpos;
		case ';': // Return on ;
			rpos = pos;
			pos = 0;  // Reset position index ready for next time
			return rpos;
		default:
			if (pos < len - 1) {
				buffer[pos++] = readch;
				buffer[pos] = 0;
			}
		}
	}
	// No end of line has been found, so return -1.
	return -1;
}