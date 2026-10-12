"""specs_s279.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 leaves: 0x4ce5f0 (counted walk through slots 0x4c
and 0x64) and 0x5ef330 (pair calls through four child objects, slots 4 and 8)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _walk(c):
    e = c.emu
    seq = [c.rng.getrandbits(32) | 1 for _ in range(c.rng.randrange(0, 4))] + [0]
    k = [0]

    def nxt(em, a, seq=seq, k=k):
        v = seq[min(k[0], len(seq) - 1)]
        k[0] += 1
        em.w32(a[0], 1)
        return (v, None)

    vt = e.logging_vtable('walk4ce5f', 0x1a, impl={0x4c: lambda em, a: (em.w32(a[0], 1) or 0, None), 0x64: nxt},
                          argwords={0x4c: 1, 0x64: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt)
    n = c.rng.randrange(0, 4) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [obj, n]


def _pair(c):
    e = c.emu
    self_ = _rnd(c, 0x100)
    e.w8(self_ + 0xa0, c.rng.choice([0, 1]))
    e.w8(self_ + 0xb5, c.rng.choice([0, 1]))
    for off, name in [(0xa9, 'p1'), (0xa1, 'p2'), (0xa5, 'p3')]:
        child_vt = e.logging_vtable('ch5ef' + name, 0x5, impl={}, argwords={4: 2})
        ch = _rnd(c, 0x40)
        e.w32(ch, child_vt)
        e.w32(self_ + off, ch)
    b_vt = e.logging_vtable('ch5efb', 0x5, impl={}, argwords={4: 2, 8: 0})
    b = _rnd(c, 0x40)
    e.w32(b, b_vt)
    e.w32(self_ + 0xb1, b if c.rng.random() < 0.8 else 0)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4ce5f0, 'walkCount (GUESS)', 'thiscall', None, ret='eax', gen=_walk, note='batch279; ret 4')
S(0x5ef330, 'pairCalls (GUESS)', 'thiscall', None, ret=None, gen=_pair, note='batch279; ret 8')
