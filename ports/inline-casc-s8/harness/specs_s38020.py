"""specs_s38020.py - cascade s8 batch 38020: 0x64c8d0. Owner object (0x10200 random bytes) with a manager at +0x1005d (slots 0x20 returns the index buffer, 0x60; +0x218 = pool whose slot 8 returns fresh
objects; +0x68 = id table), the pending list at +0x1010d (0..5 items whose node's id word at +0x5a is zero about half of the time), the +0x10089 table (0..5 valid objects). The owner's slot 0x1c
(recording stub) installs +0x10151 (holder whose slot 8 returns fresh objects) the way the real initializer does. 0x63eab0 / 0x63f090 / 0x63da80 / 0x648810 / 0x634d10 are hooks; 0x648810
sometimes replaces the node it was given (through its out pointer). The flag byte at +0x10028 is never cleared (the clear branch loops forever by construction)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g64c8d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    buf = e.alloc(0x4000, 4)
    e.wbytes(buf, r.randbytes(0x4000))
    idtab = e.alloc(0x4000, 4)
    e.wbytes(idtab, r.randbytes(0x4000))
    pool_objs = [rnd(c, 0x40) for _ in range(8)]
    hold_objs = [rnd(c, 0x20) for _ in range(8)]
    pool = obj(c, 0x40, {8: pystub(c, 0, this=True, ret=lambda em, k: pool_objs[k % 8])})
    holder = obj(c, 0x40, {8: pystub(c, 0, this=True, ret=lambda em, k: hold_objs[k % 8])})
    mgr = obj(c, 0x300, {0x20: pystub(c, 1, this=True, ret=buf), 0x60: pystub(c, 0, this=True)})
    e.w32(mgr + 0x218, pool)
    e.w32(mgr + 0x68, idtab)

    me = []

    def init_side(em, k):
        m = em.reg('ecx')
        em.w32(m + 0x10151, holder)
    me = obj(c, 8, {0x1c: pystub(c, 0, this=True, side=init_side)})
    # real object: big random block, vtable pointer from the stub vtable
    vtp = e.r32(me)
    big = e.alloc(0x10200, 4)
    e.wbytes(big, r.randbytes(0x10200))
    e.w32(big, vtp)
    me = big
    e.w32(me + 0x1005d, mgr)
    n = r.choice([0, 1, 1, 2, 3, 5])
    e.w32(me + 0x1010d, n)
    for i in range(n):
        node = rnd(c, 0x80)
        e.wbytes(node + 0x5a, struct.pack('<H', 0 if r.random() < 0.5 else r.randrange(1, 0x10000)))
        item = rnd(c, 0x80)
        e.w32(item + 8, node)
        e.w32(me + 0x10111 + 4 * i, item)
    rs = []
    for _ in range(8):
        y = rnd(c, 0x80)
        rr = rnd(c, 0x20)
        e.w32(rr + 0xc, y)
        rs.append(rr)
    k = r.choice([0, 1, 2, 3, 5])
    e.w32(me + 0x10089, k)
    for i in range(k):
        e.w32(me + 0x1008d + 4 * i, rnd(c, 0x80))
    hook_rec(c, 0x63eab0, 1, this=True, pop=4, ret=lambda em, kk: rs[kk % 8])
    hook_rec(c, 0x63f090, 1, this=True, pop=4, ret=lambda em, kk: r.getrandbits(32))
    hook_rec(c, 0x63da80, 1, this=True, pop=4)
    hook_rec(c, 0x634d10, 3, pop=0)
    alts = []
    for _ in range(4):
        z = rnd(c, 0x40)
        w = rnd(c, 0x40)
        e.w32(z + 0xc, w)
        alts.append(z)

    def s648810(em, kk):
        if r.random() < 0.4:
            em.w32(em.arg32(0), r.choice(alts))
    hook_rec(c, 0x648810, 2, this=True, pop=8, stackmark=(0,), side=s648810)
    return [me]


S(0x64c8d0, 'GUESS flush pending object list', 'thiscall', None, ret=None, gen=_g64c8d0, note='batch38020')
