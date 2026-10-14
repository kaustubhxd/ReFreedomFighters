"""specs_s36060.py - cascade s4 batch 36060: 0x61cd60 (register an item in a growing table)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g61cd60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alloc(em, rr):
        sz = em.arg32(0)
        em.calllog.append(('alloc', sz))
        blk = e.alloc(max(sz, 0x20), 4)
        e.wbytes(blk, bytes([0x44]) * max(sz, 0x20))
        em.ret(eax=0 if fail else blk, argbytes=0)

    def realloc(em, rr):
        old, sz = em.arg32(0), em.arg32(1)
        em.calllog.append(('realloc', old, sz))
        blk = e.alloc(max(sz, 0x20), 4)
        e.wbytes(blk, bytes([0x44]) * max(sz, 0x20))
        e.wbytes(blk, bytes(em.rbytes(old, min(sz, 0x30))))
        em.ret(eax=0 if fail else blk, argbytes=0)
    fail = r.random() < 0.1
    al = e.alloc(0x20, 4)
    e.w32(al + 0xc, e.stub_fn('alloc', alloc))
    e.w32(al + 0x10, e.stub_fn('realloc', realloc))
    n = r.choice([0, 0, 1, 2, 3, 4])
    cap = r.choice([n, n, n + 2, 0 if n == 0 else n])
    tab = e.alloc(0x200, 4)
    e.wbytes(tab, bytes([0x55]) * 0x200)
    ee = rnd(c, 0x20)
    ents = []
    for i in range(n):
        ent = ee if r.random() < 0.2 else rnd(c, 0x20)
        e.w32(tab + 12 * i, ent)
        e.w32(tab + 12 * i + 4, r.getrandbits(32))
        e.w32(tab + 12 * i + 8, r.getrandbits(32))
    if n == 0 and r.random() < 0.5:
        e.w32(tab, ee)
    s = rnd(c, 0x20)
    e.w32(s + 0xc, n)
    e.w32(s + 0x10, cap)
    e.w32(s + 0x14, tab)
    e.w32(s + 8, r.choice([0, 0, 0x1234]))
    e.wbytes(ee + 9, bytes([r.choice([0, 0, 1])]))
    return [s, ee, r.choice([0, 1, 0x100, 0x2, r.getrandbits(32)]), r.choice([0, 1, 1]), r.choice([0, 0, 1, 0x77]), al]


S(0x61cd60, 'GUESS register an item in a growing table', 'cdecl', None, ret='eax', gen=_g61cd60, note='batch36060')
