"""specs_s278.py - unclaimed area 67, gap band: a field setter (ret 4), a constructor (returns this), and a conditional clear."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _arg(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


def _obj(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _clear(c):
    inner = _rnd(c, 0x100)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0xc, inner)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.choice([0, 1, 2, 5, c.rng.getrandbits(32)])]


S(0x5f2c30, 'FUN_5f2c30 (setFields2c30)', 'thiscall', None, ret=None, gen=_arg, note='batch278; four fields')
S(0x5f0630, 'FUN_5f0630 (ctor5f0630)', 'thiscall', None, ret='eax', gen=_obj, note='batch278; ctor, returns this')
S(0x5f2b50, 'FUN_5f2b50 (clearA0)', 'thiscall', None, ret=None, gen=_clear, note='batch278; clear [[this+0xc]+0xa0] for a in {0, 1}')
