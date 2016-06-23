/*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED IN AN ¡°AS IS¡± CONDITION. NO WARRANTY AND SUPPORT
* IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
* DAMAGES, FOR ANY REASON WHATSOEVER.
*
********************************************************************************
*
* SAMPLE SOURCE CODE FOR NRF24L01+ WIRELESS TRANSCEIVER
*
*
*
* DESCRIPTION:
*
* This is the sample source code to send and receive data using NRF24L01+ 
* transceiver.
*
*
*
* AUTHOR   : Kong Wai Weng
* COMPANY  : Cytron Technologies Sdn Bhd
* REVISION : 1.0
* DATE     : 8/12/2011
*
*******************************************************************************/



#include <htc.h>
#include "system.h"
#include "spi.h"
#include "nrf24l01.h"



/*******************************************************************************
* DEVICE CONFIGURATION WORDS                                                   *
*******************************************************************************/

__CONFIG(FOSC_HS &		// High Speed Crystal.
		 WDTE_OFF &		// Disable Watchdog Timer.
		 PWRTE_ON &		// Enable Power Up Timer.
		 BOREN_OFF &	// Disable Brown Out Reset.
		 LVP_OFF);		// Disable Low Voltage Programming.



/*******************************************************************************
* PRIVATE CONSTANT DEFINITION                                                  *
*******************************************************************************/





/*******************************************************************************
* PRIVATE FUNCTION PROTOTYPES                                                  *
*******************************************************************************/



/*******************************************************************************
* PRIVATE GLOBAL VARIABLES                                                     *
*******************************************************************************/




/*******************************************************************************
* MAIN FUNCTION                                                                *
*******************************************************************************/
int main(void)
{
	unsigned char ucStatus;
	unsigned char ucData;
	
	
	
	// Set all pins on Port A as digital IO.
	ADCON1 = 0x06;
	
	// Configure the IO direction.
	TRISB = 0b00111111;
	TRISC = 0b11010100;
	
	// Initialize the IO.
	PORTA = 0;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
	PORTE = 0;
	
	LED1 = 0;
	LED2 = 0;
	
	CE = 0;
	CSN = 1;
	
	
	// Initialize SPI.
	vInitSpi();
	
	// Initialize nRF24L01.
	vInitNrf24l01();
	
	
	
	while (1) {
		// If data is received...
		if (IRQ == 0) {
			ucStatus = ucNrf24l01ReceivePacket(&ucData, 1);
			
			// Make sure data is read out successfully.
			if (ucStatus != 0) {
				// Turn on/off LED1 according to the data received.
				if (ucData == 1) {
					LED1 = 1;
				}	
				else if (ucData == 2) {
					LED1 = 0;
				}
			}	
			
		}	
		
		// If SW1 is pressed, transmit 1.
		if (SW1 == 0) {
			
			// Enable Tx mode.
			vNrf24l01EnableTx();
			
			ucData = 1;
			ucStatus = ucNrf24l01TransmitPacket(&ucData, 1);
			
			// Change back to Rx mode.
			vNrf24l01EnableRx();
			
			// Turn on LED2 for a while if transmission failed.
			if (ucStatus == 0) {
				LED2 = 1;
				__delay_ms(300);
				LED2 = 0;
			}
			
			// Wait until SW1 is released.
			while (SW1 == 0);
		}
		
		
		
		// If SW2 is pressed, transmit 2.
		if (SW2 == 0) {
			
			// Enable Tx mode.
			vNrf24l01EnableTx();
			
			ucData = 2;
			ucStatus = ucNrf24l01TransmitPacket(&ucData, 1);
			
			// Change back to Rx mode.
			vNrf24l01EnableRx();
			
			// Turn on LED2 for a while if transmission failed.
			if (ucStatus == 0) {
				LED2 = 1;
				__delay_ms(300);
				LED2 = 0;
			}
			
			// Wait until SW2 is released.
			while (SW2 == 0);
		}
		
	}	
}
