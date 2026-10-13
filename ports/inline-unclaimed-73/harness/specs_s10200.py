"""specs_s10200.py - batch 102 setter.
0x521760 (thiscall, ret 4): sets [this+0x133] and [this+0x24ca] to argument
"""
from pilot import S

def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a

def _gen_521760(c):
    e = c.emu
    this_obj = _rnd(c, 0x2500)  # Need at least 0x24ca+1 bytes
    arg = c.rng.getrandbits(8)
    return [this_obj, arg]

S(0x521760, 'GUESS FUN_00521760 (unknown) thiscall', 'thiscall', 'al', ret=None, gen=_gen_521760,
  note='batch 102; sets [this+0x133] and [this+0x24ca] to argument')
