char Compare(char* This, char* RecievedCommand) 
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