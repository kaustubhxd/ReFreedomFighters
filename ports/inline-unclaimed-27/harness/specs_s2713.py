"""specs_s2713.py - unclaimed-27 batch 13: FUN_466c00 (GUESS name). Object 0x800 random bytes with a vtable whose slot +0x2b4
(one argument, ret 4) is a STUB that records its argument (NOT verified)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f466(c):
    rec = c.emu.alloc(0x10, 4)
    code = b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little') + b'\xc2\x04\x00'   # record [esp+4]; ret 4
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = c.emu.alloc(0x800, 4)
    c.emu.w32(vt + 0x2b4, st)
    o = _rnd(c, 0x800)
    c.emu.w32(o, vt)
    return [o]


S(0x466c00, 'FUN_466c00 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f466,
  note='unclaimed-27 batch 13; slot +0x2b4 is a stub that records its argument')
