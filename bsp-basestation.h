/*
 * File:   bsp-ip25.h
 * Author: apullin
 *
 * Created on January 15, 2014, 5:05 PM
 */

#ifndef BSP_IP25_H
#define	BSP_IP25_H

//SPI setup registers; possible should be in a chip support include
// SPIx Registers
#define SPI_BUF         SPI2BUF
#define SPI_CON1bits    SPI2CON1bits
#define SPI_CON2        SPI2CON2
#define SPI_STATbits    SPI2STATbits
#define SLPTR           _LATE5 // Radio Sleep/Transmit Pin

//TRX defines
#define TRX_CS      0 //TRX on SPI channel 2 on basestation
//DFMEM defines
//#define DFMEM_CS    0 //On SPI channel 2
//MPU defines
//#define MPU_CS      1 //On SPI channel 2

#define TRX_SPI_CHAN 1

//These should probably be in a chip support package include, rather than BSP
#define SPI1_CS             (_LATG9)    // Radio Chip Select
#define SPI2_CS1            (_LATG9)    // Flash Chip Select
#define SPI2_CS2            (_LATG9)   // MPU6000 Chip Select

// UART
#define UART_RX_IF _U1RXIF
#define UART_TX_IF _U1TXIF
#define UART_RX_INTERRUPT _U1RXInterrupt
#define UART_TX_INTERRUPT _U1TXInterrupt
#define UARTSTAbits U1STAbits
#define BusyUART BusyUART1
#define WriteUART WriteUART1


//LED colors
//TODO (): Should this be here? Since any color LED could end up installed
//  on the board, which could be very misleading
#define LED_0   _LATD0
#define LED_1   _LATD1
#define LED_2   _LATD2
#define LED_3   _LATD3

#define LED_RED             LED_0
#define LED_YLW1            LED_1
#define LED_YLW2            LED_2
#define LED_BLU             LED_3

#endif	/* BSP_IP25_H */
