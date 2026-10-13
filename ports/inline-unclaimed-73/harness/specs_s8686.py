"""specs_s8686.py - residue 6 batch 86 (GUESS name). FUN_005ec5a0 (thiscall, one stack argument a, ret 4): p = the dword at this+0x3a;
[this+0x42] = a; [p] = a. The spec gives this+0x3a a valid buffer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x60)
    buf = _rnd(c, 0x40)
    e.w32(o + 0x3a, buf)
    return [o, c.rng.getrandbits(32)]


S(0x5ec5a0, 'GUESS FUN_005ec5a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='residue 6 batch 86; p = [this+0x3a]; [this+0x42] = a; [p] = a; ret 4')
