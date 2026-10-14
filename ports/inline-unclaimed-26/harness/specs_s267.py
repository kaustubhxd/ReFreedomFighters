"""specs_s267.py - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list: 0x5be190, keyed flag record that calls
exe find-or-add 0x5be690 (not claimed here; it is batch 265's function, residue 5)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flag(c):
    e = c.emu
    self_ = _rnd(c, 0x1000)
    key_w = c.rng.getrandbits(16)
    e.w16(self_ + 0x914, key_w)
    e.w16(self_ + 0x918, c.rng.getrandbits(16))
    n = c.rng.randrange(0, 6)
    e.w32(self_ + 0x910, n)
    e.w32(self_ + 0x992, c.rng.randrange(0, 9))
    e.w32(self_ + 0x91e, c.rng.getrandbits(16))
    e.w32(self_ + 0x92a, c.rng.randrange(0, 8))
    for k in range(n):
        e.w32(self_ + 0x718 + 5 * k, 0x2000 + k)
        e.w8(self_ + 0x71c + 5 * k, c.rng.choice([0xff, 0, 1, 2, 3]))
    for i in range(4):                       # per-entry counters at 0x54 and 0x85 (base 0x3a * index)
        e.w8(self_ + 0x54 + 0x3a * i, c.rng.randrange(0, 3))
        e.w8(self_ + 0x85 + 0x3a * i, c.rng.choice([0, 1]))
    key = c.rng.choice([0x2000 + c.rng.randrange(max(n, 1)), c.rng.getrandbits(32)])
    w = key_w if c.rng.random() < 0.5 else c.rng.choice([c.rng.getrandbits(16), 0x1234])
    if c.rng.random() < 0.2:
        w = e.r8(self_ + 0x918) | (e.r8(self_ + 0x919) << 8)
    # engine for the find path's full branch
    cc = _rnd(c, 0x40)
    c_vt = e.logging_vtable('cobj5be1', 0x21, impl={0x20: lambda em, a: (0, None)}, argwords={})
    e.w32(cc, c_vt)
    o_vt = e.logging_vtable('eng5be1', 0x59, impl={0x58: lambda em, a: (cc, None)}, argwords={0x58: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    return [self_, w, key]


S(0x5be190, 'flagRecord (GUESS)', 'thiscall', None, ret='eax', gen=_flag, note='batch267; calls exe 0x5be690; ret 8')
