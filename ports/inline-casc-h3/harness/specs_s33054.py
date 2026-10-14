"""specs_s33054.py - h3 () batch 33054."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g5302(slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        s = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
        vt = e.alloc(0x1c0, 4)
        e.w32(vt + slot, s)
        me = _zeroed(c, 0x5320, 0x40)
        e.w32(me, vt)
        p = rnd(c, 0x100)
        e.w32(p, r.choice([0, 4, 8, 0x10, 0x20, 0x40]))
        e.w32(me + 0x5302, r.choice([p, p, p, 0]))
        return [me, _w(c)]
    return g


def _g554cc0(c):
    clear_hooks(c)
    e = c.emu
    so = sysobj(c)
    s94 = pystub(c, 0, this=True, ret=lambda em, k: rnd(c, 0x20))
    e.w32(so + 0x1aa3, obj(c, 0x100, {0x94: s94}))
    hook_rec(c, 0x642050, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: rnd(c, 0x20))
    hook_rec(c, 0x5002f0, 1, this=True, ret=lambda em, k: _w(c))
    a = rnd(c, 0x20)
    e.w32(a + 8, rnd(c, 0x20))
    return [rnd(c, 0x40), a]


def _g574df0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x610100, 1, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x4e5e60, 0, this=True, side=lambda em, k: em.calllog.append(('o', 2)), ret=lambda em, k: _w(c))
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58})
    return [rnd(c, 0x200), rnd(c, 0x20)]


def _g5e4600(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x488bc0, 0, this=True)
    me = _zeroed(c, 0x700, 0x40)
    s54a = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s54b = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x100, 4)
    e.w32(vt2 + 0x54, s54b)
    s58 = pystub(c, 1, this=True, side=lambda em, k: e.w32(me, vt2), ret=lambda em, k: _w(c))
    vt1 = e.alloc(0x100, 4)
    e.w32(vt1 + 0x54, s54a)
    e.w32(vt1 + 0x58, s58)
    e.w32(me, vt1)
    return [me]


def _g5f94b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 3, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [_w(c), _w(c)]


def _g656460(c):
    clear_hooks(c)
    r = c.rng

    def ret(em, k):
        return rnd(c, 0x20) if k == 0 else rnd(c, 0x100)
    s = pystub(c, 1, this=True, ret=ret)
    return [obj(c, 0x40, {0xc: s}), r.randrange(0, 0x40)]


def _g46e3e0(c):
    clear_hooks(c)
    r = c.rng
    s8c = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    child = obj(c, 0x100, {0x8c: s8c})
    s100 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([child, child, 0]))
    return [obj(c, 0x140, {0x100: s100}), _w(c)]


S(0x536840, 'GUESS rec lookup vcall 1ac', 'thiscall', None, ret='eax', gen=_g5302(0x1ac), note='batch33054')
S(0x536950, 'GUESS rec lookup vcall 1b0', 'thiscall', None, ret='eax', gen=_g5302(0x1b0), note='batch33054')
S(0x554cc0, 'GUESS sysobj vcall 94 and pair 5003d0/5002f0', 'thiscall', None, ret='eax', gen=_g554cc0, note='batch33054')
S(0x574df0, 'GUESS call, id, table lookup store', 'thiscall', None, ret=None, gen=_g574df0, note='batch33054')
S(0x5e4600, 'GUESS vcall 58 store then vcall 54 reread vt', 'thiscall', None, ret='eax', gen=_g5e4600, note='batch33054')
S(0x5f94b0, 'GUESS global vcall 20, log slot 2c, assert hook', 'stdcall', None, ret='eax', gen=_g5f94b0, note='batch33054')
S(0x656460, 'GUESS double vcall c indexed', 'thiscall', None, ret='eax', gen=_g656460, note='batch33054')
S(0x46e3e0, 'GUESS lookup vcall 100 then child vcall 8c', 'thiscall', None, ret='eax', gen=_g46e3e0, note='batch33054')
