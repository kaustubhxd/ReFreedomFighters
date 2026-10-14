"""specs_u69_82.py - area 69, residue-8 forwarders to 0x4cbec0 (lea ecx,[ebp-N]; jmp 0x4cbec0). Same empty-list-only coverage as 0x664202 (specs_u69_80.py).
EBP is passed as an argument through the ('regs', ['ebp']) ABI with a buffer in emulator memory. The target 0x4cbec0 is real."""
from pilot import S
from ckit import rnd


def _frame(off):
    def gen(c):
        e = c.emu
        buf = rnd(c, 0x200)
        ebp = buf + 0x100
        head = ebp - off
        e.w32(head, head + 4)   # empty list: first == &sentinel
        return [ebp]
    return gen

S(0x664346, 'fwd664346 (forwarder to 0x4cbec0, lea ebp-0x90)', ('regs', ['ebp']), None, ret=None, gen=_frame(0x90), note='u69 group 82; empty-list path only')
S(0x664fc7, 'fwd664fc7 (forwarder to 0x4cbec0, lea ebp-0x90)', ('regs', ['ebp']), None, ret=None, gen=_frame(0x90), note='u69 group 82; empty-list path only')
S(0x665d88, 'fwd665d88 (forwarder to 0x4cbec0, lea ebp-0x90)', ('regs', ['ebp']), None, ret=None, gen=_frame(0x90), note='u69 group 82; empty-list path only')
S(0x666000, 'fwd666000 (forwarder to 0x4cbec0, lea ebp-0x90)', ('regs', ['ebp']), None, ret=None, gen=_frame(0x90), note='u69 group 82; empty-list path only')
S(0x666dc0, 'fwd666dc0 (forwarder to 0x4cbec0, lea ebp-0x90)', ('regs', ['ebp']), None, ret=None, gen=_frame(0x90), note='u69 group 82; empty-list path only')
S(0x668bc0, 'fwd668bc0 (forwarder to 0x4cbec0, lea ebp-0x90)', ('regs', ['ebp']), None, ret=None, gen=_frame(0x90), note='u69 group 82; empty-list path only')
S(0x6672c7, 'fwd6672c7 (forwarder to 0x4cbec0, lea ebp-0xa8)', ('regs', ['ebp']), None, ret=None, gen=_frame(0xa8), note='u69 group 82; empty-list path only')
