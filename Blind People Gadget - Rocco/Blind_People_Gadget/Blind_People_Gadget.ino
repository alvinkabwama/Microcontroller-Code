
#include <Ultrasonic.h>


Ultrasonic STOMACH_SENSOR(14, 15);
Ultrasonic L_LEG_SENSOR(17, 18);
Ultrasonic R_LEG_SENSOR(7, 6);
float S_DISTANCE, R_DISTANCE, L_DISTANCE;

void setup()
  {
  Serial.begin(9600);
 
 
  
  }

void loop()
  {
  float cmMsec, inMsec;
  long microsec1 = STOMACH_SENSOR.timing();//microsec is timing for the first sensor object
  long microsec2 = L_LEG_SENSOR.timing();//microsec is timing for the second sensor object
  long microsec3 = R_LEG_SENSOR.timing();//microsec is timing for the third sensor object

  S_DISTANCE = STOMACH_SENSOR.convert(microsec1, Ultrasonic::CM); //Calculation of the sensor distances 
  L_DISTANCE = L_LEG_SENSOR.convert(microsec2, Ultrasonic::CM);
  R_DISTANCE = R_LEG_SENSOR.convert(microsec3, Ultrasonic::CM);
  Serial.print("S1: ");// Printing of sensor distances on the serial monitor.
  Serial.print(S_DISTANCE);
  Serial.print(", L1: ");
  Serial.print(L_DISTANCE);
  Serial.print(", R1: ");
  Serial.println(R_DISTANCE);
  delay(100);
  //DistMeasure();
  
  }
