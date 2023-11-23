#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int s = 0;

ISR(TIMER1_COMPA_vect)
{
	s++;
		
	if (s>10)
	{	
		PORTB = (1<<PB0);
		_delay_ms(500);
		s=0;
	}
	
	TCNT1H=0;
	TCNT1L=0;
}

int main(void)
{
	DDRB = 0xFF;
	
	TCCR1A = 0x00;
	TCCR1B = 0x05;
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	ICR1H = 0x00;
	ICR1L = 0x00;
	OCR1AH = 0x1E;
	OCR1AL = 0x85;
	TIMSK = 0x10;
	
    while(1)
    {
    }
}