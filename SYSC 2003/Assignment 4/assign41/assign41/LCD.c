#include <stdio.h>
#include "hcs12dp256.h"


void lcd_istruction(char data){
	 
	 char d1 = 0x00;
	 d1 = data;
	 d1 = d1 >> 4;
	 PTP |= d1;
	 PTT &= ~0x04;		 //set RS=0 as it is an instruction
	 PTT |= 0x08;		 
	 delay(100);
	 PTT &= ~0x08;
	 
	 d1 = data;
	 d1 &= 0x0F;
	 PTP |= d1;
	 PTT &= ~0x04;		 //set RS=0 as it is an instruction
	 PTT |= 0x08;
	 delay(100);
	 PTT &= ~0x08;
	 
}

void lcd_data(char data){
	 
	 char d1 = 0x00;
	 d1 = data;
	 d1 = d1 >> 4;
	 PTP |= d1;
	 PTT |= 0x04;		 //set RS=1 as it is data
	 PTT |= 0x08;
	 delay(100);
	 PTT &= ~0x08;
	 
	 d1 = data;
	 d1 &= 0x0F;
	 PTP |= d1;
	 PTT |= 0x04;		 //set RS=1 as it is data
	 PTT |= 0x08;
	 delay(100);
	 PTT &= ~0x08;
	 
}

void delay (int ms){

	 const int delayConstant = 1234;
	 int i, j;
	 
	 for (i=0; i<ms; i++) {
	 	 for (j=0; j<delayConstant; j++) {
		 }
	}
	
}

void main(){
	 
	char test = 0x00;
		  
	PTS = 0xFF;		   		//enabling U21_EN for the LCD
	PTT &= ~0x02;			//set RW=0
	
	lcd_istruction(0x38);		  //function set
	lcd_istruction(0x0E);		  //Display on/off control
	lcd_istruction(0x06);		  //Entry Mode set
	lcd_istruction(0x01);		  //clear display
	
	while(test<0xFF){
	lcd_data(test);
	printf("test : ",test);
	test++;
	}
	printf("End");
	
}
