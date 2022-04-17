/*
 *Include header files
*/


#include "IncFile1.h"
#include "IncFile2.h"
#include "data.h" 
#include "avr/interrupt.h" 




/* 
*function to write data to LCD
*/
 void lcddatas(unsigned char data)
 {   /*
	 * Make portD pin 5 high
	  */
	 PORTD |= (1<<reg);
	 /* 
	 * Make portD pin 6 low
	 */
	 PORTD &= ~(1<<regw);
	 /*
	  * Data transmission in 4 bit mode
	  * make D4,D5,D6,D7 high
	  */
	 LCD= data & 0xF0;
	 /*
	 *make enable pin high
	 */
	 PORTD|=(1<<enab);
	 _delay_ms(1);
	 /*
	 make enable pin low
	 */
	 PORTD&= ~(1<<enab);
	 LCD =data<<4;
	 PORTD |= (1<<enab);
	 _delay_ms(1);
	 PORTD&= ~(1<<enab);
 }
 /*
 * function to initialize lcd
  */
 void lcd_init()
 {   /*
      * PORTB as output
	  */
	 DDRB = 0xFF;
	 DDRD|=(1<<enab);
	 DDRD|=(1<<reg);
	// DDRD = 0xFF;
	 PORTD&= ~(1<<enab);
	 lcdcmd(0x33);
	 lcdcmd(0x32);
	 lcdcmd(0x28);
	 lcdcmd(0x0E);
	 lcdcmd(0xC0);
	 lcdcmd(0x01);
	 lcdcmd(0x80);
	 _delay_ms(2);
 }
 /*
 * Function to pass the incoming string to lcd data function
 */
 void lcd_print(char *q)
 {
	 unsigned char i=0;
	 while(q[i]!=0)
	 {
		 lcddata(q[i]);
		 i++;
	 }
 }

 
 int main(void)
 {   /*
	 * Initialize LCD
	 */
	 lcd_init();
	 /*
	 * Clear LCD
	 */
	 lcdcmd(0x01);
	 int16_t  c= 0,d=0,e=0,f=0;
	 char s[16],t[16],u[16],v[16];
	 /*
	* Display Commands
	 */
	 lcd_print("    WELCOME");
	 lcdcmd(0xC5);
	 _delay_ms(1000);
	 lcdcmd(0x01);
	 lcd_print("Please cast your");
	 lcdcmd(0xC0+0);
	 lcd_print(" valuable vote");
	  _delay_ms(500);
  
while(1)
{   /*
	* If PIR sensor detects motion then execute loop
	*/
	if((PINC& 0b00100000)==0)
	{
		PORTB |=(1<<PORTB0);
	_delay_ms(200);
	PORTB &=~(1<<PORTB0);
	_delay_ms(200);

	    /*
		* First pushbutton pressed
		*/
		 if( (PINC & 0x01) == 0 )
		 {   PORTB &=~(1<<PORTB0);
			  PORTB |=(1<<PORTB1);
			  _delay_ms(200);
			  PORTB &=~(1<<PORTB1);
			 c++;
			  
			 while( (PINC & 0x01) == 0 );
		 }
		 /*
		  *  second pushbutton pressed
		 */
		if( (PINC & 0x02) == 0 )
		 {  
			 PORTB &=~(1<<PORTB0);
			  PORTB |=(1<<PORTB1);
			  _delay_ms(200);
			  PORTB &=~(1<<PORTB1);
			 d++;
			 
			 while( (PINC & 0x02) == 0 );
		 }
		 
		 /*
		  * Third pushbutton pressed
		  */
		if((PINC & 0b00000100)==0)
		 {
			 PORTB &=~(1<<PORTB0);
			  PORTB |=(1<<PORTB1);
			  _delay_ms(200);
			  PORTB &=~(1<<PORTB1);
			 e++;
			 
			 while( (PINC & 0b00000100) == 0 );
		 }
		  /*
		   * Fourth pushbutton pressed
		   */
		 if( (PINC & 0b00001000) == 0 )
		 {
			 PORTB &=~(1<<PORTB0);
			  PORTB |=(1<<PORTB1);
			  _delay_ms(200);
			  PORTB &=~(1<<PORTB1);
			 f++;
			 
			 while( (PINC & 0b00001000) == 0 );
		 }
	     /*
		  * Fifth pushbutton pressed
		  */
		  if( (PINC & 0b00010000) == 0 )
		  {  
			  PORTB &=~(1<<PORTB0);
			  PORTB &=~(1<<PORTB1);
			  PORTB |=(1<<PORTB2);
			  _delay_ms(200);
			  PORTB &=~(1<<PORTB2);
			  _delay_ms(200);
			  lcdcmd(0x01);
			  lcd_print("P= ");
			  lcdcmd(0x80+2);
			  itoa(c,s,10);
			  lcd_print(s);
			  lcdcmd(0x80 + 10);
			  
			  lcd_print("Q= ");
			  lcdcmd(0x80+12);
			  itoa(d,t,10);
			  lcd_print(t);
			  lcdcmd(0xC0+0);
			  
			  lcd_print("R= ");
			  lcdcmd(0xC0+2);
			  itoa(e,u,10);
			  lcd_print(u);
			  lcdcmd(0xC0+10);
			  
			  lcd_print("S= ");
			  lcdcmd(0xC0+12);
			  itoa(f,v,10);
			  lcd_print(v);
			  lcdcmd(0x80+0);
			  
			  
			  while( (PINC & 0b00010000) == 0 );
		  }
		 
	}
}
	 
	 return 0;
}
 
 