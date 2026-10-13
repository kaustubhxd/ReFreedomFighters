"""specs_s8181.py - residue 6 batch 81 (GUESS name). FUN_0065c9e0 (thiscall, plain ret): old = [this+4]; [this+4] = old + 8; returns old."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x40)
    e.w32(o + 4, c.rng.getrandbits(32))
    return [o]


S(0x65c9e0, 'GUESS FUN_0065c9e0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='residue 6 batch 81; old=[this+4]; [this+4]=old+8; returns old')
