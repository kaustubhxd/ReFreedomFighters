"""specs_s293.py - unclaimed area 67: 0x4cc1d0 (return [this]) and 0x4cbec0 (release [this] unless it points at this+4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _first(c):
    o = _rnd(c, 0x40)
    c.emu.w32(o, c.rng.choice([0, 1, 0x1234, c.rng.getrandbits(32)]))
    c.emu.mu.ctl_flush_tb()
    return [o]


def _rel(c):
    o = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(o, o + 4)
    else:
        blk = c.emu.alloc(0x40, 16)
        c.emu.wbytes(blk, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
        c.emu.w32(o, blk)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x4cc1d0, 'FUN_4cc1d0 (firstDword4cc1d0)', 'thiscall', None, ret='eax', gen=_first, note='batch293; [this]')
S(0x4cbec0, 'FUN_4cbec0 (releaseIfNotSelf4cbec0)', 'thiscall', None, ret=None, gen=_rel, note='batch293; ext 0x634273 unless [this] == this+4')
