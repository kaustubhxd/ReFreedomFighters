"""specs_s33092.py - h3 (Sonnet) batch 33092: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fb(c, lo=-10.0, hi=10.0):
    return _b(c.fv(lo, hi, 0.25))


def _g4f1b80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x20)
    s98 = pystub(c, 3, this=True, ret=lambda em, k: rec)
    s350 = pystub(c, 3, this=True)
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    me = rnd(c, 0xb0)
    vt = e.alloc(0xa0, 4)
    e.w32(vt + 0x350 - 0x350 + 0x98, s98)
    e.w32(me + 0x9f, vt)
    vt2 = e.alloc(0x360, 4)
    e.w32(vt2 + 0x350, s350)
    e.w32(me, vt2)
    return [me, _w(c), _w(c), _w(c), _fb(c), r.choice([0, 1, 0xff, 0x100, _w(c)])]


def _g51c470(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flag = r.random() < 0.7
    s2e0 = pystub(c, 6, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff00, _w(c)]) if not flag else 1)
    o = obj(c, 0x40, {0x2e0: s2e0})
    holder = rnd(c, 0xae4)
    e.w32(holder + 0xadc, o)
    sysobj(c)
    e.w32(e.r32(0x70039c) + 0x9b, holder)
    me = rnd(c, 0x5a0)
    base = r.choice([_fb(c), 0, 0x80000000, 0x7fc00000, _b(5.0)])
    e.w32(me + 0x64, base)
    e.w32(me + 0x552, r.choice([base, _fb(c), _b(1.0), 0x7fc00000]))
    return [me]


def _g530b60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        t = em.reg('ecx')
        em.calllog.append(('edx', em.reg('edx')))
        for i in range(3):
            em.w32(t + 4 * i, r.choice([_b(1.0), _b(2.0), _b(-0.5), _b(0.0), _b(c.fv(-4, 4, 0.1)), _b(1e-30)]))
    hook_rec(c, 0x43e920, 1, this='mark', side=side)
    me = rnd(c, 0x50)
    for off in (6, 0xa, 0xe):
        e.w32(me + off, _fb(c))
    for off in (0x3c, 0x40, 0x44):
        e.w32(me + off, r.choice([0, 1, 16, 255, 1000, 0xffffffff, r.getrandbits(12)]))
    p = rnd(c, 0x10)
    for i in range(3):
        e.w32(p + 4 * i, _fb(c, -100, 100))
    return [me, rnd(c, 8), p]


S(0x4f1b80, 'GUESS register new record via slot 0x98', 'thiscall', None, ret='eax', gen=_g4f1b80, note='batch33092')
S(0x51c470, 'GUESS ray-test reset and distance field', 'thiscall', None, ret='al', gen=_g51c470, note='batch33092')
S(0x530b60, 'GUESS world position to 16-bit grid coords', 'thiscall', None, ret=None, gen=_g530b60, note='batch33092')
