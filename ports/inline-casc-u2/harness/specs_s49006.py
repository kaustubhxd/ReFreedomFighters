"""specs_s49006.py - cascade u2 batch 49006: 0x513d10. Everything is vtable stubs: engine table object T ([0x70039c]+0x9b: slots 0x4c, 0x58, 0x114; +0xadc an object with slot 0x25c returning
object b with slot 0x100 returning object k with slot 0x84), the owner (this) slots 0x2f0 (float in st0) and 0x130 (records its pointer argument: 2 dwords on odd calls, 4 on even), the item
holder C -> [+0x18] D with slots 0x4c and 0x5c (writes the iterator word: non-zero for n calls, then 0). this+8 points to a block whose +0x40 floats are read by 0x4db7c0 (exe code)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g513d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = c.fv
    n = r.choice([0, 1, 2, 3])
    ret32 = lambda em, k: r.getrandbits(32)

    kobj = obj(c, 0x20, {0x84: pystub(c, 1, this=True, ret=ret32)}, nslots=0x40)
    bobj = obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=lambda em, k: kobj)}, nslots=0x80)
    o1 = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: bobj)}, nslots=0x100)

    def side5c(em, k):
        em.w32(em.arg32(0), r.randrange(1, 1 << 32) if k < n else 0)
    ditem = [rnd(c, 0x10) for _ in range(4)]
    dobj = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,)),
                         0x5c: pystub(c, 1, this=True, nullflag=(0,), side=side5c, ret=lambda em, k: ditem[min(k, 3)])}, nslots=0x30)
    cobj = rnd(c, 0x40)
    e.w32(cobj + 0x18, dobj if r.random() < 0.85 else 0)
    cret = 0 if r.random() < 0.12 else cobj
    T = obj(c, 0xb00, {0x4c: pystub(c, 1, this=True, ret=ret32),
                       0x58: pystub(c, 1, this=True, ret=lambda em, k: cret),
                       0x114: pystub(c, 4, this=True, ret=ret32)}, nslots=0x80)
    e.w32(T + 0xadc, o1)
    so = sysobj(c)
    e.w32(so + 0x9b, T)

    def side130(em, k):
        p = em.arg32(2)
        cnt = 2 if k % 2 == 0 else 4
        em.calllog.append(('s130', k) + tuple(em.r32(p + 4 * i) for i in range(cnt)))
    me = obj(c, 0x160, {0x2f0: pystub(c, 0, this=True, st0=lambda em, k: fv(-10, 10, 0.1)),
                        0x130: pystub(c, 3, this=True, side=side130, stackmark=(2,))}, nslots=0xc0)
    blk = rnd(c, 0x60)
    e.wbytes(blk + 0x40, struct.pack('<fff', fv(-10, 10, 0.1), fv(-10, 10, 0.1), fv(-10, 10, 0.1)))
    e.w32(me + 8, blk)
    return [me]


S(0x513d10, 'GUESS resource lookup and per-item spawn', 'thiscall', None, ret=None, gen=_g513d10, note='batch49006')
