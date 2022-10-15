#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "smart-irrigation-system-1df0b-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "XmDp5AxQCy0lRdzABb4UsP2uBamy5JXjtIlkjkJA"
#define WIFI_SSID "Redmi 10"
#define WIFI_PASSWORD "9157723152"

#define Sensor A0
#define Pump D3
void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
  
  // Sensor and Pump Data
  pinMode(Sensor, INPUT);
  pinMode(Pump, OUTPUT);
}

void loop() {
  int sensorread = analogRead(Sensor);
  float x = sensorread;
  float y = (1 - (x/1024));  
  float humidity = y*100;
  int Pumpstatus;
  
  if (humidity <= 25){
    digitalWrite(Pump, 0);
    delay(10000);
    Pumpstatus = 1;
  }
  else{
    digitalWrite(Pump, 1);
    Pumpstatus = 0;
  }

  Serial.println("Humidity: ");  
  Serial.println(humidity);
  Serial.println("Pump-Status");
  Serial.println(Pumpstatus);  
  Firebase.setFloat("SoilMoisture/Humidity",humidity);
  Firebase.setFloat("SoilMoisture/PumpStatus",Pumpstatus);
  
    if (Firebase.failed()) 
    {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
    }  
//   while(1){
//     int PumpStatus = Firebase.getInt("SoilMoisture/PumpStatus");
//     if(PumpStatus == 1){
//       digitalWrite(Pump, HIGH);
//       Serial.println("Pump On");
//       break;
//     }
//     else if (PumpStatus == 0){
//       digitalWrite(Pump, LOW);
//       Serial.println("Pump Off");
//       break;
//     }
//     else{
//       Serial.println(Firebase.error()); 
//       return;
//     }
//   }  
}

// #define relaypin D3
// void setup(){
//   pinMode(relaypin, OUTPUT);
// }
// void loop(){
//   digitalWrite(relaypin,LOW);
//   delay(2000);
//   digitalWrite(relaypin,HIGH);
//   delay(2000);
// }
