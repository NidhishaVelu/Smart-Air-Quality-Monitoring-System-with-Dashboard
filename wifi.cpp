#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <MQ135.h>

const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";
const String serverURL = "http://your-server-ip/save_data.php"; // Replace with your server

MQ135 mq135_sensor(A0);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected.");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    float airPPM = mq135_sensor.getPPM();
    String url = serverURL + "?ppm=" + String(airPPM);

    http.begin(url);
    int httpCode = http.GET();
    http.end();

    Serial.println("PPM Sent: " + String(airPPM));
  }

  delay(5000); // Send every 5 seconds
}
