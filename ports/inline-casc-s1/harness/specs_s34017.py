"""specs_s34017.py - cascade tier E, batch 34017: 0x54ab90 (kind 1 / 2 / other with the assert hook always set), 0x54c3f0 (factory slot 0x40 returns an object whose slot 8
returns 0/1 and records the 11 initialised descriptor dwords), 0x5219c0 (id null in a fifth of the cases; hooked 0x43e920 writes random dwords through ECX and logs the
dwords EDX points at; the /GS check 0x633654 is a recorder without arguments since the cookie depends on the frame)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g54ab90(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    hook_rec(c, 0x54dff0, 1, this=True)
    st = lambda n: pystub(c, n, this=True)
    me = obj(c, 0x6400, {0x64: st(1), 0x68: st(1), 0x6c: st(1), 0x70: st(0)}, nslots=0x20)
    p = rnd(c, 0x60)
    c.emu.w32(p, r.choice([1, 2, 1, 2, 0, 3, r.getrandbits(32)]))
    return [me, p]


def _g54c3f0(c):
    clear_hooks(c)
    r = c.rng
    desc_log = []

    def side(em, k):
        d = em.arg32(0)
        em.calllog.append(('desc', tuple(em.r32(d + 4 * i) for i in range(12) if i != 6), em.arg32(1)))
    f = obj(c, 0x40, {8: pystub(c, 2, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True), 4: pystub(c, 1, this=True)}, nslots=0x10)
    # slot 8 recorder with a descriptor side effect
    h, _rec = None, None
    from recruits_util import _recorder
    h, _rec = _recorder(c, 2, r.choice([0, 1]) | (r.getrandbits(24) << 8), None, True, (), None, side, None, (0,))
    c.emu.w32(c.emu.r32(f) + 8, c.emu.stub_fn('slot8', h))
    me = obj(c, 0x40, {0x40: pystub(c, 0, ret=f, this=True)}, nslots=0x20)
    return [me]


def _g5219c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0)

    def w3(em, k):
        for i in range(3):
            em.w32(em.reg('ecx') + 4 * i, r.getrandbits(32))
        em.calllog.append(('v', tuple(em.r32(em.reg('edx') + 4 * i) for i in range(3))))
    hook_rec(c, 0x43e920, 1, this='mark', side=w3)

    def side84(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))
    obj84 = obj(c, 0x40, {0x84: pystub(c, 1, this=True, side=side84, stackmark=(0,))}, nslots=0x40)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=obj84, this=True)})
    me = obj(c, 0x80, {0x378: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x100)
    return [me, 0 if r.random() < 0.2 else r.getrandbits(32) | 1]


S(0x54ab90, 'GUESS dispatch on record kind', 'thiscall', None, ret=None, gen=_g54ab90, note='batch34017')
S(0x54c3f0, 'GUESS build descriptor and accept via factory', 'thiscall', None, ret='eax', gen=_g54c3f0, note='batch34017')
S(0x5219c0, 'GUESS lookup object, transformed vector to this', 'thiscall', None, ret=None, gen=_g5219c0, note='batch34017')
