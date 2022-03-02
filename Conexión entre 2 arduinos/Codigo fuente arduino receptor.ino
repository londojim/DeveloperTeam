/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */
//ARDUINO RECEPTOR
// include the library code:
#include <LiquidCrystal.h>
#define reloj 13
#define banderaRX 6
#define infoEncriptada 7
int8_t i=0;
int val=0;
int resto =0, resultado=0;
bool bandera = false;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(reloj, INPUT); ////Pin para la señal de reloj
  pinMode(infoEncriptada, INPUT);// Pin para recibir la información "encriptada"
  pinMode(banderaRX, OUTPUT); //Bandera de RX. Se enciende cuando logra leer el bit
}


void loop() {
  
  int infoRX[8] = {0};
  
    if(digitalRead(reloj)){  //Si detecta flanco de subida:
      val= digitalRead(infoEncriptada); //Lee la información
      infoRX[i]= val; //Va guardando la información en un array
      
      resultado =(resto*2)+val;
      resto=resultado;
      
       while (bandera==true)
    {
      lcd.setCursor(0, 1); //Se ubica el cursor en la columna i, fila 0
      lcd.print("Bandera");
      bandera=false;
         
    }
      
      lcd.setCursor(i, 0); //Se ubica el cursor en la columna i, fila 0
      lcd.print(infoRX[i]);
      i++;      
      digitalWrite(banderaRX,1); //Se enciende cuando logra recibir el bit
      delay(20);
    } 
      digitalWrite(banderaRX,0); 
      delay(20);
      
      Serial.print("RX ");
      Serial.println(val);
  
  if(i==8){
    
    if (digitalRead(8) == 0)
    {
      bandera=true;
    }
    
    
    
    lcd.setCursor(10, 0); //Se ubica el cursor en la columna i, fila 0
    lcd.print(resto);
  delay(50); 
    resto=0;
    resultado=0;
    i=0;
    lcd.clear();
  }  
}
 