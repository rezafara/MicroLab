#include <mega64.h>
#include <delay.h>
#include "glcd.h"

void write_Cmd(unsigned char cmd)
{
    //if(cs == 0)
    GLCD_SIG_PORT |= GLCD_CS1;
    //PORTA |= 0x10;
    //else
    GLCD_SIG_PORT |= GLCD_CS2;    
    GLCD_SIG_PORT &= ~(GLCD_DI);
    GLCD_SIG_PORT &= (~(GLCD_RW));
    //GLCD_SIG_PORT &= (~(GLCD_RST));
    GLCD_DB_PORT = cmd;
    GLCD_SIG_PORT &= (~(GLCD_E));
    GLCD_SIG_PORT |= GLCD_E;
    delay_us(100);
    GLCD_SIG_PORT &= (~(GLCD_E));
     
}

void write_Data(unsigned char data,int cs)
{
    if (cs == 1){
        GLCD_SIG_PORT |=   GLCD_CS1 ;
        GLCD_SIG_PORT &= ~(GLCD_CS2);
    }
    else if(cs == 2){
        GLCD_SIG_PORT |=   GLCD_CS2 ;
        GLCD_SIG_PORT &= ~(GLCD_CS1); 
    }
    else{
        return;
    }
    GLCD_SIG_PORT |= GLCD_DI;
    GLCD_SIG_PORT &= (~(GLCD_RW));
    //GLCD_SIG_PORT &= (~(GLCD_RST));
    GLCD_DB_PORT = data;
    GLCD_SIG_PORT &= (~(GLCD_E));
    GLCD_SIG_PORT |= GLCD_E;
    delay_us(100);
    GLCD_SIG_PORT &= (~(GLCD_E));
}

void clearScreen()
{
    int i =0;
    int j =0;
    
    for (i = 0; i < 8 ; i++){
        for (j = 0; j < 64; j++){
            gotoPage(i,j);
            write_Data(0x00,1);
            write_Data(0x00,2);
        }
        write_Data(0x00,1);
        write_Data(0x00,2);
    }
}

void GLCDInit()
{
    PORTA=0x00;
    DDRA=0xFF;
    
    PORTC=0x00;
    DDRC=0xFF;
    
    GLCD_SIG_PORT &= !(GLCD_RST);
    delay_us(100);
    GLCD_SIG_PORT |= GLCD_RST; 
    write_Cmd(CMD_GLCDON);
    write_Cmd(CMD_PAGE);
    write_Cmd(CMD_YLINE);
    write_Cmd(CMD_STARTLINE);
    delay_us(100);
    clearScreen();    
}
void gotoPage(int page,int y)
{
    write_Cmd(0xB0 | (0x08 |(page & 0x07)));
    write_Cmd(0x40 | (0x3F & y));
}

void setPicture()
{
    
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here

    GLCDInit();   
    while (1)
      {
      // Place your code here


      }
}
