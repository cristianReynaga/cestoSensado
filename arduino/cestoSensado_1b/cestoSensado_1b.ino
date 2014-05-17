/*

 Sensado de cesto usando sensor ultrasonido SRF05
 17/05/2014
 #BAHackaton
 
 */

#include <NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int ledPin[]={
  7, 6, 5, 4, 3, 2};
int sensorPin[]={
  30, 32, 34, 36, 38, 40};


void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {

  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  //Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.print(",");
  Serial.println();

  delay(50);
}



