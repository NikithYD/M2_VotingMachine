/*
 * data.h
 *
 * Created: 16-04-2022 19:53:58
 *  Author: lenovo
 */ 


#ifndef DATA_H_
#define DATA_H_
void lcddata(unsigned char data)
{
	PORTD |= (1<<reg);
	PORTD &= ~(1<<regw);
	LCD= data & 0xF0;
	PORTD|=(1<<enab);
	_delay_ms(1);
	PORTD&= ~(1<<enab);
	LCD =data<<4;
	PORTD |= (1<<enab);
	_delay_ms(1);
	PORTD&= ~(1<<enab);
}




#endif /* DATA_H_ */