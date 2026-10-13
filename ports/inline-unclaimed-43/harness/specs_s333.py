"""specs_s333.py - area 71 batch 333: 0x507ee0, thiscall, one stack argument, ret 4. The argument's +4 is a two-level array
(as in batch 305); element 0 is read through the exe helper 0x5003d0. The byte at (this+0x18)+0x776 becomes 1 when that dword
is nonzero, else 0. Half the elements are zero."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _array(c, n):
    data = c.emu.alloc(8 * n + 16, 8)
    c.emu.wbytes(data, bytes(c.rng.getrandbits(8) for _ in range(8 * n + 16)))
    c.emu.w32(data, c.rng.choice([0, 1, c.rng.getrandbits(32)]))   # the boundary value 1 is drawn explicitly
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
    c.emu.w32(this + 0x18, tgt)
    arg = E.zero_obj(c, 0x40)
    c.emu.w32(arg + 4, _array(c, r.randrange(1, 4)))
    c.emu.mu.ctl_flush_tb()
    return [this, arg]


S(0x507ee0, 'flag from element 0 nonzero (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 71 batch 333 (leaf, residue 10); array helper 0x5003d0 is original exe code')
