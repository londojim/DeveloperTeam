//ARDUINO TRANSMISOR
#define reloj 13
#define banderaRX 6
#define infoENC 3
//#define SRCLK 9    //pin 9 a SRCLK del 74HC595

int8_t pinRCLK = 10; //Pin del registro de salida. AMARILLO
int8_t pinSRCLK = 9; //Pin del registro de desplazamiento. ROSADO

void OnSRCLK() { //Función para activar el reloj de la etapa de desplazamiento
  digitalWrite(pinSRCLK, LOW);
  digitalWrite(pinSRCLK, HIGH);
  digitalWrite(pinSRCLK, LOW);
}
void OnRCLK() { //Función para activar el reloj de la etapa de salida.
  digitalWrite(pinRCLK, LOW);
  digitalWrite(pinRCLK, HIGH);
  digitalWrite(pinRCLK, LOW);
}

int val = 0;
int k = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(reloj, OUTPUT); //Pin para la señal de reloj
  pinMode(infoENC, OUTPUT); // Pin para enviar la información "encriptada"
  pinMode(banderaRX, INPUT);  //Bandera de RX indicando que recibió

}

void loop()
{

  Serial.println("NUEVO VOID LOOP");
  Serial.println(k);

  while (k < 1) {


    byte informacion[8] = {0};
    int info[] = {117,23,58}; //Información "encriptada"

    int size = sizeof(info) / sizeof(int);
    
    
    for (int j = 0; j < size; j++) {

      for (int i = 0; i < 8 ; i++ ) {
        informacion[i] = info[j] % 2;
        info[j] /= 2;
      }


      Serial.print("---------");

      for (int8_t i = 7; i >= 0; i--) {//se envian datos al SER

        digitalWrite(reloj, HIGH); //Flanco de subida señal de reloj
        //shiftOut(infoENC, SRCLK, MSBFIRST, informacion[i]);
        digitalWrite(infoENC, informacion[i]); //Se envía bit a bit
        OnSRCLK();
        OnRCLK();
        while (digitalRead(banderaRX) == LOW) { //Si el RX no ha podido leer : espere
          Serial.println("esperando");
        }
        digitalWrite(reloj, LOW); //Flanco de bajada señal de reloj

        Serial.print("El valor enviado es ");
        Serial.println(informacion[i]);
      }//for SER



    }//fin for j

    k++;

  }//fin while

  
}//fin loop
