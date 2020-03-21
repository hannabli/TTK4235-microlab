//
//  ppi.c
//  
//
//  Created by Hanna Lille on 3/21/20.
//

#include <stdio.h>
#include "ppi.h"
#include "gpiote.h"

void ppi_init() {
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[1]);
    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
    
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[2]);
    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
    
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->OUT[3]);
    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->IN[0]);
    
    PPI->CHENSET = 0x0000000E;
}
