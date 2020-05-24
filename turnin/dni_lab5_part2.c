/*	Author: Dragon Ni
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States{start, store, dec, incr, reset} state;
unsigned char counter = 0;

void Tick(){
	unsigned char tempA = ~PINA;
	switch(state){
		case start:
			state = store;
			break;
		case store:
			if((tempA & 0x03) == 0x00) {
				state = store;
			}
			else if((tempA & 0x03) == 0x01) {
				state = incr;
				if(counter != 9){
					counter++;
					PORTC = counter;
				}
			}
			else if((tempA & 0x03) == 0x02){
				state = dec;
				if(counter != 0){
					counter--;
					PORTC = counter;
				}
			}
			else{
				state = reset;
				counter = 0;
				PORTC = counter;
			}
			break;
		case dec:
			if((tempA & 0x03) == 0x00){
				state = store;
			}
			else if((tempA & 0x03) == 0x01){
				state = incr;
				if(counter != 9){
					counter++;
					PORTC = counter;
				}
			}
			else if((tempA & 0x03) == 0x02){
				state = dec;
			}
			else{
				state = reset;
				counter = 0;
				PORTC = counter;
			}
			break;
		case incr:
			if((tempA & 0x03) == 0x00){
				state = store;
			}
			else if((tempA & 0x03) == 0x01){
				state = incr;
			}
			else if((tempA & 0x03) == 0x02){
				state = dec;
				if(counter != 0){
					counter--;
					PORTC = counter;
				}
			}
			else{
				state = reset;
				counter = 0;
				PORTC = counter;
			}
			break;
		case reset:
			if((tempA & 0x03) == 0x00){
				state = store;
			}
			else if((tempA & 0x03) ==0x01){
				state = incr;
				if(counter != 9){
					counter++;
					PORTC = counter;
				}
			}
			else if((tempA & 0x03) == 0x02){
				state = dec;
				if(counter != 0){
					counter--;
					PORTC = counter;
				}
			}
			else{
				state = reset;
				counter = 0;
				PORTC = counter;
			}
			break;

		default:
			state = start;
			break;
	}
	switch(state){
		case start:
			PORTC = counter;
			break;
		case store:
			break;
		case incr:
			break;
		case dec:
			break;
		case reset:
			break;
		
		default:
			break;
	}
}

int main(void) {

	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = counter;

	state = start;

    while(1) {
	   Tick();
	}
    return 1;


}
