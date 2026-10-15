"""specs_s66072.py - cascade s4 batch 66072: 0x5bdd30 (deep copy of a record table)."""
from pilot import S
from recruits_util import clear_hooks


def _g5bdd30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alloc(em, rr):
        em.calllog.append(('alloc', em.arg32(0)))
        em.ret(eax=e.alloc(max(min(em.arg32(0), 0x400), 16), 8), argbytes=0)
    e.hook(0x41e290, alloc)
    n = r.choice([0, 1, 2, 5, 0xf0000001, 0x80000000])
    cnt = n if n < 100 else 3
    s = e.alloc(0x40, 8)
    e.wbytes(s, bytes(r.getrandbits(8) for _ in range(0x20)))
    e.w32(s + 8, n)
    e.w32(s + 0xc, e.alloc(16 * cnt + 16, 8))
    e.w32(s + 0x10, e.alloc(4 * cnt + 16, 8))
    e.w32(s + 0x14, e.alloc(4 * cnt + 16, 8))
    for off, sz in ((0xc, 16), (0x10, 4), (0x14, 4)):
        p = int.from_bytes(bytes(e.rbytes(s + off, 4)), 'little')
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(sz * cnt)))
    t = e.alloc(0x40, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [t, s]


S(0x5bdd30, 'GUESS deep copy of a record table', 'thiscall', None, ret='eax', gen=_g5bdd30, note='batch66072')
