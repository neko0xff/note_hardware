/*
 * sensor: S12SD
*/
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorVoltage;
  int sensorValue;
  sensorValue = analogRead(A0);
  /*
   * 転換公式: sensorVoltage = sensorValue/1024* 供電電壓 (3.3V 或 5V) 
  */
  sensorVoltage = (float)sensorValue/1024*3.3;

  
  Serial.print("Sensor Reading=");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.print("Sensor Voltage=");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  Serial.print("UV=");
  Serial.println(mv_to_uv(sensorValue));
  
  //delay(2000);
}

int mv_to_uv(int sensor_value){
   int uv;
   
   if(sensor_value<=226) uv=0;
   else if(sensor_value<=227&&sensor_value<=317) uv=1;
   else if(sensor_value<=318&&sensor_value<=407) uv=2;
   else if(sensor_value<=408&&sensor_value<=502) uv=3;
   else if(sensor_value<=503&&sensor_value<=605) uv=4;
   else if(sensor_value<=606&&sensor_value<=695) uv=5;
   else if(sensor_value<=696&&sensor_value<=794) uv=6;
   else if(sensor_value<=795&&sensor_value<=880) uv=7;
   else if(sensor_value<=881&&sensor_value<=975) uv=8;
   else if(sensor_value<=976&&sensor_value<=1078) uv=9;
   else if(sensor_value<=1079&&sensor_value<=1169) uv=10;
   else uv=11;
   
   return uv;
}
