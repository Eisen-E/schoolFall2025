TITLE MASM Template						(main.asm)
;Template Modified by Evan Eisenman for CIS 250 11518 09/13/2025

INCLUDE Irvine32.inc

.data
myMessage BYTE "Hello,Evan Eisenman",0dh,0ah,0 ;message for part one
myPrompt BYTE "Please enter three numbers for the following equation(x+y-z)",0 ;message for user prompt
finalPrompt BYTE "X+Y-Z = ",0 ;message that is used to diplay the final value to the user
userValX SDWORD 0 ;X Value for our math equation
userValY SDWORD 0 ;Y Value for our math equation
userValZ SDWORD 0 ;Z Value for our math equation

.code
main PROC
	mov edx,10
	mov eax,10
	mov ebx,10
	mov ecx,5

	cmp edx,eax
	ja final
	cmp ebx,ecx
	ja T1
	jmp T2
	T1: cmp ebx,edx
	ja final
	jmp T2
	final:
	mov edi,1
	mov userValX,edi
	exit
	T2:	
	mov edi,2
	mov userValX,edi
	exit
main ENDP

END main