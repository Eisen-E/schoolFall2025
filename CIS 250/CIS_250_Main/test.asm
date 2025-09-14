INCLUDE Irvine32.inc
.data
.code
main PROC
mov al,255
add al,1
call DumpRegs
sub al,1
call DumpRegs
sub al,1
call DumpRegs
exit
main ENDP
END main