"""specs_s1385.py - unclaimed-13 claim 4 (docs/20-unclaimed-13.md): ZMoveOnSpline::CanSee (0x5122c0). The object is 0x800
random bytes; the dword at +0x140 is -1 in about 30% of cases (returns 0), else a small index. The pointer at +0x13c
is a fresh 0x800-byte object. The callee 0x4a9cb0 is original code in both the exe and the port (not stubbed). Its no-match path is not exercised (see below)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _canssee(c):
    o = _rnd(c, 0x800)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x140, 0xffffffff)
    else:
        c.emu.w32(o + 0x140, c.rng.randint(0, 7))
    # The callee's object (0x800 random bytes) holds a table of dwords at +0x54 with stride 8 (it scans 200 entries).
    # Half the time the argument equals one entry, so the match path and the argument are exercised.
    obj = _rnd(c, 0x2000)   # the callee indexes obj + index * 0x1b8 (index up to 7), so it needs more than 0x800 bytes
    # The argument is always an entry of the table, so the callee takes its match path (a bit test on the table's own
    # flags, no further calls). Its no-match path calls through the game's global objects, which are not modelled here
    # (random memory there faults in both the exe and the port), so it is not exercised by this spec.
    k = c.rng.randint(0, 199)
    arg = c.rng.getrandbits(32)
    c.emu.w32(obj + 0x54 + 8 * k, arg)
    c.emu.w32(o + 0x13c, obj)
    return [o, arg]


S(0x5122c0, 'ZMoveOnSpline::CanSee (unknown) thiscall', 'thiscall', None, ret='al', gen=_canssee,
  note='unclaimed-13 claim 4; -1 at +0x140 gives 0, else 0x4a9cb0 (original code)')
