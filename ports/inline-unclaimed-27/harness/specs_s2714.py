"""specs_s2714.py - unclaimed-27 batch 14: CSpriteBorder2D::SetHeight (0x5edb00, thiscall, ret 4) and FUN_45d380 (GUESS,
thiscall, ret 8). SetHeight's object is 0x800 random bytes; the argument equals the stored value in about a third of cases
(so the no-change path runs). FUN_45d380's object has a vtable whose slot +0x16c (two arguments, ret 8) is a stub that
records both (NOT verified). The return value (eax) is compared for FUN_45d380."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sbh(c):
    o = _rnd(c, 0x800)
    if c.rng.random() < 0.33:
        v = c.emu.r32(o + 0xe3)
    else:
        v = c.rng.getrandbits(32)
    return [o, v]


def _f380(c):
    rec = c.emu.alloc(0x10, 4)
    code = (b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little')
            + b'\x8b\x44\x24\x08\xa3' + (rec + 4).to_bytes(4, 'little') + b'\xc2\x08\x00')
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = c.emu.alloc(0x800, 4)
    c.emu.w32(vt + 0x16c, st)
    o = _rnd(c, 0x800)
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()   # the stub was written into heap memory that may hold translated code from an earlier case
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5edb00, 'CSpriteBorder2D::SetHeight (unknown) thiscall', 'thiscall', None, ret=None, gen=_sbh,
  note='unclaimed-27 batch 14')
S(0x45d380, 'FUN_45d380 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f380,
  note='unclaimed-27 batch 14; slot +0x16c is a stub that records its two arguments')
