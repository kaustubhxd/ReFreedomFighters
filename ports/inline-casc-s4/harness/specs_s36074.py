"""specs_s36073.py - cascade s4 batch 36074: 0x50f3e0 / 0x50fc20 (clones of 0x50a770 / 0x50ae00 on table slot 0x138), 0x6474f0 (copy a chain of transform entries)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _common(c, r):
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec0 = rnd(c, 0x10)
    e.wbytes(rec0 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec0, inner if typ == 4 else r.getrandbits(32))
    return rec0


def _g50f3e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec0 = _common(c, r)
    q = rnd(c, 0x10)
    e.wbytes(q + 4, bytes([r.choice([0, 1, 1, 2, 5, 0xff])]))
    recs = [rec0, q]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    val = r.getrandbits(32)

    def s88(em, rr):
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.w32(em.arg32(1), val)
        em.ret(0, 8)
    o = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [p]


def _g50fc20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec0 = _common(c, r)
    rec1 = rnd(c, 0x10)
    recs = [rec1, rec0]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    o = obj(c, 0x20, {0x5c: pystub(c, 3, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [p]


def _g6474f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = [0]

    def mk(addr):
        def h(em, rr):
            em.calllog.append(('fc', addr, em.reg('ecx'), em.reg('edx')))
            em.ret(eax=0, argbytes=0)
        return h
    for a in (0x4df1e0, 0x4de420, 0x4de480, 0x4419f0, 0x441940):
        e.hook(a, mk(a))
    nch = r.choice([1, 1, 2, 3, 4])
    ids = r.sample(range(0, 6), nch)
    A = e.alloc(0x30 * 7 + 8, 16)
    C = e.alloc(0x30 * 7 + 8, 16)
    D = e.alloc(0x30 * 7 + 8, 16)
    for blk in (A, C, D):
        e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x30 * 7 + 8)))
    for i, ix in enumerate(ids):
        e.w32(D + 0x30 * ix + 0xc, ids[i + 1] if i + 1 < nch else 0)
    # the chain must not revisit a zero index as continuation: index 0 only matters as the very first id
    for ix in range(7):
        if ix not in ids:
            e.w32(D + 0x30 * ix + 0xc, 0)
    return [A, ids[0], C, D]


S(0x50f3e0, 'GUESS store a looked-up value into a value record (clone)', 'stdcall', None, ret=None, gen=_g50f3e0, note='batch36074')
S(0x50fc20, 'GUESS send a typed id and value to an engine object (clone)', 'stdcall', None, ret=None, gen=_g50fc20, note='batch36074')
S(0x6474f0, 'GUESS copy a chain of transform entries', 'stdcall', None, ret=None, gen=_g6474f0, note='batch36074')
