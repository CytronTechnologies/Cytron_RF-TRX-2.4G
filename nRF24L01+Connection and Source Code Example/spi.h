/*******************************************************************************
* This file provides the functions for the SPI module.
*
* Author: Kong Wai Weng @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _SPI_H
#define _SPI_H



/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/

/*******************************************************************************
* PUBLIC FUNCTION: vInitSpi
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the SPI module.
*
*******************************************************************************/
void vInitSpi(void);



/*******************************************************************************
* PUBLIC FUNCTION: ucTransferSpi
*
* PARAMETERS:
* ~ ucData		- The data to send.
*
* RETURN:
* ~ The data received from the SPI.
*
* DESCRIPTIONS:
* Send and receive the data via SPI.
*
*******************************************************************************/
unsigned char ucTransferSpi(unsigned char ucData);



#endif
