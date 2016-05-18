.include "m64def.inc" // library contain registers and addresses
.def temp=r16
.org 0x00
rjmp Main
.org 0x60 // after all registers of micro
;---------------------Main Function--------------------;
Main:
	ldi temp,low(ramend)
	out spl,temp
	ldi temp, high(ramend)
	out sph,temp //Stack Pointer ini
	ldi temp,0xff
	out ddrc,temp //Portc „³ Output
	ldi temp,0xff
	out portc,temp //Portc =11111111

finish: //infinite loop
	rjmp finish
