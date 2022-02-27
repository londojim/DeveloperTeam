//ARDUINO TRANSMISOR
#define reloj 13 
#define banderaRX 6
#define infoENC 3

int val=0;

void setup()
{
  Serial.begin(9600);
  pinMode(reloj, OUTPUT); //Pin para la señal de reloj
  pinMode(infoENC, OUTPUT); // Pin para enviar la información "encriptada"
  pinMode(banderaRX, INPUT);  //Bandera de RX indicando que recibió
}

void loop()
{
  int informacion[10] = {1,0,0,1,1,0,1,0,1,1}; //Información "encriptada"
  
  for(int8_t i=0; i<10; i++){
    digitalWrite(reloj, HIGH); //Flanco de subida señal de reloj
    digitalWrite(infoENC,informacion[i]); //Se envía bit a bit 
    while(digitalRead(banderaRX)==LOW){ //Si el RX no ha podido leer : espere
          Serial.print("esperando");
    } 
    digitalWrite(reloj, LOW); //Flanco de bajada señal de reloj

    Serial.print("El valor enviado es");
    Serial.println(val);
  } 
}