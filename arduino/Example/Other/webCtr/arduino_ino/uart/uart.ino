int LEDX;
int LEDmode;
int LED1=11;
int LED2=10;
int LED3=9;
int led_arr[]={11,10,9};
int led_arr_var=0;
int PWMvar=255;
int fadeAmount=5;
int brightCtr=0;
char str_type=Serial.read();
//String str_type=Serial.readString();

void led_pwm(){
       analogWrite(LED1,brightCtr);
       analogWrite(LED2,brightCtr);
       analogWrite(LED3,brightCtr);

       brightCtr=brightCtr+fadeAmount;
       if(brightCtr<=0 || brightCtr>=255){
            fadeAmount= -fadeAmount;
        }
       delay(300);
       
}
void led_light(){
        for(led_arr_var=0;led_arr_var<2;led_arr_var++) digitalWrite(led_arr[led_arr_var],HIGH);
        delay(1000);
 }
void led_dark(){
        for(led_arr_var=0;led_arr_var<2;led_arr_var++) digitalWrite(led_arr[led_arr_var],LOW);
        delay(1000);
 }
void led_pilix(){
      led_dark();
      for(led_arr_var=0;led_arr_var<=3;led_arr_var++) {
        digitalWrite(led_arr[led_arr_var],HIGH);
        delay(10000);
      }
      for(led_arr_var=0;led_arr_var<=3;led_arr_var--) {
        digitalWrite(led_arr[led_arr_var],LOW);
        delay(10000);
      }
 }
 
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    led_dark();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    str_type=Serial.read();
    //str_type=Serial.readString();
     if(str_type=='P'){
           led_pilix();
      }
     if(str_type=='W'){
          led_pwm();
      }
    
      if(str_type=='A'){
             LEDX=LED1;
             LEDmode= HIGH;
       }else if(str_type=='B'){
            LEDX=LED2;
            LEDmode= HIGH;
       }else if(str_type=='C'){
           LEDX=LED3;
           LEDmode= HIGH;
       }else if(str_type=='E'){
           led_light();
        }

        if(str_type=='a'){
             LEDX=LED1;
             LEDmode= LOW;
       }else if(str_type=='b'){
            LEDX=LED2;
            LEDmode= LOW;
       }else if(str_type=='c'){
           LEDX=LED3;
           LEDmode= LOW;
       }else if(str_type=='e'){
           led_dark();
        }
       
     digitalWrite(LEDX,LEDmode);
     
  }
 delay(100);
}
