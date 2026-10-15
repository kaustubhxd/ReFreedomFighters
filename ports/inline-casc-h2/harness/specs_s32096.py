"""specs_s32096.py - h2 (Sonnet) batch 32096: eight tier H float / SSE functions. Float args F(); NaN-able heap floats use nan_heap=True."""
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
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def g4edeb0(c):
    clear_hooks(c)
    return [rnd(c, 0x20), rnd(c, 0x40)]


def g572df0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x572720, 0, this=True, pop=0, ret=r.getrandbits(32))
    so = sysobj(c)
    k = _f(e.r32(0x678620))
    t = r.randrange(-50, 50)
    e.w32(so + 0x40, t & 0xffffffff)
    me = rnd(c, 0x880)
    e.wbytes(me + 0x86c, bytes([r.choice([0, 1, 1, 1])]))
    for off in (0x50, 0x58):
        want = t + r.choice([-1, 0, 0, 1, 2, -5])
        cand = _f32(want / k) if k else 0.0
        if r.random() < 0.5:
            for _ in range(8):   # nudge until int(trunc(cand*k)) == t exactly (boundary t == a)
                prod = _f32(cand * k)
                if int(prod) == t:
                    break
                cand = _f32(cand + (1e-4 if int(prod) < t else -1e-4))
        e.wbytes(me + off, _fb(r.choice([cand, c.fv(-10, 10), _f(NAN), 1e30, -1e30])).to_bytes(4, 'little'))
    return [me]


def g467c40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    e.wbytes(o + 0x88, _fbits(c, -100, 100).to_bytes(4, 'little'))
    so = sysobj(c, table_slots={0x60: pystub(c, 1, ret=(o if r.random() < 0.75 else 0), this=True)})
    e.w32(so + 0x40, r.getrandbits(32) if r.random() < 0.3 else r.randrange(0, 100000))
    return [rnd(c, 0x150)]


def g52a220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dcd70, 1, this=True, pop=4, ret=r.getrandbits(32))
    me = rnd(c, 0x70)
    s_parts = [c.fv(-5, 5) for _ in range(3)]
    e.wbytes(me + 0x61, _fb(s_parts[0]).to_bytes(4, 'little'))
    e.wbytes(me + 0x44, _fb(s_parts[1]).to_bytes(4, 'little'))
    ssum = _f32(_f32(_f32(s_parts[0]) + _f32(s_parts[1])) + _f32(s_parts[2]))
    lo = r.choice([-3.0, 0.0, c.fv(-5, 5), ssum, ssum, -1e30, _f(NAN)])
    hi = r.choice([3.0, c.fv(-5, 5), 1e30, ssum - 1.0, ssum - 1.0, _f(NAN)])
    e.wbytes(me + 0x28, _fb(lo).to_bytes(4, 'little'))
    e.wbytes(me + 0x2c, _fb(hi).to_bytes(4, 'little'))
    inner = rnd(c, 0x20)
    e.w32(inner + 8, rnd(c, 0x20))
    e.w32(me + 0x18, inner)
    return [me, F(s_parts[2])]


def g655ca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 0x40)
    e.wbytes(p + 0xc, bytes([r.choice([0, 1, 2, 3, 4, 0xff])]))
    e.wbytes(p + 0x1c, _fbits(c, -50, 50).to_bytes(4, 'little'))
    return [p, rnd(c, 0x10), rnd(c, 0x10)]


def g47f680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = rnd(c, 0x10)
    B = rnd(c, 0x10)
    for i in range(3):
        v = _fbits(c, -3, 3)
        e.wbytes(A + 4 * i, v.to_bytes(4, 'little'))
        w = r.choice([v, v, v, _fbits(c, -3, 3), 0x80000000 if v == 0 else v, 0 if v == 0x80000000 else v])
        e.wbytes(B + 4 * i, w.to_bytes(4, 'little'))
    return [A, B]


def g5a40e0(c):
    clear_hooks(c)
    r = c.rng
    seq = [r.getrandbits(32) for _ in range(2)]
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=_f(_fb(c.fv(-100, 100))), side=_log('f'))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: seq[min(k, 1)], side=_log('i'))
    return [rnd(c, 0x130), rnd(c, 0x20)]


def g475940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x1c, pystub(c, 8, ret=r.getrandbits(32), this=True))
    me = rnd(c, 0x300)
    e.wbytes(me + 0x2e7, vt.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32), F(c.fv(-10, 10)), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4edeb0, 'GUESS bind source record', 'thiscall', None, ret=None, gen=g4edeb0, note='batch32096')
S(0x572df0, 'GUESS tail to 572720 when time passed', 'thiscall', None, ret=None, gen=g572df0, note='batch32096')
S(0x467c40, 'GUESS prime looked-up object timers', 'thiscall', None, ret='eax', gen=g467c40, nan_heap=True, note='batch32096')
S(0x52a220, 'GUESS clamped sum then tail 4dcd70', 'thiscall', None, ret='eax', gen=g52a220, nan_heap=True, note='batch32096')
S(0x655ca0, 'GUESS fill outputs from float field', 'stdcall', None, ret='al', gen=g655ca0, nan_heap=True, note='batch32096')
S(0x47f680, 'GUESS vec3 equality (register ABI)', 'fastcall', None, ret='al', gen=g47f680, note='batch32096')
S(0x5a40e0, 'GUESS copy float and two ints from source', 'thiscall', None, ret=None, gen=g5a40e0, note='batch32096')
S(0x475940, 'GUESS forward to embedded object slot 0x1c', 'thiscall', None, ret='eax', gen=g475940, note='batch32096')
