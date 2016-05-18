.include "m64def.inc"
.def temp=r16
.org 0x00
rjmp main

main:
	//Setting up stack pointer
	ldi temp,low(ramend)
	out spl,temp

	ldi temp,high(ramend)
	out sph,temp

	//Set PORTC to output
	ldi temp,0xff
	out ddrc,temp

	//Setting initial value to be shifted
	ldi temp,0x01

shift:
	//Every time set PORTC to last shifted value
	out PORTC,temp
	rol temp
	cpi temp,0x00
	brne delay
	//Avoid extra delay in case of temp = 0x00
	ldi temp,0x01

delay:
	//41*150*128 ~0.8 mega instruction
	//0.8*10* (1/8MHz) = 1 Second
	ldi r18,41
	ldi r19,150
	ldi r20,128

time_wasting:
	dec r20
	brne time_wasting
	dec r19
	brne time_wasting
	dec r18
	brne time_wasting
	rjmp shift
