"""specs_s32099.py - h2 (Sonnet) batch 32099: eight tier H float / SSE functions. Float args F(); NaN-able heap floats use nan_heap=True; slots/callees are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _f32(x):
    try:
        return struct.unpack('<f', struct.pack('<f', x))[0]
    except OverflowError:
        return float('inf') if x > 0 else float('-inf')


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def g5a5be0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = _f(e.r32(0x678858))
    o = rnd(c, 0x40)
    hook_rec(c, 0x5ec2b0, 2, this=True, pop=8, side=lambda emu, kk: emu.calllog.append(('call', emu.r8(o + 0x35) if hasattr(emu, 'r8') else 0)))
    me = rnd(c, 0x6a0)
    e.wbytes(me + 0x689, (o if r.random() < 0.85 else 0).to_bytes(4, 'little'))
    cur = r.choice([k - 0.5, k, c.fv(-1, 1), 0.0, _f(NAN)])
    a = r.choice([0.5, 0.0, c.fv(-1, 2), k - cur if cur == cur else 0.0, 1e10])
    e.wbytes(me + 0x68d, _fb(cur).to_bytes(4, 'little'))
    return [me, F(a)]


def g4ef0e0(c):
    clear_hooks(c)
    hook_rec(c, 0x44a1f0, 0, this=True, pop=0, side=_log('a'))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    me = obj(c, 0x20, {0x6c: pystub(c, 1, this=True, deref={0: 9}, side=_log('b'))}, nslots=0x6c // 4 + 1)
    return [me]


def g607c20(c):
    clear_hooks(c)
    r = c.rng
    bufs = [rnd(c, 0xb0), rnd(c, 0x20)]
    if r.random() < 0.2:
        bufs[0] = 0
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: bufs[min(k, 1)], pop=0, side=_log('alloc'))
    hook_rec(c, 0x651850, 0, this=True, pop=0, side=_log('init'))
    return []


def g4a58d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x40, r.randrange(-1000, 100000) & 0xffffffff)
    hook_rec(c, 0x4a5f20, 1, this=True, pop=4, st0=r.choice([-1.5, 0.0, -0.0, 2.5, _f(NAN)]), side=_log('a'))
    hook_rec(c, 0x4a5fe0, 0, this=True, pop=0, side=_log('b'))
    me = rnd(c, 0xc4)
    e.wbytes(me + 0xbb, _fbits(c, -10, 10).to_bytes(4, 'little'))
    return [me]


def g517540(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x515620, 0, this=True, pop=0, side=_log('a'))
    hook_rec(c, 0x5253b0, 5, this=True, pop=0x14, ret=r.getrandbits(32), side=_log('b'))
    me = obj(c, 0x1620, {0x80: pystub(c, 2, this=True, side=_log('c')), 0x36c: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('d'))}, nslots=0x36c // 4 + 1)
    e.wbytes(me + 0x1610, _fbits(c, -5, 5).to_bytes(4, 'little'))
    return [me]


def g58b6d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ks = [_f(e.r32(a)) for a in (0x6ad1fc, 0x67da18, 0x6ad234, 0x68aef8, 0x6ad238)]
    me = rnd(c, 0x10)
    cur = r.choice([c.fv(-1, 1), ks[1], ks[4], ks[1] - 0.1, ks[4] + 0.1, _f(NAN), 0.0, ks[1] * 1.5])
    e.wbytes(me, _fb(cur).to_bytes(4, 'little'))
    a = r.choice([ks[0], ks[0] + 1.0, ks[2], ks[2] - 1.0, c.fv(-5, 5), 0.0, ks[1], _f(NAN), ks[0] - 0.01])
    return [me, F(a)]


def g459980(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    v = r.getrandbits(32)
    e.w32(so + 0x3c, v)
    e.wbytes(so + 0x48, _fbits(c, -10, 10).to_bytes(4, 'little'))
    hook_rec(c, 0x459c40, 1, this=True, pop=4, side=_log('b'))
    o = obj(c, 0x20, {0x4c: pystub(c, 4, this=True, side=_log('a'))}, nslots=0x4c // 4 + 1)
    me = rnd(c, 0x30)
    e.w32(me + 8, rnd(c, 0x60))
    e.w32(me + 0x24, v if r.random() < 0.4 else r.getrandbits(32))
    return [me, o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g51eaf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    r1 = rnd(c, 0x10)
    r2 = rnd(c, 0x10)
    seq = [r1, r2]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 1)], side=_log('a'))
    vt = e.alloc(0x10, 4)
    e.w32(vt, pystub(c, 3, this=True, side=_log('b')))
    base = rnd(c, 0x3b0)
    e.wbytes(base + 0x39f, vt.to_bytes(4, 'little'))
    me = rnd(c, 0x30)
    e.w32(me + 0x18, base)
    a = rnd(c, 0x10)
    e.w32(a + 4, rnd(c, 0x10))
    return [me, a]


S(0x5a5be0, 'GUESS advance fraction clamped to 1.0 and apply', 'thiscall', None, ret=None, gen=g5a5be0, nan_heap=True, note='batch32099')
S(0x4ef0e0, 'GUESS slot 0x6c with constant record on stack', 'thiscall', None, ret=None, gen=g4ef0e0, note='batch32099')
S(0x607c20, 'GUESS allocate and init object with name string', 'cdecl', None, ret='eax', gen=g607c20, note='batch32099')
S(0x4a58d0, 'GUESS elapsed time check then reset', 'thiscall', None, ret=None, gen=g4a58d0, nan_heap=True, note='batch32099')
S(0x517540, 'GUESS refresh via 5253b0 and slots', 'thiscall', None, ret='eax', gen=g517540, nan_heap=True, note='batch32099')
S(0x58b6d0, 'GUESS wrapped angle accumulate', 'thiscall', None, ret='eax', gen=g58b6d0, nan_heap=True, note='batch32099')
S(0x459980, 'GUESS slot 0x4c then update on time change', 'thiscall', None, ret=None, gen=g459980, note='batch32099')
S(0x51eaf0, 'GUESS apply value through embedded object', 'thiscall', None, ret='eax', gen=g51eaf0, note='batch32099')
