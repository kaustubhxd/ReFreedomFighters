"""specs_s66080.py - cascade s4 batch 66080: 0x5db4f0 (write a header and a list of float / id records to a stream writer)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, reftab_vt


def _g5db4f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    w = obj(c, 0x40, {0x64: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True)})
    n = r.choice([0, 1, 2, 4])
    recs = []
    for i in range(n):
        rec = e.alloc(0x20, 8)
        e.w32(rec, r.getrandbits(32))
        e.w32(rec + 9, r.getrandbits(32))
        recs.append(rec)
    base = reftab_vt(c, list(recs), count=n)
    vt = e.alloc(0x100, 4)
    for off in (0x14, 0x4c, 0x5c):
        e.w32(vt + off, int.from_bytes(bytes(e.rbytes(base + off, 4)), 'little'))
    lst = e.alloc(0x20, 8)
    e.w32(lst, vt)
    t = e.alloc(0x100, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(t + 0x84, lst)
    return [t, w]


S(0x5db4f0, 'GUESS write a header and a list of float / id records to a stream writer', 'thiscall', None, ret='al', gen=_g5db4f0, note='batch66080')
