/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */



#include "DIO_Reg.h"
#include "STd_Types.h"
#include "Utilities.h"
#include <avr/delay.h>

# define  iterations 10


void main(void){


	SET_BIT(DDRB, 1);  // Transistor enabled for 7Seg 1
	SET_BIT(DDRB, 2);  // TRansistor enabled for 7Seg 2

	SET_BIT(DDRA, 4);	// SET
	SET_BIT(DDRA, 5);	// 7Segs
	SET_BIT(DDRA, 6);	// to
	SET_BIT(DDRA, 7);	// Output


	u8 Arr [iterations] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90};
	u8 j, k;
	u8 i=0;
	u8 var_num1, var_num2 ;

	while(1){


	//	if (max < 100){

		//		for(i=0; i < iterations; i++){     		// for 10s

			do {
					var_num1 = Arr[i];
					i++;

						for (j=0; j < iterations; j++){		// for 1s

							var_num2 = Arr[j];

							for (k=0; k < 20; k++){

										PORTB = 0x04;
										PORTA = var_num1;
										_delay_ms (10);

										PORTB = 0x02;
										PORTA = var_num2;
										_delay_ms (10);

									}

					}
				} while (var_num1 != var_num2);

			PORTB = 0x06;
			PORTA =  var_num1;

	}
}
