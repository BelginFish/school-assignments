#include <stdio.h>
#include "hcs12dp256.h"


void main(){
	 SPI1CR1 = 0x00;		   //Turn off SPI
	 DDRP = 0xFF;
	 DDRT = 0xFF;
	 
	 PTP = 0x20;
	 delay(50);
	 PTT = 0x04;
	 delay(50);
	 PTT = 0x04;
	 delay(50);
	 PTT = 0x04;
	 delay(50);
	 PTT = 0x04;
	 delay(50);
	 PTT = 0x04;
	 delay(50);
	 PTT = 0x04;
	 delay(50);
	
	 printf("yo");
	 delay(1000);
	

	 delay(50);
	 PTT = 0x20;
	 delay(50);
	 PTT = 0x20;
	 delay(50);
	 PTT = 0x20;
	 delay(50);
	 PTT = 0x20;
	 delay(50);
	 PTT = 0x20;
	 delay(50);
	 PTT = 0x20;
	 delay(50);
	 PTP = 0x00;
	 
	 
	 printf("end");
	 
}

void delay (int ms){

	 const int delayConstant = 1234;
	 int i, j;
	 
	 for (i=0; i<ms; i++) {
	 	 for (j=0; j<delayConstant; j++) {
		 }
	}
	
}