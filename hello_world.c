#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>





#define BIT(x) (1UL << (x))
#define REG(x) ((volatile uint32_t *) (x))

#define C3_GPIO 0x60004000

#define  GPIO_OUT_EN  8
#define GPIO_OUT_FUNC  341
#define GPIO_IN_FUNC  85 


static int gpio_pin =3;

int main(void)
{		 bool value=1;
		 REG(C3_GPIO)[341 + 1] = BIT(9) | 128;  
		REG(C3_GPIO)[GPIO_OUT_EN] &= ~BIT(gpio_pin);
		REG(C3_GPIO)[GPIO_OUT_EN] |= (1 ? 1U : 0U) << gpio_pin;

		REG(C3_GPIO)[1] &= ~BIT(gpio_pin);                 
		REG(C3_GPIO)[1] |= (value ? 1U : 0U) << gpio_pin;  
           
			//printf("hello"); //without doesn´t work->  Code that works with a printf() statement present, but fails when it is removed, is usually a sign of some invalid operation affecting memory in the program somewhere (e.g. falling off the end of an array, dereferencing NULL, etc). The misbehaving code may be in some other section of the program entirely (e.g. not within the function that contains the printf() statement)
														//That is even more likely when the offending printf() statement is something obviously innocent, and without any side effects that can affect behaviour of other code (such as printf("Hi\n")).
														//The reason is that the presence of the extra printf() does actually affect layout of memory for the program as a whole. So the offending code (which may be in some completely unrelated part of the program) still overwrites memory, but the consequence changes (e.g. overwriting some data the program is permitted to change, rather than some area of memory that causes the operating system to terminate the program).
														//This is true whether or not the code is multithreaded. 
    
        
	
    return 0;
}
