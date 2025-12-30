#include <Wire.h>
#include <APDS9930.h>

#define SDA_PIN 21  // choose your SDA pin
#define SCL_PIN 22  // choose your SCL pin

APDS9930 sensor = APDS9930();

void setup() {
  Serial.begin(115200);

  // Initialize I2C on custom pins
  Wire.begin(21, 22);

  // Initialize the APDS-9930 sensor
  if (sensor.init()) {
    Serial.println("APDS-9930 initialized successfully");
  } else {
    Serial.println("APDS-9930 initialization failed");
    while(1);
  }

  // Disable interrupts for polling mode
  sensor.enableProximitySensor(false);
  // PGAIN: 0=1x, 1=2x, 2=4x, 3=8x
  sensor.setProximityGain(3);
// LED strength: 0=12.5mA, 1=25mA, 2=50mA, 3=100mA
  sensor.setLEDDrive(3);
  delay(500); 
}

void loop() {
  uint16_t proximity = 0;
  
  if (sensor.readProximity(proximity)) {
    //Serial.print("proximity: ");
    Serial.println(proximity);
  }

  delay(200);
}
