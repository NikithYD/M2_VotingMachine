/*
 * IncFile2.h
 *
 * Created: 16-04-2022 19:50:57
 *  Author: Nikith
 */ 


#ifndef INCFILE2_H_
#define INCFILE2_H_
/* 
 * Commands
 */
void lcdcmd(unsigned char cmd)
{
	PORTD &= ~(1<<reg);
	PORTD &= ~(1<<regw);
	LCD= cmd & 0xF0;
	PORTD|=(1<<enab);
	_delay_ms(1);
	PORTD&= ~(1<<enab);
	LCD =cmd<<4;
	PORTD |= (1<<enab);
	_delay_ms(1);
	PORTD&= ~(1<<enab);
}




#endif /* INCFILE2_H_ */