"""specs_s8033.py - residue 18 unported list (docs/20-unclaimed-79.md). Each call gets its own random arguments.
0x4cc5a0 writes the global buffer at 0x700450 (compared as .data). Counts stay below 0x100 (the exe's 0x634047 path is not ported)."""
from pilot import S
import os, sys

def _g6246a0(c):
    head = c.rng.choice([0xed, 0xef, c.rng.getrandbits(8)])
    if head == 0xef:
        tail = [0xbb, c.rng.choice([0xbf, 0xbe, c.rng.getrandbits(8)])]
        b = bytes([0xef] + [c.rng.choice([0xbb, c.rng.getrandbits(8)])] + [c.rng.choice([0xbf, 0xbe, c.rng.getrandbits(8)])] + [c.rng.getrandbits(8)])
    else:
        b = bytes([head, c.rng.getrandbits(8), c.rng.getrandbits(8), c.rng.getrandbits(8)])
    alloc = c.emu.alloc(8, 4)
    c.emu.wbytes(alloc, b + b'\x00' * 4)
    return [c.rng.getrandbits(32), alloc]

def _g4cc5a0(c):
    n = c.rng.randrange(-5, 0x100)
    return [n & 0xffffffff]

S(0x6246a0, '(GUESS) 0x6246a0 UTF-8 prefix test', 'cdecl', None, ret='eax', gen=_g6246a0,
  note='residue 18 unported: returns 1 for ED with bit 5 of the next byte, EF BB BF/BE, else 0')
S(0x4cc5a0, '(GUESS) 0x4cc5a0 fill global buffer with spaces', 'thiscall', None, ret='eax', gen=_g4cc5a0,
  note='residue 18 unported: n spaces at 0x700450 then zero, returns 0x700450 (n below 0x100)')
