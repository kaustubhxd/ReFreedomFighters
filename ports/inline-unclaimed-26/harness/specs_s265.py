"""specs_s265.py - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list: 0x5be690, table find-or-add with an
engine call on the full path (engine+0x9b slots 0x58, then 0x20 and 0x28 on the returned objects)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _find(c):
    e = c.emu
    cap = c.rng.randrange(0, 9)
    n = c.rng.randrange(0, 9)
    self_ = _rnd(c, 0x1000)
    e.w32(self_ + 0x910, n)
    e.w32(self_ + 0x992, cap)
    e.w32(self_ + 0x91e, c.rng.getrandbits(16))
    for k in range(n):                       # some keys are fixed so the find path hits
        e.w32(self_ + 0x718 + 5 * k, 0x1000 + k)
    key = c.rng.choice([0x1000 + c.rng.randrange(max(n, 1)), c.rng.getrandbits(32)])
    r = c.rng.getrandbits(32)
    r_vt = e.logging_vtable('res5be', 0x29, impl={}, argwords={})
    rr = _rnd(c, 0x40)
    e.w32(rr, r_vt)
    c_vt = e.logging_vtable('cobj5be', 0x21, impl={0x20: lambda em, a: (rr, None)}, argwords={})
    cc = _rnd(c, 0x40)
    e.w32(cc, c_vt)
    o_vt = e.logging_vtable('eng5be', 0x59, impl={0x58: lambda em, a: (cc, None)}, argwords={0x58: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    return [self_, key]


S(0x5be690, 'findOrAdd (GUESS)', 'thiscall', None, ret='eax', gen=_find, note='batch265; residue-05 list')
