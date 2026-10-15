"""specs_s32100.py - h2 (Sonnet) batch 32100: eight tier H float / SSE functions. NaN-able heap floats use nan_heap=True; slots/callees are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def g522770(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    r1 = rnd(c, 0x10)
    r0 = rnd(c, 0x10)
    e.w32(r1, r.choice([0, 1, r.getrandbits(32)]))
    e.wbytes(r0, _fbits(c, -9, 9).to_bytes(4, 'little'))
    seq = [r1, r0]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 1)], side=_log('a'))
    hook_rec(c, 0x520c50, 2, this=True, pop=8, ret=r.getrandbits(32), side=_log('b'))
    me = rnd(c, 0x30)
    e.w32(me + 0x1c, rnd(c, 0x20))
    a = rnd(c, 0x10)
    e.w32(a + 4, rnd(c, 0x10))
    return [me, a]


def g584f40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=_log('f')), 0x3c: pystub(c, 1, this=True, side=_log('i'))})
    me = rnd(c, 0x80)
    e.wbytes(me + 0x64, _fbits(c, -9, 9).to_bytes(4, 'little'))
    e.wbytes(me + 0x57, _fbits(c, -9, 9).to_bytes(4, 'little'))
    return [me, o]


def g466ce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    e.wbytes(o + 0x88, _fbits(c, -100, 100).to_bytes(4, 'little'))
    p = obj(c, 0x20, {0x84: pystub(c, 1, this=True, side=_log('p'))}, nslots=0x84 // 4 + 1)
    so = sysobj(c, table_slots={0x60: pystub(c, 1, ret=(o if r.random() < 0.75 else 0), this=True)})
    e.w32(so + 0x40, r.randrange(0, 100000))
    e.wbytes(so + 0x1a9f, (p if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    me = rnd(c, 0x150)
    return [me]


def g4a37f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x40, r.randrange(-100, 100000) & 0xffffffff)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x14, pystub(c, 0, ret=r.getrandbits(32), this=True, side=_log('a')))
    me = obj(c, 0x130, {0x84: pystub(c, 1, this=True, side=_log('b')), 0x88: pystub(c, 0, this=True, side=_log('c'))}, nslots=0x88 // 4 + 1)
    e.wbytes(me + 0x78, vt.to_bytes(4, 'little'))
    return [me]


def g4f50f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4ef210, 1, this=True, pop=4, side=_log('a'))
    o = obj(c, 0xd0, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True, side=_log('b'))}, nslots=0x1e0 // 4 + 1)
    return [rnd(c, 0xd0), o]


def g4f8940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = _f(e.r32(0x678620))
    so = sysobj(c)
    t = r.randrange(-50, 50)
    e.w32(so + 0x40, t & 0xffffffff)
    me = rnd(c, 0x1e0)
    fv = r.choice([(t + r.choice([-1, 0, 1, 2])) / k, c.fv(-5, 5), _f(NAN)])
    e.wbytes(me + 0x1cf, _fb(fv).to_bytes(4, 'little'))
    inner = rnd(c, 0x60)
    e.w32(inner + 0x3c, r.choice([0, 0x800, r.getrandbits(32), 0x7ff]))
    ob = obj(c, 0x20, {0xbc: pystub(c, 1, this=True, side=_log('o'))}, nslots=0xbc // 4 + 1)
    e.w32(ob + 8, inner)
    e.wbytes(me + 0x1bf, (ob if r.random() < 0.8 else 0).to_bytes(4, 'little'))
    return [me]


def g51e7b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vt = e.alloc(0x40, 4)
    e.w32(vt + 8, pystub(c, 1, this=True, side=_log('a')))
    e.w32(vt + 0x20, pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True, side=_log('b')))
    e.w32(vt + 4, pystub(c, 3, this=True, side=_log('c')))
    me = rnd(c, 0x2b0)
    e.wbytes(me + 0x29a, vt.to_bytes(4, 'little'))
    e.wbytes(me + 0x272, _fbits(c, -9, 9).to_bytes(4, 'little'))
    e.wbytes(me + 0x26e, _fbits(c, -9, 9).to_bytes(4, 'little'))
    return [me]


def g5d8740(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def w(emu, k):
        emu.w32(emu.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x4db500, 1, this=True, pop=4, nullflag=(0,), side=w)
    hook_rec(c, 0x4db7c0, 1, this=True, pop=4, nullflag=(0,), side=w)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    inner = rnd(c, 0x20)
    e.w32(inner + 8, rnd(c, 0x20))
    me = rnd(c, 0x60)
    e.w32(me + 0x44, inner)
    return [me]


S(0x522770, 'GUESS 5003d0 twice then 520c50 with float and flag', 'thiscall', None, ret='eax', gen=g522770, note='batch32100')
S(0x584f40, 'GUESS clear bit 6, two float slot calls, slot 0x3c, true', 'thiscall', None, ret='al', gen=g584f40, note='batch32100')
S(0x466ce0, 'GUESS prime object timers then notify', 'thiscall', None, ret=None, gen=g466ce0, nan_heap=True, note='batch32100')
S(0x4a37f0, 'GUESS reset state via slots', 'thiscall', None, ret=None, gen=g4a37f0, note='batch32100')
S(0x4f50f0, 'GUESS copy state block when accepted', 'thiscall', None, ret=None, gen=g4f50f0, note='batch32100')
S(0x4f8940, 'GUESS time check then set flag via slot 0xbc', 'thiscall', None, ret=None, gen=g4f8940, nan_heap=True, note='batch32100')
S(0x51e7b0, 'GUESS embedded object update with floats', 'thiscall', None, ret=None, gen=g51e7b0, note='batch32100')
S(0x5d8740, 'GUESS read two floats out of member (GS frame)', 'thiscall', None, ret=None, gen=g5d8740, nan_heap=True, note='batch32100')
