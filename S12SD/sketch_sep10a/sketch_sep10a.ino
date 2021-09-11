/*
 * sensor: S12SD
*/
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorVoltage,sensorValue;
  sensorValue = analogRead(A0);
  /*
   * 転換公式: sensorVoltage = sensorValue/1024* 供電電壓 (3.3V 或 5V) 
  */
  sensorVoltage = sensorValue/1024*3.3;

  
  Serial.print("Sensor Reading=");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.print("Sensor Voltage=");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  Serial.print("UV=");
  Serial.println(mv_to_uv(sensorVoltage));
  
  delay(1000);
}

int mv_to_uv(float sensor_value){
   int uv;
   
   if(sensor_value<=1170) uv=11;
   else if(sensor_value<=1079) uv=10;
   else if(sensor_value<=976) uv=9;
   else if(sensor_value<=881) uv=8;
   else if(sensor_value<=795) uv=7;
   else if(sensor_value<=696) uv=6;
   else if(sensor_value<=606) uv=5;
   else if(sensor_value<=503) uv=4;
   else if(sensor_value<=408) uv=3;
   else if(sensor_value<=318) uv=2;
   else if(sensor_value<=227) uv=1;
   else if(sensor_value=50)  uv=0;
   
}
