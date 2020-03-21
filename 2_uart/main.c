#include <stdint.h>
#include "uart.h"
#include "gpio.h"
#include <stdio.h>



ssize_t _write(int fd, const void *buf, size_t count){
        char * letter = (char *)(buf);
        for(int i = 0; i < count; i++){
            uart_send(*letter);
            letter++;
        }
    return count;
}

ssize_t _read(int fd, void *buf, size_t count){
        char *str = (char *)(buf);
        char letter;
        do {
            letter = uart_read();
        } while(letter == '\0');
        *str = letter;
    return 1;
}

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	int sleep = 0;
    
	uart_init();
    
    iprintf("The chemical formula for Ketamine is C%dH%dClNO\n\r", 13, 16); 
    
	while(1){
		
        
        uart_send_letter();
        uart_read_letter();

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
