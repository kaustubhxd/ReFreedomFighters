"""specs_s90001.py - 0x5af350 GetNoOf(type): jump table on type-0xc (0xc,0xd -> branch A, 0xe..0x10 -> branch B, else 0). thiscall ret 4.
this[0..2] objects (any may be 0 -> logger at 0x700390 path); hooked callees: 0x5af130 find (ecx = this[1]; returns a cell pointer, 0, or a cell holding 0),
0x5af300 (A tail), 0x4ccba0 constructor (installs a fake list vtable with begin/next), 0x4ccf60 destructor. Sys table slots 0x58 (lookup) and 0x114 (fill list); this[0] slot 0x130; this[2] slot 0x98; looked-up object slot 0x2e8."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab_vt


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x7003b0, 0, ret=r.getrandbits(32))
    logger(c)
    k = r.random()
    typ = r.choice([0xc, 0xd, 0xe, 0xf, 0x10]) if k < 0.85 else r.choice([0, 1, 0xb, 0x11, 0x12, 0xffffffff, 0xfffffff4, r.getrandbits(32)])
    branchB = typ in (0xe, 0xf, 0x10)
    # find result
    cell = c.emu.alloc(4, 4)
    want = r.choice([1, 2, 3, 0x40, r.getrandbits(32)])
    c.emu.w32(cell, 0 if r.random() < 0.1 else want)
    fk = r.random()
    fret = 0 if fk < 0.1 else cell
    hook_rec(c, 0x5af130, 1, this=True, ret=fret)
    hook_rec(c, 0x5af300, 1, this=True, ret=r.getrandbits(32))
    # branch B pieces
    elems = [r.getrandbits(32) for _ in range(r.choice([0, 0, 1, 2, 3, 5, 7]))]
    vt = reftab_vt(c, elems)
    hook_rec(c, 0x4ccba0, 0, this='mark', pop=0, side=lambda em, k, vt=vt: em.w32(em.reg('ecx'), vt))
    hook_rec(c, 0x4ccf60, 0, this='mark', pop=0)
    # looked-up objects: slot 0x2e8 returns want with probability 0.5
    n = r.choice([1, 3, 6])
    seq = [want if r.random() < 0.5 else r.getrandbits(32) for _ in range(8)]
    o_obj = obj(c, 0x40, {0x2e8: pystub(c, 0, this=True, ret=lambda em, k: seq[min(k, 7)])}, nslots=0xc0)
    if branchB or r.random() < 0.8:
        r58 = o_obj
    else:
        r58 = 0
    t58 = pystub(c, 1, this=True, ret=r58)
    t114 = pystub(c, 5, this=True, nullflag=(4,), ret=r.getrandbits(32))
    so = sysobj(c, table_slots={0x58: t58, 0x114: t114})
    a = obj(c, 0x40, {0x130: pystub(c, 2, this=True)}, nslots=0x60)
    o2 = obj(c, 0x40, {0x98: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=0x60)
    lst = rnd(c, 0x20)
    me = rnd(c, 0x20)
    vals = [a, lst, o2]
    for i in range(3):
        if r.random() < 0.12:
            vals[i] = 0
        c.emu.w32(me + 4 * i, vals[i])
    return [me, typ]


S(0x5af350, 'ZFFInventoryBridge::GetNoOf', 'thiscall', None, ret='eax', gen=_g)
