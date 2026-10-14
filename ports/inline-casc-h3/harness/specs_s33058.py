"""specs_s33058.py - h3 () batch 33058."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g4b1800(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: r.choice([0, 1, _w(c)]))
    s = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s})
    return [rnd(c, 0x80), rnd(c, 0x20)]


def _g4c3220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        if r.random() < 0.7:
            em.w32(em.arg32(0), _w(c))
    s40 = pystub(c, 1, this=True, nullflag=(0,), side=side)
    a = obj(c, 0x80, {0x40: s40})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58})
    me = rnd(c, 0x80)
    e.w32(me + 4, _w(c))
    return [me, a]


def _g4cfae0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x6762ec, pystub(c, 1, pop=0))
    me = rnd(c, 0x1e0)
    n = r.choice([0, 1, 2, 3, 5])
    e.w32(me + 0x1c8, n)
    for i in range(n):
        blk = rnd(c, 0x20)
        e.w32(me + 8 + 4 * i, blk + 4 + r.choice([0, 4]))
    return [me]


def _gg(string_slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        so = sysobj(c)
        s2e8a = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
        s2e8b = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
        vt2 = e.alloc(0x400, 4)
        e.w32(vt2 + 0x2e8, s2e8b)
        vt1 = e.alloc(0x400, 4)
        e.w32(vt1 + 0x2e8, s2e8a)
        me = rnd(c, 0x200)
        e.w32(me, vt1)
        s60 = pystub(c, 2, this=True, side=lambda em, k: e.w32(me, vt2), ret=lambda em, k: _w(c))
        g_ = obj(c, 0x80, {0x60: s60})
        e.w32(so + 0x1a9f, r.choice([g_, g_, 0]))
        return [me]
    return g


def _g560530(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 7, 0x30, 0x31, 0x32, 0x33, 0x40])
    e.w32(0x714198, n)
    for i in range(0x34):
        e.w32(0x7141a0 + 4 * i, _w(c))

    def ah(e2, res_):
        e2.calllog.append(('assert', e2.r32(0x714198)))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    s44 = pystub(c, 1, this=True)
    me = obj(c, 0x80, {0x44: s44})
    return [me, _w(c)]


def _g56d100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562e90, 2, this=True)
    so = sysobj(c)
    s14 = pystub(c, 1, this=True)
    e.w32(so + 0x1907, r.choice([obj(c, 0x40, {0x14: s14}), 0]))
    me = _zeroed(c, 0x200, 0x100)
    e.w32(me + 0x1c6, _w(c) | 1)
    return [me, _w(c), r.choice([0, 1, 0x100, 0x1ff, _w(c)])]


def _g5d05b0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x4de7a0, 0, this='mark')
    me = _zeroed(c, 0xc00, 0x80)

    def side(em, k):
        em.calllog.append(('f', em.r32(me + 0xb15)))
    e.w32(me + 0x44, rnd(c, 0x20))
    hook_rec(c, 0x591ae0, 0, this=True, side=side, ret=lambda em, k: _w(c))
    return [me]


S(0x4b1800, 'GUESS flag and table lookup word', 'thiscall', None, ret=None, gen=_g4b1800, note='batch33058')
S(0x4c3220, 'GUESS vcall 40 with arg slot ptr', 'thiscall', None, ret='al', gen=_g4c3220, note='batch33058')
S(0x4cfae0, 'GUESS free pointer stack via import', 'thiscall', None, ret=None, gen=_g4cfae0, note='batch33058')
S(0x518790, 'GUESS sysobj lookup 60 then vcall 2e8', 'thiscall', None, ret='eax', gen=_gg(0x69f178), note='batch33058')
S(0x5217f0, 'GUESS sysobj lookup 60 then vcall 2e8 b', 'thiscall', None, ret='eax', gen=_gg(0x69f188), note='batch33058')
S(0x560530, 'GUESS global stack push', 'thiscall', None, ret='eax', gen=_g560530, note='batch33058')
S(0x56d100, 'GUESS call then optional sysobj vcall', 'thiscall', None, ret='al', gen=_g56d100, note='batch33058')
S(0x5d05b0, 'GUESS init tmp and store call result', 'thiscall', None, ret=None, gen=_g5d05b0, note='batch33058')
