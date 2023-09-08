#define BLYNK_TEMPLATE_ID "TMPL3efWH3vun"
#define BLYNK_TEMPLATE_NAME "dht iot sensor"
#define BLYNK_AUTH_TOKEN "z4AZkvLmEvVUPNZvWHWhhclHmjmi5iQC"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 
#define DHTTYPE DHT11  

char auth[] = "z4AZkvLmEvVUPNZvWHWhhclHmjmi5iQC";
char ssid[] = "Never gonna give you up";
char pass[] = "password6";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT TEST SUCCESSFUL");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected successfully");
  dht.begin();
}

void loop() {
  delay(2000);  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature(true);
  if (isnan(temperature) || isnan(humidity) ||isnan(temp) )
  {
    Serial.println("Something is not working as intended");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("C°");
  Serial.println("");
  Serial.println("yai lo bhai");
  Blynk.virtualWrite(V0,temperature);
  Blynk.virtualWrite(V1,humidity);
  delay(1000);
}