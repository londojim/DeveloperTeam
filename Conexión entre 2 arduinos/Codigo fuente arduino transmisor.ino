//ARDUINO TRANSMISOR
#define dato 2
#define reloj 13
int val=0;
int val1=0;
int banderaRX=0;

void OnReloj() { //Función para activar el reloj
  digitalWrite(reloj, LOW);  
  digitalWrite(reloj, HIGH);  
  digitalWrite(reloj, LOW); 
}

void setup()
{
   Serial.begin(9600);
  pinMode(reloj, OUTPUT); //Reloj
  pinMode(dato, INPUT); // dato
  pinMode(4, OUTPUT);
  pinMode(6, INPUT);  //Bandera de RX indicando que recibió
}

void loop()
{
  int informacion[10] = {1,0,0,1,1,0,1,0,1,1};
  for(int8_t i=0; i<10; i++){
    digitalWrite(reloj, HIGH); 
    val1= informacion[i];
    digitalWrite(3,val1);
    while(digitalRead(6)==LOW){
          Serial.print("esperando");
    } 
    digitalWrite(reloj, LOW);

    Serial.print("El valor enviado es");
    Serial.println(val1);
  } 
}