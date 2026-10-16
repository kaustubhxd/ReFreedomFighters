"""specs_s266.py - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list: 0x439bd0, walk over a REFTAB-like
object's slots 0x4c and 0x64, calling this->vtbl[4] on each entry."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ovr(c):
    e = c.emu
    if c.rng.random() < 0.15:
        return [_rnd(c, 0x40), 0]
    seq = [c.rng.getrandbits(32) | 1 for _ in range(c.rng.randrange(0, 4))] + [0]
    k = [0]

    def nxt(em, a, seq=seq, k=k):
        v = seq[min(k[0], len(seq) - 1)]
        k[0] += 1
        return (v, None)

    t_vt = e.logging_vtable('ref439', 0x1a, impl={0x64: nxt}, argwords={0x4c: 1, 0x64: 1})
    t = _rnd(c, 0x40)
    e.w32(t, t_vt)
    this_vt = e.logging_vtable('this439', 2, impl={}, argwords={4: 1})
    self_ = _rnd(c, 0x40)
    e.w32(self_, this_vt)
    return [self_, t]


S(0x439bd0, 'overrideActions (GUESS)', 'thiscall', None, ret=None, gen=_ovr, note='batch266; residue-05 list')
