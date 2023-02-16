#include <math.h>
 
int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
float fsrReading;     // the analog reading from the FSR resistor divider
float fsrVoltage;     // the analog reading converted to voltage
float fsrForce;       // Finally, the resistance converted to force
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  fsrReading = analogRead(fsrPin) - 20;
  if(fsrReading <0) {
    fsrReading = 0;  
  }
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V (= 5000mV)
  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  Serial.print("Voltage reading in mV = ");
  Serial.println(fsrVoltage);  
 
  if (fsrVoltage == 0) {
    Serial.println("No pressure");  
  } else {
    fsrForce = 1E-9 * pow(fsrVoltage,3.3905);
    Serial.print("Force in g: ");
    Serial.println(fsrForce);      
  }
  Serial.println("--------------------");
  delay(500);
}



