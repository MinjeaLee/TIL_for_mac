from pwn import *

#  nc host3.dreamhack.games 8538
p = remote('host3.dreamhack.games', 8538)


p.interactive()