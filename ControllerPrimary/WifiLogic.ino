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
	int i=0;
    while (!client.connected() && i<5) { 
      Serial.print(" Connecting to ");
      Serial.print(server);
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
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
  
    // wait 10 seconds for connection:
    delay(6000);
	i++;
  } 
  
  if(status == WL_CONNECTED)
  {

    Serial.println("Connected to wifi");
        Serial.print("Dns configured.");
	printWifiStatus();  
	PrintText("Connected to the world and ready to share few facts about myself ;)");
  }
  else
  {
	WifiEnabled=false;
	PrintText("Cannot connect to wifi. Will do it myself!");
  }
  
  
  client.flush();
	client.println("GET / HTTP/1.1");
		Serial.println("==>GET / HTTP/1.1");
	client.println("Host: icedock.net");
		//Serial.println("==>Host: 192.168.0.107");
	client.println("Connection: close");
	client.println();
        delay(1500);

	while (client.available()) 
	{
          char c = client.read();
          Serial.print(c);
	}
}

String ReadDataFromWifi()
{
  boolean startRecord = 0;
  String response="";
  
  //ConnectToSite();
  
  if (client.connected())
  {
        client.flush();
	client.println("GET /api/Command/Bot/Get HTTP/1.1");
		Serial.println("==>GET /api/Command/Bot/Get HTTP/1.1");
	client.println("Host: icedock.net");
		//Serial.println("==>Host: 192.168.0.107");
	client.println("Connection: close");
	client.println();
        delay(1500);

	while (client.available()) 
	{
          char c = client.read();
          if(c==123)
          {
            startRecord=1;           
          }  
          if(startRecord==1) {response=response+c;}
          Serial.print(c);
          //Serial.write(c);
	}
  }
  Serial.println();
  return response;
}

boolean CheckConnection()
{
	boolean checkConnection=true;
	if (!client.connected() && lastConnected) {
		Serial.println();
		Serial.println("disconnecting.");
		client.stop();
		checkConnection=false;
	}		

	lastConnected = client.connected();
	return checkConnection;
}

void sendResponse(String response) {
  // if there's a successful connection:
  if(response.length()==0) return;
  
  Serial.print("sending data: ");
  ConnectToSite();
  
  if (client.connected())
  {

    String content = "{'Text':' " + response + "'}";
    Serial.println(content);
    
	client.println("POST /api/Response/Bot/Post HTTP/1.1");
		Serial.println("==>POST /api/Response/Bot/Post HTTP/1.1");
	client.println("Host: arduino");
		//Serial.println("==>Host: 192.168.0.107");
	client.println("Connection:Keep-Alive");
		//Serial.println("==>Connection:Keep-Alive");
	client.println("Content-Type: application/json");
		//Serial.println("==>Content-Type: application/json");
	client.println("Accept: */*");
		//Serial.println("==>Accept: */*");
	client.print("Content-Length: ");
		//Serial.println("==>Content-Length:");
	client.println(content.length());
		//Serial.println(content.length());
	client.println();
	client.print(content);
		Serial.println(content);
	client.println();
  } 
}
