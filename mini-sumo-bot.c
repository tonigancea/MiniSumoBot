/*	
 * PM Fair 2019 - Gancea Ionatan
 * Mini-Sumo Robot
 */

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

#define POWER 255;
#define STOP 1;

void stop_robot() {
	OCR0A = STOP;
	OCR0B = STOP;
	OCR2A = STOP;
	OCR2B = STOP;
}

void move_forward() {
	OCR0A = POWER;
	OCR0B = STOP;
	OCR2A = POWER;
	OCR2B = STOP;	
}

void move_back() {
	OCR0A = STOP;
	OCR0B = POWER;
	OCR2A = STOP;
	OCR2B = POWER;	
}

void turn_around_left() {
	OCR0A = STOP;
	OCR0B = POWER;
	OCR2A = POWER;
	OCR2B = STOP;	
}

void turn_around_right() {
	OCR0A = POWER;
	OCR0B = STOP;
	OCR2A = STOP;
	OCR2B = POWER;	
}

/* Aprinde led-ul PC0 la apasarea butonului PB2. */
void run(void) {

	/* Setez PD6 si PD7 ca iesire. */
	/* Pe PD6 si PD7 scot semnal PWM */
	/* PD6 - OC2B */
	/* PD7 - OC2A */
	DDRD |= (1 << PD7) | (1 << PD6);

	/* Setez PB3 si PB4 ca iesire */
	/*  PB3 - OC0A */
	/* PB4 - OC0B */
	DDRB |= (1 << PB3) | (1 << PB4);

	// DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);

	/* timer 0 used for left engine */
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B |= (1 << CS00) | (1 << CS20);
	TIMSK0 = 0;
	OCR0A = STOP;
	OCR0B = STOP;

	/* timer 2 used for right engine */
	TCCR2A |= (1 << WGM21) | (1 << WGM20) | (1 << COM2A1) | (1 << COM2B1);
	TCCR2B |= (1 << CS20) | (1 << CS22);
	TIMSK2 = 0;
	OCR2A = STOP;
	OCR2B = STOP;

	int turn = 0;
	int tmp;

	while(1) {
		if ((PINA & (1 << PA6)) == 0)
			turn = 1;

		if (turn == 1) {
			/* stop forward */
			stop_robot();

			/* randomize turn */
			tmp = rand() % 2;
			
			/* start turning */
			if (tmp == 0)
				turn_around_left();
			else
				turn_around_right();	
			
			_delay_ms(800);
			
			/* stop turning */
			stop_robot();
			turn = 0;
		}

		/* move forward */
		move_forward();	
	}
	
}

int main(void) {
	run();

	while(1);

	return 0;
}
