.model small
.stack
.data
msg1 db 100 dup(?)
msg2 db 100 dup(?)
msg3 db 'Enter the first string: $'
msg4 db 0ah, 0dh,'Enter the second string: $'
msg5 db 0ah, 0dh,'The strings are equal.$'
msg6 db 0ah, 0dh,'The strings are not equal.$'

.code
main proc
mov ax, @data
mov ds, ax



main endp
end main
