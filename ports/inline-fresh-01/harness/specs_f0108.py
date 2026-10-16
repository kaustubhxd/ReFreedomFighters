"""specs_f0108.py - fresh-01 batch 8 (docs/20-fresh-01.md). Pointers to the caller's stack are never logged; stubs
log what they read through them."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _engine(c, n=0x200):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _render(c, impl=None, argw=None):
    eng = _engine(c)
    r = obj(c, 0x20, 'render', 0x60, impl or {}, argw or {})
    c.emu.w32(eng + 0x9b, r)
    return r


def _link(c):
    els = [rnd(c, 4), rnd(c, 4)]
    hk(c, 0x5003d0, 'elem', 1, eax=lambda e: els[e.arg32(0) & 1])
    k = c.rng.random()
    is1 = c.rng.random() < 0.7
    g0 = obj(c, 0x20, 'g0', 0xb0, {0x1e0: lambda e, a: (int(is1), None)}, {0x1e0: 1, 0x288: 3})
    g1 = rnd(c, 0x20)
    v0, v1 = c.emu.r32(els[0]), c.emu.r32(els[1])
    _render(c, {0x58: lambda e, a: ((g0 if k > 0.15 else 0) if a[0] == v0 else (g1 if k < 0.85 else 0), None)}, {0x58: 1})
    p = rnd(c, 0x10)
    return [rnd(c, 0x10), p]


def _dtor(c):
    _render(c, {}, {0x34: 1})
    o = rnd(c, 0x60)
    c.emu.w32(o + 0x48, obj(c, 0x10, 'owned', 4, {}, {0: 1}) if c.rng.random() < 0.7 else 0)
    return [o]


def _list(c):
    n = c.rng.choice([0, 1, 2, 4])
    st = {'k': 0}
    vals = [c.rng.getrandbits(32) for _ in range(3 * n)]

    def mk(slot, size):
        def h(e, r):
            v = vals[st['k']] if st['k'] < len(vals) else 0
            st['k'] += 1
            e.calllog.append(('load', slot))
            e.w32(e.arg32(0), v)
            e.ret(argbytes=4)
        return h

    def s14(e, r):
        e.calllog.append(('count',))
        e.w32(e.arg32(0), n)
        e.ret(argbytes=4)
    ld = rnd(c, 0x20)
    c.emu.w32(ld, c.emu.fake_vtable('load', 0x20, {0x14: s14, 0x40: mk(0x40, 4), 0x50: mk(0x50, 4)}))
    ob = obj(c, 0x20, 'obj', 0x30, {}, {0x98: 3})
    return [ld, ob]


def _ostr(c):
    c.emu.w32(0x724768, c.rng.choice([0, 1]))
    hk(c, 0x604ca0, 'setup', 0)
    buf = rnd(c, 0x10)
    hk(c, 0x41e290, 'new', 1, eax=buf, regs=(), pop=False)
    return [rnd(c, 0x20)]


def _iterlist(c, n):
    ids = [c.rng.getrandbits(32) for _ in range(n)]

    def s4c(e, r):
        e.calllog.append(('begin', e.reg('ecx')))
        e.wbytes(e.arg32(0), struct.pack('<III', 1, 0, 0x77))
        e.ret(argbytes=4)

    def s5c(e, r):
        p = e.arg32(0)
        i = e.r32(p + 4)
        e.calllog.append(('next', e.reg('ecx'), e.r32(p), i, e.r32(p + 8)))
        if i < n:
            e.w32(p + 4, i + 1)
            e.ret(eax=ids[i], argbytes=4)
        else:
            e.w32(p, 0)
            e.ret(eax=0xdead, argbytes=4)
    lst = rnd(c, 0x20)
    c.emu.w32(lst, c.emu.fake_vtable('list', 0x20, {0x4c: s4c, 0x5c: s5c}))
    return lst, ids


def _gfor(c, slot, argw):
    lst, ids = _iterlist(c, c.rng.randint(0, 4))
    geoms = {i: obj(c, 0x20, 'g', 0x90, {}, {slot: argw}) for i in ids if c.rng.random() < 0.7}
    _render(c, {0x58: lambda e, a: (geoms.get(a[0], 0), None)}, {0x58: 1})
    return lst


def _send(c):
    hk(c, 0x45faf0, 'ZGEOM::SendCommandRecursive', 3)
    lst = _gfor(c, 0x138, 3)
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x18, lst if c.rng.random() < 0.85 else 0)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gate(c):
    hk(c, 0x4dc630, 'SetControl', 2)
    lst = _gfor(c, 0x214, 0)
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x1c, lst if c.rng.random() < 0.85 else 0)
    return [o]


def _censize(c):
    g = rnd(c, 0x60)
    for off in (0x40, 0x44, 0x48):
        c.emu.wf32(g + off, c.rng.choice([0.0, -1.0, 1e-5, 0.0001220703125, 0.0002, 5.0, float('nan'), c.fv()]))
    hk(c, 0x4da1d0, 'CalcCenSize', 1)

    def sz(e, r):
        e.calllog.append(('SetSize', e.reg('ecx'), e.rbytes(e.arg32(0), 12).hex()))
        e.ret(argbytes=4)
    c.emu.hook(0x4dd060, sz)
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, g)
    return [o]


def _fill(c):
    c.emu.w32(0x701a78, c.rng.choice([0, 0, 1]))

    def res(e, r):
        p = e.reg('ecx')
        e.calllog.append(('reserve', e.rbytes(p, 13).hex(), e.arg32(0)))
        e.w32(p, 0x5000)
        e.w32(p + 4, 0x5000)
        e.w32(p + 8, 0x5000 + 4 * e.arg32(0))
        e.ret(argbytes=4)

    def dt(e, r):
        e.calllog.append(('~vector', e.rbytes(e.reg('ecx'), 13).hex()))
        e.ret()

    def s1c(e, r):
        p = e.arg32(0)
        e.calllog.append(('fill', e.rbytes(p, 13).hex()))
        e.w32(p + 4, 0x5010)
        e.ret(argbytes=4)
    c.emu.hook(0x59a9b0, res)
    c.emu.hook(0x4ff9d0, dt)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('self', 0x10, {0x1c: s1c}))
    return [o]


S(0x50dad0, 'link geoms 0x50dad0', 'thiscall', None, ret=None, gen=_link)
S(0x5c3f10, 'destructor 0x5c3f10', 'thiscall', None, ret=None, gen=_dtor)
S(0x49a5d0, 'ZLoadGame list read 0x49a5d0', 'thiscall', None, ret=None, gen=_list)
S(0x604650, 'OpaqueString_t::OpaqueString_t', 'thiscall', None, ret='eax', gen=_ostr)
S(0x44a710, 'ZLIST::SendCommandRecursive', 'thiscall', None, ret=None, gen=_send)
S(0x449310, 'ZGateLightMaster::Enable', 'thiscall', None, ret=None, gen=_gate)
S(0x453090, 'ZGATE::CalcCenSize', 'thiscall', None, ret=None, gen=_censize)
S(0x522c50, 'fill vector 0x522c50', 'thiscall', None, ret=None, gen=_fill)
