/*	Author: Dragon Ni
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempA;
    	unsigned char tempC = 0;
    while (1) {
	tempA = ~PINA & 0x0F;
	if(tempA > 0x00){
		tempC = tempC | 0x20;
	}
	if(tempA > 0x02){
		tempC = tempC | 0x10;
	}
	if(tempA > 0x04){
		tempC = tempC | 0x08;
	}
	if(tempA > 0x06){
		tempC = tempC | 0x04;
	}
	if(tempA > 0x09){
		tempC = tempC | 0x02;
	}
	if(tempA > 0x0C){
		tempC = tempC | 0x01;
	}

	if(tempA < 0x05){
		tempC = tempC | 0x40;
	}
	else{
		tempC = tempC & 0xBF;
	}
	PORTC = tempC;
	tempA = 0;

	tempC = 0;
    }
    return 1;


}
