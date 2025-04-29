//CÓDIGO DOS DISPLAY MULTIPLEXADO

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main (void){


  DDRB|=0X0F;//salidas b9 b10 b11 b12
  DDRD|=0X0C; //d2 d3
  PORTD&=~0x0c; //empiece en 00 para catodo
 
  while (1){
 
    PORTD&=~0X08; //desactivo d3
    PORTD|=0X04; //activo d2
    PORTB|=0X06; //mandoel 6
    PORTB&=0xF6;


  _delay_ms(1000);


    PORTD&=~0X04; //activo d3
    PORTD|=0X08; //desactivo d2
    PORTB|=0X07; //mando el 7
    PORTB&=0xF7;
    _delay_ms(1000);




}
}
//SUBIR BAJAR  CON  2 BOTONES Y 2 DISPLAY MULTIPLEXADOS

/*
#define F_CPU 16000000UL
 #include <avr/io.h>
 #include <util/delay.h>
 
 int main(void) {
     DDRD |= 0xF0;   // PD4 a PD7 como salida (datos al display)
     DDRB |= 0x03;   // PB0 y PB1 como salida (selección de display)
     DDRB &= ~0x0C;  // PB2 y PB3 como entrada (pulsadores)
     PORTB |= 0x0C;  // Habilitar pull-ups en PB2 y PB3
 
     char cuenta = 0;
     char pulsadores = 0;
 
     while (1) {


         PORTB &= ~0x01;     // par apagar el display de decenas
         PORTB |= 0x02;      // para prender el display de unidades
         PORTD = (PORTD & 0x0F) | ((cuenta % 10) << 4);  // para "desplazar" las unidades a losp ines del deco
         _delay_ms(8); //display
 
         // Mostrar decenas
         PORTB &= ~0x02;     // para apagar el display de unidades
         PORTB |= 0x01;      // para prender e display de decenas
         PORTD = (PORTD & 0x0F) | ((cuenta / 10) << 4);  // para desplazar las decenas a los pines del deco
         _delay_ms(8);
 
         // Leer botones
         pulsadores = (PINB & 0x0C); // para indicar uso de los pines pb10 pb11
 
         if (pulsadores == 0x08) {  // boton para subir
             cuenta++; //aumenta 1 unidad
             if (cuenta > 99)
             cuenta = 99; //la suma no va sobre pasar los 99
             _delay_ms(200);//boton


         } else if (pulsadores == 0x04) {  // boton para bajar
             if (cuenta > 0)
             cuenta--;
             _delay_ms(200);
         }
     }
 }
*/