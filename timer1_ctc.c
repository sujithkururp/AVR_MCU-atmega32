#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <avr/interrupt.h>



void main(void) {
    
    TCCR1A=0X40;
    TCCR1B=0X0D;
    OCR1A=7812;
    
    DDRD |=(1<<5);//0c1a pin is toglled automaticaly whch is designd 
    
    
   
    return;
}
