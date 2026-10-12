"""specs_s1030.py - unclaimed-04 batch 30 (docs/20-unclaimed-04.md): 0x4022f0 (cdecl, object and n). When n != 0 and the
signed sum (dword +0x18) + n exceeds the signed dword +0x30, returns -131 and leaves the object alone. Otherwise adds n to
+0x18 and returns 0. The spec's fields cover the bound and overflow-adjacent values."""
from pilot import S


def _args(c):
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    lo = c.rng.choice([0, 5, -5, 0x7ffffff0, -0x7ffffff0, c.rng.randrange(-100, 100)]) & 0xffffffff
    hi = c.rng.choice([0, 10, 0x7ffffff0, -1, c.rng.randrange(-100, 100)]) & 0xffffffff
    c.emu.w32(o + 0x18, lo)
    c.emu.w32(o + 0x30, hi)
    n = c.rng.choice([0, 1, -1, 7, 0x7fffffff, -0x80000000, c.rng.randrange(-200, 200)]) & 0xffffffff
    return [o, n]


S(0x4022f0, 'unknown::checked_counter_advance (unknown) cdecl', 'cdecl', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 30; bounded counter at +0x18 against +0x30 (GUESS)')
