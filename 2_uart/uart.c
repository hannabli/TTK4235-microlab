#include <stdint.h>
#include "gpio.h"
#include <stdio.h>
#define UART ((NRF_UART_REG*)0x40002000)


int lights_on = 0;



typedef struct {
 
    volatile uint32_t STARTRX;
    volatile uint32_t STOPRX;
    volatile uint32_t STARTTX;
    volatile uint32_t STOPTX;
    volatile uint32_t RESERVED2[3];

    volatile uint32_t SUSPEND;
    volatile uint32_t RESERVED3[56];

    volatile uint32_t CTS;
    volatile uint32_t NCTS;
    volatile uint32_t RXDRDY;
    volatile uint32_t RESERVED4[4];
    volatile uint32_t TXDRDY;
    volatile uint32_t RESERVED5[1];
    volatile uint32_t ERROR;
    volatile uint32_t RESERVED6[7];
    volatile uint32_t RXTO;
    volatile uint32_t RESERVED7[110];
    
    volatile uint32_t INTEN;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED8[93];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED9[31];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED10[1];
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED11[1];
    volatile uint32_t BAUDRATE;
    volatile uint32_t RESERVED12[17];
    volatile uint32_t CONFIG;
} NRF_UART_REG;

void uart_init(){
    GPIO->PIN_CNF[25] = 0; 
    GPIO->PIN_CNF[24] = 1;
    //GPIO->DIRSET |= 1<<24;
    //GPIO->DIRCLR |= 1<<25;
    UART->PSELTXD = 24;
    UART->PSELRXD = 25;
    UART->PSELCTS = 0xFFFFFFFF;
    UART->PSELRTS = 0XFFFFFFFF;
    UART->BAUDRATE = 0X00275000;
    UART->ENABLE =4;
    UART->STARTRX = 1;
}

void uart_send(char letter){
    UART->STARTTX =1;
    UART->TXDRDY =0;
    UART->TXD = letter;

    while (!(UART->TXDRDY)){
        //wait until sent
    }
	// GPIO->OUTCLR |= 1<<14;

    UART->STOPTX =1;

}

char uart_read(){
    UART->STARTRX = 1;

    if(UART->RXDRDY) {
        
        UART->RXDRDY =0;
        char letter = UART->RXD;
        return letter;
    }
    else{
        //UART->STOPRX =1;
        return '\0';
    }
}

void uart_send_letter() {
    if (!(GPIO->IN & 1<<26)){
        uart_send('B');
        /*GPIO->OUTSET |= 1<<13;
        GPIO->OUTSET |= 1<<14;
        GPIO->OUTSET |= 1<<15; Dette var fra oppgave 1*/
        

    }
    if ((!(GPIO->IN & 1<<17))){
        uart_send('A');
        /*GPIO->OUTCLR |= 1<<13;
        GPIO->OUTCLR |= 1<<14;
        GPIO->OUTCLR |= 1<<15;*/
    }
}

void uart_read_letter() {
    char letter = uart_read();
    if(letter != '\0') {
        
        if(lights_on) {
            printf("Skrur på matrisen.");
            GPIO->OUTCLR = (1<<13);
            GPIO->OUTCLR = (1<<14);
            GPIO->OUTCLR = (1<<15);
            lights_on = 0;
        }
        
        else {
            printf("Skrur av matrisen.");
            GPIO->OUTSET = (1<<13);
            GPIO->OUTSET = (1<<14);
            GPIO->OUTSET = (1<<15);
            lights_on = 1;
        }
    }
}

