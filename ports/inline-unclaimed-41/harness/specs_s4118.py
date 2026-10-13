"""specs_s4118.py - unclaimed-41 batch 18 (slice 13): 0x5ed510 (thiscall, two stack arguments P, Q; ret 8; returns eax of 0x5ecd80).

P: a 0x100-byte object whose vtable slots +0 and +4 are checksum stubs returning random ints. self: 0x100 random bytes with
M = [+0xe7] and N = [+0xeb] in 0..3 (the branches), D = [+0xdf], E = [+0xe3] random ints, the floats at +0xd7 and +0xdb random in
[-100, 100], [+0xef] and [+0xf3] random ints; self+0x3a -> Q (Q+4 -> a 0x200-byte list); self+0x62 -> arr of 9 entry pointers (0x40
bytes each, random); self+0x52 and +0x56 random ints. The batch-16 function 0x5ec390 is original code (it writes the list and the entries).
0x5ec120 (three arguments), 0x5ed2b0 (three arguments, returns a random eax) and 0x5ecd80 (two arguments, returns a random eax) are
checksum stubs (GUESS). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0]


def _layout(c):
    s, _, _ = hs.stub(c, 3, ecx=False, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x5ec120, s)
    s, _, _ = hs.stub(c, 3, ecx=False, edx=False, ret=c.rng.getrandbits(32))
    ss.patch(c, 0x5ed2b0, s)
    s, _, _ = hs.stub(c, 2, ecx=False, edx=False, ret=c.rng.getrandbits(32))
    ss.patch(c, 0x5ecd80, s)

    vt = c.emu.alloc(0x40, 4)
    for off in (0, 4):
        st, _, _ = hs.stub(c, 0, ecx=True, edx=False, ret=c.rng.getrandbits(32))
        c.emu.w32(vt + off, st)
    P = _rnd(c, 0x100)
    c.emu.w32(P, vt)

    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0xe7, c.rng.randint(0, 3))
    c.emu.w32(self_ + 0xeb, c.rng.randint(0, 3))
    c.emu.w32(self_ + 0xdf, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0xe3, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0xd7, _f(c))
    c.emu.w32(self_ + 0xdb, _f(c))
    c.emu.w32(self_ + 0xef, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0xf3, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x52, c.rng.getrandbits(32) if c.rng.random() > 1 / 6 else 0)
    c.emu.w32(self_ + 0x56, c.rng.getrandbits(32) if c.rng.random() > 1 / 6 else 0)
    q = _rnd(c, 0x40)
    c.emu.w32(q + 4, _rnd(c, 0x200))
    c.emu.w32(self_ + 0x3a, q)
    arr = c.emu.alloc(4 * 9, 4)
    for i in range(9):
        c.emu.w32(arr + 4 * i, _rnd(c, 0x40))
    c.emu.w32(self_ + 0x62, arr)
    return [self_, P, c.rng.getrandbits(32)]


S(0x5ed510, 'fn5ed510 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 18; 0x5ec120, 0x5ed2b0, 0x5ecd80 are checksum stubs (GUESS); 0x5ec390 is original code')
