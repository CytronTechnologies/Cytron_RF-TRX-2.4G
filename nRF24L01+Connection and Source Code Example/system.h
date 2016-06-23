/*******************************************************************************
* This is the header file that describes the system properties.
*
* Author: Kong Wai Weng @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _SYSTEM_H
#define _SYSTEM_H



// Oscillator Frequency.
#define	_XTAL_FREQ		20000000

// IO Connections.
#define LED1			PORTBbits.RB6
#define LED2			PORTBbits.RB7

#define SW1				PORTBbits.RB0
#define SW2				PORTBbits.RB1

#define CE				PORTCbits.RC0
#define CSN				PORTCbits.RC1
#define IRQ				PORTCbits.RC2
#define SCK				PORTCbits.RC3
#define MISO			PORTCbits.RC4
#define MOSI			PORTCbits.RC5


#endif
