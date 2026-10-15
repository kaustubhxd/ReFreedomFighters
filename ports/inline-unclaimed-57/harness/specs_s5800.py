"""specs_s5800.py - unclaimed-57, batch 100: 0x5c2b00 (GUESS name unnamed_5c2b00). Thiscall, five stack arguments (name, val1, flag, val2, bb;
ret 0x14), no return value, no callees. The table count at this+0x2c0 is 0 to 17 (16 or more means no append). The stored names are pointers into
a small pool of C strings; the argument name is one of the pool strings (so the equal-name path runs in about one case in two) or a new string.
val2 is zero in about two cases in five. The flag and bb arguments are random dwords (only their low bytes matter)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 1)
    c.emu.wbytes(a, text + b'\x00')
    return a


def _c2b00(c):
    e = c.emu
    pool = [_cstr(c, b'alpha'), _cstr(c, b'beta'), _cstr(c, b'gamma'), _cstr(c, b'delta')]
    newname = _cstr(c, b'epsilon')
    self_obj = _rnd(c, 0x400)
    n0 = c.rng.randrange(0, 17)  # the table holds at most 16 names
    e.w32(self_obj + 0x2c0, n0)
    for i in range(min(n0, 16)):
        e.w32(self_obj + 8 + 14 * i, c.rng.choice(pool))
    name = c.rng.choice(pool) if c.rng.random() < 0.5 else newname
    val1 = c.rng.getrandbits(32)
    flag = c.rng.getrandbits(32)
    val2 = 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32)
    bb = c.rng.getrandbits(32)
    return [self_obj, name, val1, flag, val2, bb]


S(0x5c2b00, 'unnamed_5c2b00 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c2b00,
  note='unclaimed-57 batch 100; pure table insert (no callees); names from a pool of C strings')
