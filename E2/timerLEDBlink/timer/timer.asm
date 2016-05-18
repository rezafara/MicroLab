.include "m64def.inc"
.def temp=r16
.def temp2=r19
.org 0x00
	jmp main

.org 0x20
	jmp T0_OVF_ISR

.org 0x60
main:
	ldi temp,low(ramend)
	out spl,temp

	ldi temp,high(ramend)
	out sph,temp
	
	;configuring PORTC to out
	ldi temp,0xff
	out ddrc,temp
	out portc,temp
	;configuring timer
	ldi temp,0x07
	out tccr0,temp
	ldi temp,0x01
	out timsk,temp
	;initializing some register for counting 1 second
	ldi r17,31
	ldi r18,78
	
	;enabling interrupts
	sei

main_loop:
	jmp main_loop

T0_OVF_ISR:
	;Reset timer value
	ldi temp,0x00
	out tcnt0,temp
	;Counting 31 overflows for making 1 second 
	dec r17
	cpi r17,0x00
	brne T0_OVF_ISR_END
	
	;toggling portc
	in  temp,pinc
	ldi temp2,0xff
	eor temp,temp2
	out portc,temp

	;Setting value of r17 to wait for another 1 second
	ldi r17,31

T0_OVF_ISR_END:
	reti
	
