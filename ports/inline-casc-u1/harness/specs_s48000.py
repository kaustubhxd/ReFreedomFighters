"""specs_s48000.py - tier H. 0x4ed840: base cell + record r (kind word, id word at +0x50, object id at +0x4c), engine object with table slots 0x58/0x54, placed object slots 0x37c/0x378,
hooked 0x4df330 (ecx, edx, 4 args), q->slot 0x20 (records the 9+3 floats it is given), /GS check keeping eax. Float boxes: v = (e+0x90)-(r+0x28) against w = (e+0xa8)+(r+0x40), cases inside, outside, NaN, edge."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _fb(x):
    return struct.pack('<f', x)


def _fval(r, lo=-20, hi=20):
    k = r.random()
    if k < 0.12:
        return r.choice(EDGE_F)
    if k < 0.16:
        return struct.unpack('<f', struct.pack('<I', r.getrandbits(32)))[0]
    return r.uniform(lo, hi)


def _g4ed840(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda e, k: e.reg("eax"))

    def edx_rec(e, k):
        e.w32(scratch + 4 * min(k, 7), e.reg('edx'))
    scratch = em.alloc(40, 4)
    hook_rec(c, 0x4df330, 4, this=True, ret=lambda e, k: r.choice([0, 1, 1, 1, 0x100, 0xff00, r.getrandbits(32)]), side=edx_rec)

    # placed object (returned by slot 0x58): slot 0x37c bit 0, slot 0x378(1, 0)
    bit = r.choice([0, 0, 0, 1, 2, 3, 0x100, 0xff01, r.getrandbits(32)])
    pobj = obj(c, 0x40, {0x37c: pystub(c, 0, ret=bit, this=True), 0x378: pystub(c, 2, this=True)}, nslots=0x380 // 4)
    o2 = rnd(c, 0x90)
    has_o2 = r.random() < 0.7
    q = obj(c, 0x40, {0x20: pystub(c, 4, ret=lambda e, k: r.choice([0, 1, 1, 0x100, r.getrandbits(32)]), this=True, deref={1: 9, 2: 3})}, nslots=0x24 // 4)
    A = rnd(c, 0x40)
    em.w32(A + 0x18, q)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=pobj, this=True),
                                0x54: pystub(c, 1, ret=(o2 if has_o2 else 0), this=True)})
    em.wbytes(so + 0x1aa3, A.to_bytes(4, 'little'))

    # record
    rr = rnd(c, 0x60)
    kind = r.choice([0, 0, 1, 2, r.getrandbits(32)])
    em.w32(rr, kind)
    em.w32(rr + 0x50, r.choice([0, 1, 5, r.getrandbits(32)]))
    # e object
    e = rnd(c, 0xc0)
    off = r.choice([0, 0x20, 0x100, r.getrandbits(32)]) & 0xffffffff
    cell = em.alloc(8, 4)
    em.w32(cell, (rr - off) & 0xffffffff)
    em.w32(e + 0x5c, off)
    # float boxes
    p = [_fval(r) for _ in range(3)]
    mode = r.random()
    for i in range(3):
        em.wbytes(rr + 0x28 + 4 * i, _fb(p[i]))
        if mode < 0.55:      # inside the box mostly
            w = abs(_fval(r, 0, 5))
            d = r.uniform(-w, w) * r.choice([1, 1, 1.01, 0.99])
            em.wbytes(e + 0x90 + 4 * i, _fb(p[i] + d if abs(p[i]) < 1e30 else p[i]))
            em.wbytes(e + 0xa8 + 4 * i, _fb(w))
            em.wbytes(rr + 0x40 + 4 * i, _fb(0.0))
        elif mode < 0.8:
            em.wbytes(e + 0x90 + 4 * i, _fb(_fval(r)))
            em.wbytes(e + 0xa8 + 4 * i, _fb(_fval(r, 0, 10)))
            em.wbytes(rr + 0x40 + 4 * i, _fb(_fval(r, 0, 10)))
        else:
            em.wbytes(e + 0x90 + 4 * i, _fb(p[i]))   # equal -> v = 0
            em.wbytes(e + 0xa8 + 4 * i, _fb(r.choice([0.0, -0.0, 1.0, -1.0])))
            em.wbytes(rr + 0x40 + 4 * i, _fb(0.0))
    # list
    n = r.choice([0, 1, 3, 8])
    lst = em.alloc(0x60, 4)
    em.wbytes(lst, bytes(r.getrandbits(8) for _ in range(0x60)))
    em.w32(e + 0x60, lst)
    em.w32(e + 0x68, n)
    end = (lst + 4 * n)
    em.w32(e + 0x64, (end + r.choice([-4, 0, 4, 8, 0x20, -0x1000, 0x7fffffff])) & 0xffffffff)
    if r.random() < 0.05:
        em.w32(e + 0x64, r.getrandbits(32))
    return [cell, e]


S(0x4ed840, 'GUESS try add placed object to list with float box test', 'fastcall', None, ret='al', gen=_g4ed840, nan_heap=True, note='batch48000')
