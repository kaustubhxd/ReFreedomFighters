"""specs_s288.py - unclaimed area 76 (docs/20-unclaimed-76.md): 0x561cb0, word-keyed branch with four engine 0x114 queries.
Exe helpers 0x4f21f0 and 0x4f1520 run as original code; the engine object's 0x114 is a logged stub with the query keys."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _branchy(c):
    e = c.emu
    keys = {0x6a6684: 0x488, 0x6a6698: 0x492, 0x6a66a8: 0x497, 0x6a66b8: 0x49c}
    ans = {k: c.rng.getrandbits(16) for k in keys}      # the word each key returns this case
    if c.rng.random() < 0.6:                            # make one answer match the argument word
        ans[c.rng.choice(list(keys))] = c.rng.getrandbits(16)
    w = c.rng.choice(list(ans.values()) + [c.rng.getrandbits(16), 0x8000, 0x8000])
    r88 = c.rng.choice([0, 1, 7])

    def q114(em, a):
        return (ans.get(a[0], 0), None)

    o_vt = e.logging_vtable('eng561', 0x47, impl={0x114: q114}, argwords={0x114: 4})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(eng + 0x30, c.rng.randrange(-5000, 5000) & 0xffffffff)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x200)
    e.w16(self_ + 0x74, c.rng.getrandbits(16) if c.rng.random() < 0.7 else w)
    e.w8(self_ + 0x85, c.rng.choice([0, 1]))
    e.w8(self_ + 0x87, c.rng.getrandbits(8))
    e.w32(self_ + 0x44, c.rng.getrandbits(32))
    x_vt = e.logging_vtable('x561', 0x300 // 4 + 1, impl={0x84: lambda em, a: (0, None)}, argwords={0x2fc: 1})
    x = _rnd(c, 0x40)
    e.w32(x, x_vt)
    self_vt = e.logging_vtable('self561', 0xe2, impl={0x84: lambda em, a: (x, None), 0x88: lambda em, a: (r88, None)},
                               argwords={0x84: 0, 0xe0: 0, 0x88: 1})
    e.w32(self_, self_vt)
    p = _rnd(c, 0x20) if c.rng.random() < 0.8 else 0
    return [self_, w & 0xffffffff, p]


S(0x561cb0, 'branchy (GUESS)', 'thiscall', None, ret='eax', gen=_branchy, note='batch288; ret 8; exe 0x4f21f0, 0x4f1520')
