
#include <MQ135.h>

const int mq135Pin = A0;     // Analog pin connected to MQ135 sensor
MQ135 mq135_sensor(mq135Pin);

void setup() {
  Serial.begin(9600);
  Serial.println("Smart Air Quality Monitoring System");
}

void loop() {
  float airQualityPPM = mq135_sensor.getPPM();

  Serial.print("Air Quality (PPM): ");
  Serial.println(airQualityPPM);

  delay(2000);  // Read every 2 seconds
}
