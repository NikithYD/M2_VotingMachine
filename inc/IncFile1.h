/*
 * IncFile1.h
 *
 * Created: 16-04-2022 19:46:17
 *  Author: lenovo
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#endif /* INCFILE1_H_ */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define LCD PORTB
#define enab 7
#define reg 5
#define regw 6
/*
 * function to send commands to lcd display
 */
void lcdcmd(unsigned char cmd);
/*
 * function to display data to lcd display
 */
void lcddata(unsigned char data);




