"""specs_s33052.py - h3 (Sonnet) batch 33052."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g50a410(c):
    clear_hooks(c)
    s0 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    a = obj(c, 0x40, {0: s0})
    s38 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x80, {0x38: s38}), a]


def _g5217c0(c):
    clear_hooks(c)
    r = c.rng
    s = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, _w(c)]))
    me = _zeroed(c, 0x2700, 0x40)
    vt = c.emu.alloc(0x320, 4)
    c.emu.w32(vt + 0x310, s)
    c.emu.w32(me, vt)
    return [me, _w(c)]


def _g54e920(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x54e600, 1, this=True)
    e.w32(0x6763b0, pystub(c, 2, pop=0, ret=lambda em, k: _w(c)))
    return [rnd(c, 0x300), _w(c)]


def _g5ceb30(c):
    clear_hooks(c)
    e = c.emu
    me = rnd(c, 0xb80)
    for i, a in enumerate((0x5d0df0, 0x5d2eb0, 0x5d1530, 0x5d28c0, 0x5ce0b0)):
        def side(em, k, i=i):
            em.calllog.append(('call', i, em.r32(em.reg('ecx')) if False else em.rbytes(me + 0xb46, 1)[0]))
        hook_rec(c, a, 0, this=True, side=side)

    def side2(em, k):
        em.calllog.append(('call', 5, em.rbytes(me + 0xb46, 1)[0]))
    hook_rec(c, 0x5d1ea0, 0, this=True, side=side2, ret=lambda em, k: _w(c))
    return [me]


def _g656900(c):
    clear_hooks(c)
    s0c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s144 = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x40, {0xc: s0c, 0x144: s144}), _w(c), _w(c)]


def _g4739b0(c):
    clear_hooks(c)
    r = c.rng
    s = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x260, {0x230: s})
    a = r.choice([-5, -1, 0, 1, 2, 3, 4, 100, 0x7fffffff, 0x80000000]) & 0xffffffff
    return [me, a]


def _g47fb70(c):
    clear_hooks(c)
    r = c.rng
    s0c = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, _w(c)]))
    child = obj(c, 0x40, {0xc: s0c})
    s14 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x40, {0x14: s14})
    c.emu.w32(me + 4, r.choice([child, child, 0]))
    return [me]


def _g51f780(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = _zeroed(c, 0x1700, 0x40)
    vt = e.alloc(0x320, 4)

    def side(em, k):
        em.calllog.append(('f', em.r32(me + 0x16d5)))
    s = pystub(c, 1, this=True, side=side, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, _w(c)]))
    e.w32(vt + 0x310, s)
    e.w32(me, vt)
    e.w32(me + 0x1654, _w(c))
    return [me, _w(c)]


S(0x50a410, 'GUESS vcall then call arg vtable slot 0', 'thiscall', None, ret='eax', gen=_g50a410, note='batch33052')
S(0x5217c0, 'GUESS store arg if vcall true', 'thiscall', None, ret=None, gen=_g5217c0, note='batch33052')
S(0x54e920, 'GUESS call then import call store', 'thiscall', None, ret=None, gen=_g54e920, note='batch33052')
S(0x5ceb30, 'GUESS five calls then tail', 'thiscall', None, ret='eax', gen=_g5ceb30, note='batch33052')
S(0x656900, 'GUESS vcall c then vcall 144', 'thiscall', None, ret='eax', gen=_g656900, note='batch33052')
S(0x4739b0, 'GUESS clamped index vcall 230', 'thiscall', None, ret='eax', gen=_g4739b0, note='batch33052')
S(0x47fb70, 'GUESS child check then tail vcall', 'thiscall', None, ret=None, gen=_g47fb70, note='batch33052')
S(0x51f780, 'GUESS set flag then clear if vcall false', 'thiscall', None, ret=None, gen=_g51f780, note='batch33052')
