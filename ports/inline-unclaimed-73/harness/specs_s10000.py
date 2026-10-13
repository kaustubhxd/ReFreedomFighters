"""specs_s10000.py - batch 100 simple residue 6 getters.
0x46b6e0 (thiscall, ret al): byte from [this+0xc4]
0x593ae0 (thiscall, ret al): byte from [this+0x828]
0x596ce0 (thiscall, ret eax): dword from [this+0x1fb6]
"""
from pilot import S

def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a

def _gen_46b6e0(c):
    e = c.emu
    this_obj = _rnd(c, 0x200)
    byte_val = c.rng.getrandbits(8)
    e.w8(this_obj + 0xc4, byte_val)
    return [this_obj]

def _gen_593ae0(c):
    e = c.emu
    this_obj = _rnd(c, 0x900)
    byte_val = c.rng.getrandbits(8)
    e.w8(this_obj + 0x828, byte_val)
    return [this_obj]

def _gen_596ce0(c):
    e = c.emu
    this_obj = _rnd(c, 0x2000)
    dw_val = c.rng.getrandbits(32)
    e.w32(this_obj + 0x1fb6, dw_val)
    return [this_obj]

S(0x46b6e0, 'GUESS FUN_0046b6e0 (unknown) thiscall', 'thiscall', 'al', ret='al', gen=_gen_46b6e0,
  note='batch 100; returns byte from [this+0xc4]')

S(0x593ae0, 'GUESS FUN_00593ae0 (unknown) thiscall', 'thiscall', 'al', ret='al', gen=_gen_593ae0,
  note='batch 100; returns byte from [this+0x828]')

S(0x596ce0, 'GUESS FUN_00596ce0 (unknown) thiscall', 'thiscall', 'eax', ret='eax', gen=_gen_596ce0,
  note='batch 100; returns dword from [this+0x1fb6]')
