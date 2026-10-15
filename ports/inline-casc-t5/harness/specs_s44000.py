"""specs_s44000.py - t5 (Sonnet) batch 44000: 0x4e41e0, 0x551830. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def g4e41e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e4050, 7, this=True, pop=28, ret=r.getrandbits(32))
    me = rnd(c, 0x40)
    sc = r.choice([_bits(1.0), _bits(0.5), _bits(r.uniform(-4, 4)), _bits(100.0), NAN, 0, _bits(1e-3)])
    e.wbytes(me + 0x1d, struct.pack('<I', sc))
    for i in range(3):
        e.wbytes(me + 0x21 + 4 * i, struct.pack('<I', r.choice([_bits(r.uniform(-50, 50)), _bits(0.0), _bits(r.uniform(-5, 5))])))

    def vec():
        p = rnd(c, 0x10)
        for i in range(3):
            v = r.choice([_bits(r.uniform(-60, 60)), _bits(r.uniform(-1, 1)), _bits(r.uniform(-1e5, 1e5)), _bits(r.uniform(-9, 9)), 0, NAN, _bits(1e30)])
            e.w32(p + 4 * i, v)
        return p
    return [me, vec(), vec(), r.getrandbits(32)]


def g551830(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: blk + 4 * k)
    hook_rec(c, 0x5002f0, 1, this=True, pop=4, ret=r.getrandbits(32))
    hook_rec(c, 0x500360, 1, this=True, pop=4, ret=r.getrandbits(32))
    w = rnd(c, 0x10)
    tgt = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=w)}, nslots=0x50 // 4)
    t = r.choice([tgt, tgt, tgt, 0])
    o = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=t)}, nslots=0x1c // 4)
    v = rnd(c, 0x18)
    return [o, r.getrandbits(32), v]


S(0x4e41e0, 'GUESS box to grid cell range (7 arg)', 'thiscall', None, ret='eax', gen=g4e41e0, nan_heap=True, note='batch44000')
S(0x551830, 'GUESS fill 5 params of looked up object', 'stdcall', None, ret='eax', gen=g551830, nan_heap=True, note='batch44000')
