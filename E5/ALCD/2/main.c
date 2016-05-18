#include <mega64.h>
#include <stdio.h>
#include <delay.h>
#include <string.h>

// Alphanumeric LCD functions
#include <alcd.h>

//int debounce1(int index){
int debounce1(){
    int i = 0;
    for(i = 0; i < 2;i++){
        if((PINA & 0x01) == 0x01){
            if (i == 2){
                return 1;    
            }
        }
        else{
            return 0;
        }
        delay_ms(40);
    }
}

int debounce2(){
    int i = 0;
    for(i = 0; i < 2;i++){
        if((PINA & 0x02) == 0x02){
            if (i == 2){
                return 1;    
            }
        }
        else{
            return 0;
        }
        delay_ms(40);
    }
}

int checkToggled1()
{
    if((PINA & 0x01) == 0)
        return 1;
    else
        return 0;
}

int checkToggled2()
{
    if((PINA & 0x02) == 0)
        return 1;
    else
        return 0;
}    
// Declare your global variables here

void main(void)
{
// Declare your local variables here
    int counter=0;
    char counterChar;
    //string printStr = "0";
// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Port E initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTE=0x00;
DDRE=0x00;

// Port F initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTF=0x00;
DDRF=0x00;

// Port G initialization
// Func4=In Func3=In Func2=In Func1=In Func0=In 
// State4=T State3=T State2=T State1=T State0=T 
PORTG=0x00;
DDRG=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 20
lcd_init(20);

while (1)
      {
      // Place your code here
          if(debounce1() == 1){
            delay_ms(5);
            if (checkToggled1() == 1){
              counter++;
              if (counter > 9) {
              counter=0;          
              }
              }
            }
      if(debounce2() == 1){
        delay_ms(5);
        if (checkToggled2() == 1){
          counter--;
          if (counter < 0) {
          counter=9;          
              }
        }
        }
        lcd_gotoxy(0,0);
        lcd_putchar(counter + 48);
       }    
      
}
