"""specs_s328.py - area 71 batch 328: 0x5582a0, thiscall, one stack argument, ret 4. The argument's +4 is a two-level array
(as in batch 305); element 0 (exe 0x5003d0) gives a dword that is stored at (this+0x1c)+0x949. Both targets are random blocks."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _array(c, n):
    data = c.emu.alloc(8 * n + 16, 8)
    c.emu.wbytes(data, bytes(c.rng.getrandbits(8) for _ in range(8 * n + 16)))
    t = E.zero_obj(c, 0x20)
    c.emu.w32(t, data)
    c.emu.w32(t + 8, n)
    a = E.zero_obj(c, 0x20)
    c.emu.w32(a, t)
    c.emu.w32(a + 4, 0)
    c.emu.w32(a + 8, n)
    return a


def _gen(c):
    r = c.rng
    this = E.zero_obj(c, 0x40)
    tgt = E.zero_obj(c, 0x1000)
    c.emu.wbytes(tgt, bytes(r.getrandbits(8) for _ in range(0x1000)))
    c.emu.w32(this + 0x1c, tgt)
    arg = E.zero_obj(c, 0x40)
    c.emu.w32(arg + 4, _array(c, r.randrange(1, 4)))
    c.emu.mu.ctl_flush_tb()
    return [this, arg]


S(0x5582a0, 'store element 0 dword at +0x949 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 71 batch 328 (leaf, residue 10); array helper 0x5003d0 is original exe code')
