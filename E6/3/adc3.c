/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 4/16/2016
Author  : Reza
Company : 
Comments: 


Chip type               : ATmega64
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 1024
*****************************************************/

#include <mega64.h>

#include <delay.h>

#define ADC_VREF_TYPE 0x00

#define PORT_OUTPUT 0XFF
#define PORT_INPUT  0X00
#define SS_0 0X3F
#define SS_1 0X06
#define SS_2 0X5B
#define SS_3 0X4F
#define SS_4 0X66
#define SS_5 0X6D
#define SS_6 0X7D
#define SS_7 0X07
#define SS_8 0X7F
#define SS_9 0X6F

void SetSevenSegement(int OutNum)
{
    switch (OutNum)
    {
        case 0: 
            PORTC = SS_0;
            break;
            
        case 1: 
            PORTC = SS_1;
            break;      
            
        case 2: 
            PORTC = SS_2;
            break;   
            
        case 3: 
            PORTC = SS_3;
            break;
            
        case 4: 
            PORTC = SS_4;
            break;
            
        case 5: 
            PORTC = SS_5;
            break;  
        case 6: 
            PORTC = SS_6;
            break;   
        case 7: 
            PORTC = SS_7;
            break;   
         case 8: 
            PORTC = SS_8;
            break;  
         case 9: 
            PORTC = SS_9;
            break;
         default:
            break;  
           
           
    }
}
 

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}



// Declare your global variables here

void main(void)
{
// Declare your local variables here
   int adcVal;
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
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0xFF;

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

// ADC initialization
// ADC Clock frequency: 1000.000 kHz
// ADC Voltage Reference: AREF pin
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x83;

while (1)
      {
      // Place your code here
      adcVal = read_adc(0);
      adcVal /= 100;
      SetSevenSegement(adcVal);
      }
}
