//btton connected to the pd6/icp1 it as alredy in edge slect given in the pin so when ever it get signel it will capture the timer value in the icr1 register it send in uart


#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <avr/interrupt.h>


void display(unsigned char *str) {
    while(*str) {
        while(!(UCSRA & (1<<UDRE)));  // Wait until transmit buffer is empty
        UDR = (*str++);
    }
}



void main(void) {
    
    
    TCCR1A=0X00;
    TCCR1B=0XC5;
    DDRD &=~(1<<6);//PD6 as input pin
    
    DDRD=0X02;
    UCSRA=0X00;
    UCSRB=0X18;
    UCSRC=0X86;
    UBRRL=51;
    
    unsigned int value=0;
    char buffer[20];
    while(1){
        while(PIND &(1<<6));
        while(!(PIND &(1<<6)));
        
        value=ICR1;
        sprintf(buffer,"%u\r",value);
        display(buffer);
        display("\r \n");
        
       
    }
    
    
   
    
    
    return;
}
