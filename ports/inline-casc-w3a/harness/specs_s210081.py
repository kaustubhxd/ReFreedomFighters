"""specs_s210081.py - Sonnet-w3a: 0x4d3750. Embedded container at this+0x4008 (slots 0x4c, 0x5c with the iterator flag word written by the stubs, 0x44), records {len dword at +0, data at +0xc, dword at -4}, memcmp import at IAT 0x67640c with real comparison."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g4d3750(c):
    clear_hooks(c)
    e = c.emu
    name = bytes(c.rng.choice(b'ab') for _ in range(c.rng.choice([0, 1, 3]))) + b'\0'
    st = rnd(c, 0x20); e.wbytes(st, name)
    explicit = c.rng.random() < 0.4
    ln = c.rng.choice([len(name), 1, 2]) if explicit else 0
    want = ln if ln else len(name)

    def cmpfn(emu, k):
        n = emu.arg32(2)
        return 0 if emu.rbytes(emu.arg32(0), n) == emu.rbytes(emu.arg32(1), n) else 1
    e.w32(0x67640c, pystub(c, 3, ret=cmpfn, pop=0))
    n = c.rng.choice([0, 1, 2, 3])
    recs = []
    for _ in range(n):
        r = rnd(c, 0x40)
        base = rnd(c, 0x40)
        e.w32(r + 4, want if c.rng.random() < 0.6 else c.rng.choice([want + 1, 0, _r(c)]))
        e.wbytes(r + 0x10, (name if c.rng.random() < 0.5 else bytes(c.rng.choice(b'ab') for _ in range(len(name)))) + bytes(4))
        recs.append(r + 4)  # element pointer = r + 4 (so r is element - 4)
    def s4c(emu, k):
        emu.w32(emu.arg32(0), 1)

    def s5c(emu, k):
        emu.w32(emu.arg32(0), 1 if k < n else 0)
    cont_vt = e.alloc(0x80, 4)
    e.w32(cont_vt + 0x4c, pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=s4c))
    e.w32(cont_vt + 0x5c, pystub(c, 1, ret=lambda emu, k: recs[k] if k < n else 0, this=True, stackmark=(0,), side=s5c))
    e.w32(cont_vt + 0x44, pystub(c, 1, ret=_r(c), this=True, stackmark=(0,)))
    hook_rec(c, 0x4ce1c0, 2, ret=_r(c), this=True)
    s = rnd(c, 0x4100)
    e.w32(s + 0x4008, cont_vt)
    e.w32(s + 0x4004, c.rng.choice([0, 0x1000, _r(c)]))
    return [s, st, ln]


S(0x4d3750, 'remove_record_by_bytes', 'thiscall', None, ret='al', gen=g4d3750, note='batch210081')
