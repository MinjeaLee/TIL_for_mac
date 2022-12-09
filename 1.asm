.model small
.stack
.data
msg1 db 100 dup(0)
msg2 db 100 dup(0)
msg3 db 'Enter the first string: $'
msg4 db 0ah, 0dh,'Enter the second string: $'
msg5 db 0ah, 0dh,'The strings are equal.$'
msg6 db 0ah, 0dh,'The strings are not equal.$'

.code
main proc
	mov ax, @data
	mov ds, ax
	mov ah, 09h
	lea dx, msg3
	int 21h

	lea dx, msg1
	mov ah, 01h
INPUT1:
	int 21h
	cmp al, 0dh
	jz INPUT2_P
	inc dx
	jmp INPUT1

INPUT2_P:
	lea dx, msg4
	mov ah, 09h
	int 21h
	lea dx, msg2
	mov ah, 01h

INPUT2:
	int 21h
	cmp al, 0dh
	jz COMPARE_INIT
	inc	dx
	jmp INPUT2

COMPARE_INIT: 
mov al, msg1
mov bl, msg2
jmp COMPARE

COMPARE:
	cmp al, bl
	jne NOT_EQUAL
	inc al
	inc bl
	cmp al, 00h
	jne COMPARE
	jmp EQUAL

EQUAL:
	lea dx, msg5
	mov ah, 09h
	int 21h
	jmp END

NOT_EQUAL:
	lea dx, msg6
	mov ah, 09h
	int 21h
	jmp END

END:
	mov ah, 4ch
	int 21h

main endp
end main
