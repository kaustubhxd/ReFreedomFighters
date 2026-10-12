"""specs_s277.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 small leaves: 0x5edb70 (four stack args, a key
store) and 0x4dc970 (word store of a signed division by 7, using engine+0x9b -> +8 -> vtbl[0x4c])."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _key(c):
    e = c.emu
    self_ = _rnd(c, 0x200)
    vals = [c.rng.getrandbits(32) for _ in range(4)]
    if c.rng.random() < 0.5:                 # the early-return path: the four fields already match
        e.w32(self_ + 0xe7, vals[0])
        e.w32(self_ + 0xeb, vals[1])
        e.w32(self_ + 0xef, vals[2])
        e.w32(self_ + 0xf3, vals[3])
    return [self_] + vals + [c.rng.getrandbits(32)]


def _div(c):
    e = c.emu
    r = c.rng.getrandbits(32)
    child_vt = e.logging_vtable('kid4dc', 0x14, impl={0x4c: lambda em, a: (r, None)}, argwords={})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    o = _rnd(c, 0x40)
    e.w32(o + 8, child)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x80)
    a = c.rng.choice([0, c.rng.randrange(0, 1 << 16), c.rng.getrandbits(32)])
    return [self_, a]


S(0x5edb70, 'setKey (GUESS)', 'thiscall', None, ret=None, gen=_key, note='batch277; five stack args (fifth unread); ret 0x14')
S(0x4dc970, 'divSeven (GUESS)', 'thiscall', None, ret=None, gen=_div, note='batch277; ret 4')
