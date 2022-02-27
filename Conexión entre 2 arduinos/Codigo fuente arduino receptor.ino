//ARDUINO RECEPTOR
#define reloj 13
#define informacion 4
int8_t i=0;
int val=0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);

}

void loop(){
  int infoRX[10] = {8,0,7,4,0,0,0,0,0,0};
  
    if(digitalRead(13)){
      val= digitalRead(3);
      infoRX[i]= val;
      i++;
      digitalWrite(6,1);
      delay(20);
    } 
      digitalWrite(6,0);
      delay(20);
      
      Serial.print("RX ");
      Serial.println(val);
  if(i==10){
    i=0;
  }
}