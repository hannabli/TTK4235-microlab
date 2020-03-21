//
//  main.c
//  
//
//  Created by Hanna Lille on 3/21/20.
//

#include <stdio.h>
#include "gpiote.h"
#include "ppi.h"

int main() {
    
    gpiote_init();
    ppi_init();
    
    while(1);
    
    return 0;
}
