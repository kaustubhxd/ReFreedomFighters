"""specs_s282.py - unclaimed area 67, gap band: 0x5f28e0 (store v at [[this+0xc]+0xa0] for a == 0, +0xa4 for a == 1)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _case(c):
    inner = _rnd(c, 0x100)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0xc, inner)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.choice([0, 1, 2, 5, c.rng.getrandbits(32)]), c.rng.getrandbits(32)]


S(0x5f28e0, 'FUN_5f28e0 (storeSelected28e0)', 'thiscall', None, ret=None, gen=_case, note='batch282; a == 0 -> +0xa0, a == 1 -> +0xa4')
