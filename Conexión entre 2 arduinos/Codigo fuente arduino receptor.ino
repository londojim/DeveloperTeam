//ARDUINO RECEPTOR
#define reloj 13
#define banderaRX 6
#define infoEncriptada 3
int8_t i=0;
int val=0;

void setup()
{
  Serial.begin(9600);
  pinMode(reloj, INPUT); ////Pin para la señal de reloj
  pinMode(infoEncriptada, INPUT);// Pin para recibir la información "encriptada"
  pinMode(banderaRX, OUTPUT); //Bandera de RX. Se enciende cuando logra leer el bit

}

void loop(){
  int infoRX[10] = {8,0,7,4,0,0,0,0,0,0};
  
    if(digitalRead(reloj)){  //Si detecta flanco de subida:
      val= digitalRead(infoEncriptada); //Lee la información
      infoRX[i]= val; //Va guardando la información en un array
      i++;
      digitalWrite(banderaRX,1); //Se enciende cuando logra recibir el bit
      delay(20);
    } 
      digitalWrite(banderaRX,0); 
      delay(20);
      
      Serial.print("RX ");
      Serial.println(val);
  if(i==10){
    i=0;
  }
}
