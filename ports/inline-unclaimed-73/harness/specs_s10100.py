"""specs_s10100.py - batch 101 simple residue 6 setters.
0x5aede0 (thiscall, ret this): sets [this]=0
0x4e1b60 (thiscall, ret this): multi-field setter
"""
from pilot import S

def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a

def _gen_5aede0(c):
    e = c.emu
    this_obj = _rnd(c, 0x100)
    # Pre-fill with random value
    e.w32(this_obj, c.rng.getrandbits(32))
    return [this_obj]

def _gen_4e1b60(c):
    e = c.emu
    this_obj = _rnd(c, 0x100)
    # Pre-fill with random values
    e.w32(this_obj + 0x34, c.rng.getrandbits(32))
    e.w32(this_obj + 0x44, c.rng.getrandbits(32))
    e.w8(this_obj + 0x6c, c.rng.getrandbits(8))
    return [this_obj]

S(0x5aede0, 'GUESS FUN_005aede0 (unknown) thiscall', 'thiscall', 'this', ret='this', gen=_gen_5aede0,
  note='batch 101; sets [this]=0, returns this')

S(0x4e1b60, 'GUESS FUN_004e1b60 (unknown) thiscall', 'thiscall', 'this', ret='this', gen=_gen_4e1b60,
  note='batch 101; multi-field setter, returns this')
