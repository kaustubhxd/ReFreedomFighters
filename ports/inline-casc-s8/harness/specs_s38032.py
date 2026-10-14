"""specs_s38032.py - cascade s8 batch 38032. n = 0..7 (pairs of (key 0..4, source index = a permutation of 0..n-1 so the chain walk terminates), records of 0x28 bytes); qsort (IAT 0x676450) is a
logging Python stub that sorts the pairs by the first dword (the comparator's order); *out1 / *out2 are null half of the time (then the engine object's slots 0x34 / 0x38 hand out zeroed tables), else
preallocated tables; the owner (null 40%) has slot 0x218 (3 args), otherwise the engine object's slot 0x108 does; 0x4f9520 hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4f9350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4, 5, 7])
    perm = list(range(n))
    r.shuffle(perm)
    pairs = e.alloc(8 * max(n, 1) + 8, 4)
    e.wbytes(pairs, b''.join(struct.pack('<II', r.choice([0, 1, 1, 2, 3, 4]), perm[i]) for i in range(n)))
    recs = e.alloc(0x28 * max(n, 1) + 8, 4)
    e.wbytes(recs, r.randbytes(0x28 * max(n, 1) + 8))

    def qs(em, res_):
        base, cnt, sz, cmp_ = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        em.calllog.append(('qsort', base, cnt, sz, cmp_))
        items = [em.rbytes(base + sz * i, sz) for i in range(cnt)]
        items.sort(key=lambda b: struct.unpack('<i', b[:4])[0])
        for i, b in enumerate(items):
            em.wbytes(base + sz * i, b)
        em.ret(eax=0, argbytes=0)
    e.w32(0x676450, e.stub_fn('qsort', qs))

    def tab(size):
        def h(em, k):
            p = em.alloc(size + 0x40, 4)
            em.wbytes(p, bytes(size + 0x40))
            return p
        return h
    g = n + 2
    f = obj(c, 0x40, {0x34: pystub(c, 1, this=True, ret=tab(4 * g)), 0x38: pystub(c, 1, this=True, ret=tab(8 * g + 8)),
                      0x108: pystub(c, 3, this=True, ret=lambda em, k: r.getrandbits(32))})
    so = sysobj(c, {})
    holder = rnd(c, 0x40)
    e.w32(holder + 0x18, f)
    e.wbytes(so + 0x1aa3, struct.pack('<I', holder))
    owner = 0 if r.random() < 0.4 else obj(c, 0x40, {0x218: pystub(c, 3, this=True, ret=lambda em, k: r.getrandbits(32))})
    cell1 = e.alloc(4, 4)
    cell2 = e.alloc(4, 4)
    if r.random() < 0.5:
        e.w32(cell1, 0)
        e.w32(cell2, 0)
    else:
        b1 = e.alloc(4 * g + 0x40, 4)
        e.wbytes(b1, r.randbytes(4 * g + 0x40))
        b2 = e.alloc(8 * g + 0x40, 4)
        e.wbytes(b2, r.randbytes(8 * g + 0x40))
        e.w32(cell1, b1)
        e.w32(cell2, b2)
    hook_rec(c, 0x4f9520, 1, this=True, pop=4)
    return [pairs, recs, cell1, cell2, n, r.getrandbits(32), owner]


S(0x4f9350, 'GUESS sort and group keyed records', 'fastcall', None, ret='eax', gen=_g4f9350, note='batch38032')
