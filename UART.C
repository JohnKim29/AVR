#include<mega128.h>


void Init_UART(void){
	UCSR1A = 0X00;
	UCSR1B = (1<<RXEN1) | (1<<TXEN1);
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
	UBRR1H = 0X00;
	UBRR1L = 0X07;
}

void Put_char_ch1(char data){
    while(!(UCSR1A & (1<<UDRE1)))
        ;
    UDR1 = data;
}

char Get_char_ch1(void){
    while(!(UCSR1A & (1<<RXC1)))
        ;
    return UDR1;
}

void main(){
    while(1)
        #asm("nop");
}