/*
  Simple, quick test sketch.
*/

#include <SparkFun_LPS25HB_Arduino_Library.h> //Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

LPS25HB pressureSensor; // Create an object of the LPS25HB class

#define statLED 5

void setup()
{
  Serial.begin(115200);
  Serial.println("LPS25HB Pressure Sensor Example 1 - Basic Readings");
  Serial.println();
  pinMode(statLED, OUTPUT);
  digitalWrite(statLED, LOW);

  Wire.begin();
}

void loop()
{
  if (pressureSensor.begin() == true) // The library supports some different error codes such as "DISCONNECTED"
  {
    float temperature = pressureSensor.getTemperature_degC();
    float pressure = pressureSensor.getPressure_hPa();

    //pressureSensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
    Serial.print("Pressure in hPa: ");
    Serial.print(pressure); // Get the pressure reading in hPa
    Serial.print(", Temperature (degC): ");
    Serial.println(temperature, 2); // Get the temperature in degrees C

    if (pressure < 870.0 && pressure > 840.0 && temperature < 29 && temperature > 24)
      digitalWrite(statLED, HIGH);

  }
  else
  {
    Serial.println("Nothing detected");
    digitalWrite(statLED, LOW);
  }

  delay(100); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
