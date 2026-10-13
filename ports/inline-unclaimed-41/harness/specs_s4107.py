"""specs_s4107.py - unclaimed-41 batch 7 (slice 13, loop): 0x5ab9d0 (thiscall, no arguments, returns ebx in eax).

The list at this+0x6e..this+0x72 has 0 to 4 entries of 16 bytes. Entry e: [e] is a pointer value (nonzero 70%), [e+8] = P with
P+8 = Q (heap objects). this+0x6a is a heap object in 70% of cases.
Helpers (checksum stubs, GUESS): 0x4db7c0 (one stack argument, the out pointer, which is a stack address and is excluded from the
checksum; it writes a random float there, in [-50, 50]); 0x5ac660 (two stack arguments, the second 0; ret 8); 0x5ebde0 (one
stack argument; returns a random eax). The float constant at 0x680a60 is read from the exe. Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _loop(c):
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], writes=[(1, 0, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0])])
    ss.patch(c, 0x4db7c0, s)
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2])
    ss.patch(c, 0x5ac660, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=c.rng.getrandbits(32))
    ss.patch(c, 0x5ebde0, s)
    self_ = _rnd(c, 0x100)
    n = c.rng.randint(0, 4)
    lst = c.emu.alloc(16 * max(n, 1), 16)
    c.emu.wbytes(lst, bytes(c.rng.getrandbits(8) for _ in range(16 * max(n, 1))))
    for i in range(n):
        e = lst + 16 * i
        c.emu.w32(e, _rnd(c, 0x20) if c.rng.random() < 0.7 else 0)
        p = _rnd(c, 0x20)
        q = _rnd(c, 0x20)
        c.emu.w32(p + 8, q)
        c.emu.w32(e + 8, p)
    c.emu.w32(self_ + 0x6e, lst)
    c.emu.w32(self_ + 0x72, lst + 16 * n)
    c.emu.w32(self_ + 0x6a, _rnd(c, 0x40) if c.rng.random() < 0.7 else 0)
    return [self_]


S(0x5ab9d0, 'loopSum5ab9d0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_loop,
  note='unclaimed-41 batch 7; helpers 0x4db7c0, 0x5ac660, 0x5ebde0 are checksum stubs (GUESS)')
