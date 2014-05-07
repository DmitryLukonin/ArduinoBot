void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}


void ConnectToSite()
{
	if(!client.connected())
	{
		client.stop();
	}

	int i=0;
	while (!client.connected() && i<5) { 
		Serial.print(" Connecting to ");
		Serial.println(server);
		client.connect(server, serverPort);
		delay(100);
		i++;
    }
}

void ConnectToWifi()
{
	int i=0;
	int startRecord=0;
	while ( status != WL_CONNECTED && i<5) { 
		Serial.print("Attempting to connect to SSID: ");
		Serial.println(ssid);
		status = WiFi.begin(ssid, pass);
  
		// wait 10 seconds for connection:
		delay(6000);
		i++;
	} 
  
	if(status == WL_CONNECTED)
	{
		Serial.println("Connected to wifi");
		printWifiStatus();  
		PrintText("Connected to the world and ready to share few facts about myself ;)");
	}
	else
	{
		WifiEnabled=false;
		PrintText("Cannot connect to wifi!");
	}
}

String ReadDataFromWifi()
{
	if(status != WL_CONNECTED) {ConnectToWifi();}

	ConnectToSite();

	String response = "";
	if (client.connected())
	{
		client.flush();
		client.println("GET /api/Command/Bot/Get HTTP/1.1");
			Serial.println("==>GET /api/Command/Bot/Get HTTP/1.1");
		client.println("Host: icedock.net");
		client.println("User-Agent: ArduinoWiFi/1.1");
		client.println("Connection: Keep-Alive");
		client.println();

		int i=0;
		while(!client.available() && i<999)
		{
			i++;
			delay(5);
		}

		boolean startRecord = 0;


		while (client.available()) 
		{
			char c = client.read();
			if(c==123)
			{
				startRecord=1;           
			}  
			if(startRecord==1) 
			{
				response=response+c;
			}
			Serial.print(c);
		}
	}
	else
	{
		Serial.println("connection failed");
	}

	Serial.println();
	return response;
}

void sendResponse(String response) {
	if(response.length()==0) return;
  
	Serial.print("sending data: ");
  
  	if(status != WL_CONNECTED) {ConnectToWifi();}
	ConnectToSite();

	if (client.connected())
	{
		String content = "{'Text':' " + response + "'}";
			Serial.println(content);
		client.println("POST /api/Response/Bot/Post HTTP/1.1");
			Serial.println("==>POST /api/Response/Bot/Post HTTP/1.1");
		client.println("Host: icedock.net");
		client.println("Connection: Keep-Alive");
		client.println("Content-Type: application/json");
		client.println("Accept: */*");
		client.print("Content-Length: ");
		client.println(content.length());
		client.println();
		client.print(content);
		client.println();
  } 
}
