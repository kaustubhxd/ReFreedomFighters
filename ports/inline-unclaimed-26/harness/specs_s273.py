"""specs_s273.py - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list: 0x4ce550, out-parameter walk through
slots 0x4c and 0x5c of the object."""
from pilot import S


def _walk(c):
    e = c.emu
    seq = [(c.rng.choice([1, 1, 0]), c.rng.getrandbits(32)) for _ in range(c.rng.randrange(0, 5))] + [(0, c.rng.getrandbits(32))]
    k = [0]

    def out5c(em, a, seq=seq, k=k):
        lv, x = seq[min(k[0], len(seq) - 1)]
        k[0] += 1
        em.w32(a[0], lv)
        return (x, None)

    def out4c(em, a):
        em.w32(a[0], 1)
        return (0, None)

    vt = e.logging_vtable('walk4ce', 0x18, impl={0x4c: out4c, 0x5c: out5c}, argwords={0x4c: 1, 0x5c: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt)
    n = c.rng.randrange(0, 4) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [obj, n]


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


S(0x4ce550, 'walk (GUESS)', 'thiscall', None, ret='eax', gen=_walk, note='batch273; residue-05 list; ret 4')
