//
//  twi.c
//  
//
//  Created by Hanna Lille on 3/21/20.
//

#include "twi.h"

#define PIN_SCL 0
#define PIN_SDA 30

#define TWI0 ((NRF_TWI_REG*)0x40003000)

typedef struct {
    // Tasks
    volatile uint32_t STARTRX;
    volatile uint32_t RESERVED0;
    volatile uint32_t STARTTX;
    volatile uint32_t RESERVED1[2];
    volatile uint32_t STOP;
    volatile uint32_t RESERVED2;
    volatile uint32_t SUSPEND;
    volatile uint32_t RESUME;
    // Events
    volatile uint32_t RESERVED3[56];
    volatile uint32_t STOPPED;
    volatile uint32_t RXDREADY;
    volatile uint32_t RESERVED4[4];
    volatile uint32_t TXDSENT;
    volatile uint32_t RESERVED5;
    volatile uint32_t ERROR;
    volatile uint32_t RESERVED6[4];
    volatile uint32_t BB;
    // Registers
    volatile uint32_t RESERVED7[49];
    volatile uint32_t SHORTS;
    volatile uint32_t RESERVED8[63];
    volatile uint32_t INTEN;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED9[110];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED10[14];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED11;
    volatile uint32_t PSELSCL;
    volatile uint32_t PSELSDA;
    volatile uint32_t RESERVED12[2];
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED13;
    volatile uint32_t FREQUENCY;
    volatile uint32_t RESERVED14[24];
    volatile uint32_t ADDRESS;
} NRF_TWI_REG;



void twi_init() {
    TWIO->ENABLE = 0;
    TWIO->FREQUENCY = 0x01980000;
    GPIO->PIN_CNF[PIN_SCL] = ;
    GPIO->PIN_CNF[PIN_SDA] = ;

}
