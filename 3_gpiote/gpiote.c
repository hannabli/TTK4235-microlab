//
//  gpiote.c
//  
//
//  Created by Hanna Lille on 3/21/20.
//

#include <stdio.h>
#include "gpiote.h"
#include "gpio.h"

void gpiote_init() {
    for(int i=4; i<13; i++) {
        GPIO->DIRSET = (1 << i);
        GPIO->OUTCLR = (1 << i);
    }
    
    //GPIOTE->CONFIG[0] = 0000 0000 0000 0010 0001 0001 0000 0001;
    GPIOTE->CONFIG[0] = 0x00021101;
    /*GPIOTE->CONFIG[0].PSEL = 17;
    GPIOTE->CONFIG[0].MODE = 1;
    GPIOTE->CONFIG[0].POLARITY = 2;*/
    
    //GPIOTE->CONFIG[1] = 0000 0000 0000 0011 0000 1101 0000 0011;
    GPIOTE->CONFIG[1] = 0x00030D03;
    /*GPIOTE->CONFIG[1].PSEL = 13;
    GPIOTE->CONFIG[1].MODE = 3;
    GPIOTE->CONFIG[1].POLARITY = 3;*/
    
    //GPIOTE->CONFIG[2] = 0000 0000 0000 0011 0000 1110 0000 0011;
    GPIOTE->CONFIG[2] = 0x00030E03;
    /*GPIOTE->CONFIG[2].PSEL = 14;
    GPIOTE->CONFIG[2].MODE = 3;
    GPIOTE->CONFIG[2].POLARITY = 3;*/
    
    //GPIOTE->CONFIG[3] = 0000 0000 0000 0011 0000 1111 0000 0011;
    GPIOTE->CONFIG[3] = 0x00030F03;
    /*GPIOTE->CONFIG[3].PSEL = 15;
    GPIOTE->CONFIG[3].MODE = 3;
    GPIOTE->CONFIG[3].POLARITY = 3;*/
}


