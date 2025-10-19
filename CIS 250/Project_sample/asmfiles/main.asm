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
	call Clrscr
	
	;Part one moves myMessage into the EDX register and calls the write string function from irvine32
	mov	 edx,OFFSET myMessage
	call WriteString
	
	;Part two calls the dump regs function 
	call DumpRegs
	
	;Part three and extra credit calls the readint func three times and calculates a value based off the user input
	mov  edx,OFFSET myPrompt ;prompts the user to enter their values
	call WriteString
	mov  al,10
	call WriteChar

	;displays x and wait for the users input and stores it
	mov  al,"X"
	call WriteChar
	call ReadInt
	mov userValX,eax
	
	;displays Y and wait for the users input and stores it
	mov  al,"Y"
	call WriteChar
	call ReadInt
	mov userValY,eax
	
	;displays Z and wait for the users input and stores it
	mov  al,"Z"
	call WriteChar
	call ReadInt
	mov userValZ,eax

	;moves the x val to the eax reg and evaluates based of the two other variables we created
	mov eax,userValX
	add eax,userValY
	sub eax,userValZ
	
	;displays a message to the user displaying the value of equation with the given vars
	mov  edx,OFFSET finalPrompt ;prompts the user to enter their values
	call WriteString
	call WriteDec
	;Assignment asked for another call to dump regs for the basic math portion but not the extra credit added it to be safe
	call DumpRegs
	exit
main ENDP

END main