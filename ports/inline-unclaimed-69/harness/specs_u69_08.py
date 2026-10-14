"""specs_u69_08.py - area 69, group 8 (unclaimed-69 thread)."""
from pilot import S
from ckit import obj, rnd


def _rte(c):
    r = c.rng
    e = c.emu
    seq = [r.choice([0x1000 + 16 * i, r.getrandbits(32) | 1]) for i in range(r.randint(0, 4))]
    tail = list(seq)
    if r.random() < 0.7:
        tail = tail + [0]
    state = {'seq': list(tail)}

    def get(e, t, a):
        v = state['seq'].pop(0) if state['seq'] else 0
        e.wbytes(a[0], (0).to_bytes(4, 'little')) if False else None
        return (v, None, ('get',))

    def set_(e, t, a):
        e.wbytes(a[0], (r.getrandbits(32)).to_bytes(4, 'little'))
        return (0, None, ('set',))
    tbl = obj(e, 'reftab', 0x40, {0x4c: (1, set_), 0x64: (1, get)}, nslots=0x68 // 4)
    if r.random() < 0.1:
        tbl = 0
    key = r.choice(tail + [0x1000, r.getrandbits(32)]) if tail else r.getrandbits(32)
    return [tbl, key]


S(0x4cdfd0, 'REFTAB::Exists', 'thiscall', None, ret='al', gen=_rte, note='u69')
