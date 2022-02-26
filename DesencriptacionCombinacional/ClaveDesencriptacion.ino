/*
Dirección de la simulaición

https://www.tinkercad.com/things/3vaf2zqTyd7


*/
  
/*
	Capitulo 70 de Arduino desde cero en Español.
	Contador binario con LEDs conectados a cada salida de un 74HC595.

	https://www.youtube.com/c/BitwiseAr
	Autor: bitwiseAr  

	Modificacion:
	Solo se quita el for en el loop y se coloca el condicional if para leer el dato del serial

*/


#define SER 7		//pin 7 a SER del 74HC595
#define RCLK 8		//pin 8 a RCLK del 74HC595
#define SRCLK 9		//pin 9 a SRCLK del 74HC595




void setup ()
{

	Serial.begin(9600);
	pinMode(SER, OUTPUT);	//pin establecido como salida
	pinMode(RCLK, OUTPUT);	//pin establecido como salida
	pinMode(SRCLK, OUTPUT);	//pin establecido como salida
}
 
void loop() {

	if (Serial.available()>0){
		int dato = Serial.parseInt();
		digitalWrite(RCLK, LOW);				//nivel bajo a registro de almacenamiento
		shiftOut(SER, SRCLK, MSBFIRST, dato);	//funcion para enviar de forma serie el valor de i
		digitalWrite(RCLK, HIGH);				//nivel alto a registro de almacenamiento
		//delay(2000);							//demora de medio segundo
	}//Fin if  
}



/*************************

El código de la linea 53 a la 77 se usa sin la implementación
del integrado 74HC595

***************************/

/*
int main(){
	init();
  
  
  Serial.begin(9600);
   for(unsigned char puerto = 2; puerto <= 9; puerto += 1){
  	pinMode(puerto,OUTPUT);
  }
  
  
  while(1){
    delay(10);//se recomienda que esté para no saturar el serial
  	digitalWrite(9, 0);
    digitalWrite(8, 0);
    digitalWrite(7, 1);
    digitalWrite(6, 1);
    digitalWrite(5, 1);
    digitalWrite(4, 0);
    digitalWrite(3, 1);
    digitalWrite(2, 0);
  }//fin while

return 0;

}//fin main

*/