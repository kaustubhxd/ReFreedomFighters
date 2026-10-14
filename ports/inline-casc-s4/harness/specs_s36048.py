"""specs_s36048.py - cascade s4 batch 36048: 0x4f60e0 (create and configure a child), 0x4f7f20 (read a record from a stream), 0x502e30 (typed value to a callback)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g4f60e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc630, 2, this=True)
    sub = rnd(c, 0x20)
    ch = obj(c, 0x20, {0x154: pystub(c, 0, this=True), 0x27c: pystub(c, 1, this=True), 0x248: pystub(c, 1, this=True),
                       0x284: pystub(c, 1, this=True), 0x158: pystub(c, 0, this=True)})
    e.w32(ch + 8, sub)
    mgr = obj(c, 0x20, {0x298: pystub(c, 5, this=True, ret=ch if r.random() < 0.85 else 0)})
    bobj = rnd(c, 0x20) if r.random() < 0.85 else 0
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=bobj)})
    d = rnd(c, 0x90)
    s = e.alloc(16, 4)
    e.wbytes(s, (b'%' if r.random() < 0.5 else b'x') + b'name\0' + bytes(8))
    return [d, mgr, s, r.getrandbits(32)]


def _g4f7f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {'k': 0}

    def mk(width, slot):
        def h(em, rr):
            ptr = em.arg32(0)
            cnt['k'] += 1
            em.calllog.append(('stream', slot, em.reg('ecx')))
            em.wbytes(ptr, bytes(((cnt['k'] * 37 + i * 11 + slot) & 0xff) for i in range(width)))
            em.ret(0, 4)
        return h
    s = obj(c, 0x80, {0x40: e.stub_fn('s40', mk(4, 0x40)), 0x48: e.stub_fn('s48', mk(4, 0x48)),
                      0x50: e.stub_fn('s50', mk(4, 0x50)), 0x70: e.stub_fn('s70', mk(28, 0x70))})
    hook_rec(c, 0x4fa230, 1, this=True, ret=r.choice([0, 1, 1, 1, 0x100]))
    d = rnd(c, 0x100)
    return [d, s]


def _g502e30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    _assert_hook(c)
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec0 = rnd(c, 0x10)
    rec1 = rnd(c, 0x10)
    rec2 = rnd(c, 0x10)
    e.wbytes(rec1 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec1, inner if typ == 4 else r.getrandbits(32))
    recs = [rec1, rec2, rec0]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 2)])
    w = obj(c, 0x20, {0x12c: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, deref={4: 1}, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    s = rnd(c, 0x20)
    e.w32(s + 0xc, w)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [s, p]


S(0x4f60e0, 'GUESS create and configure a child', 'thiscall', None, ret='eax', gen=_g4f60e0, note='batch36048')
S(0x4f7f20, 'GUESS read a record from a stream (2)', 'thiscall', None, ret='al', gen=_g4f7f20, note='batch36048')
S(0x502e30, 'GUESS typed value to a callback (2)', 'thiscall', None, ret=None, gen=_g502e30, note='batch36048')
