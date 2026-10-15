"""specs_s32122.py - h2 (Sonnet) batch 32122: 0x45ecd0 (x87 distance mix) and 0x4e8c00 (vector pipeline). The small vector helpers run as exe code; 0x4e8c80 and the slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fvec(c, e, p, n, lo=-9, hi=9, nan=0.05):
    r = c.rng
    for i in range(n):
        v = struct.pack('<f', r.uniform(lo, hi)) if r.random() > nan else struct.pack('<I', NAN)
        e.wbytes(p + 4 * i, v)


def g45ecd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(tag):
        def side(emu, k):
            base = emu.arg32(0)
            for i in range(3):
                if r.random() < 0.8:
                    emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
            emu.calllog.append((tag,))
        return side
    me = obj(c, 0x30, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill('a'))}, nslots=0x84 // 4 + 1)
    p = obj(c, 0x30, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill('b'))}, nslots=0x84 // 4 + 1)
    for o in (me, p):
        inner = rnd(c, 0x60)
        e.wbytes(inner + 0x4c, struct.pack('<f', r.choice([r.uniform(0, 5), 0.0, 1.5])))
        e.w32(o + 8, inner)
    return [me, p]


def g4e8c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e8c80, 4, this=True, pop=0x10, ret=r.choice([0, 1, 1, 0x100, r.getrandbits(32)]), deref={1: 3, 2: 3}, side=_log('big'))
    me = rnd(c, 0x60)
    _fvec(c, e, me + 0x18, 12)
    _fvec(c, e, me + 0x3c, 3)
    A = rnd(c, 0x20)
    _fvec(c, e, A, 4)
    B = rnd(c, 0x20)
    _fvec(c, e, B, 3)
    Cv = rnd(c, 0x20)
    _fvec(c, e, Cv, 3)
    return [me, A, B, Cv, r.getrandbits(32)]


S(0x45ecd0, 'GUESS signed gap between two spheres', 'thiscall', None, ret='st0', gen=g45ecd0, nan_heap=True, note='batch32122')
S(0x4e8c00, 'GUESS transform inputs and test through 4e8c80', 'thiscall', None, ret='al', gen=g4e8c00, nan_heap=True, note='batch32122')
