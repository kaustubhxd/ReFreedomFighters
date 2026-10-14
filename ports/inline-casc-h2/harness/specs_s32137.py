"""specs_s32137.py - h2 () batch 32137: 0x5034f0, 0x441790, 0x5c8c50. Callees/slots are recorders; 0x4de040 and 0x45f960 run as exe code."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5034f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        b = emu.arg32(0)
        if r.random() < 0.6:
            for i in range(3):
                emu.w32(b + 4 * i, _bits(r.uniform(-9, 9)))
        emu.calllog.append(('fill',))
    m = obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill),
                      0x7c: pystub(c, 2, this=True, deref={0: 9, 1: 3}, side=_log('use'))}, nslots=0x84 // 4 + 1)
    comps = [rnd(c, 0x10) for _ in range(3)]
    for p in comps:
        v = r.choice([_bits(r.uniform(-9, 9)), _bits(r.uniform(-1, 1)), _bits(r.uniform(-9, 9)), 0, _bits(1.0), _bits(-1.0), _bits(0.5)])
        e.wbytes(p, struct.pack('<I', v))
    seq = [comps[2], comps[1], comps[0]]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 2)], side=_log('lk'))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, m)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x20))
    return [me, p]


def g441790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slots = {0x68: pystub(c, 1, this=True, deref={0: 3}), 0x3c: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True),
             0x4c: pystub(c, 1, this=True)}
    o = obj(c, 0x20, slots, nslots=0x50 // 4)
    me = rnd(c, 0x80)
    blk = rnd(c, 0x30)
    e.w32(me + 0x10, r.choice([0, blk, blk]))
    e.w32(blk + 0x18, r.choice([0, 0, r.getrandbits(32)]))
    for off in (0x3c, 0x40, 0x58):
        e.wbytes(me + off, struct.pack('<I', r.choice([NAN, _bits(r.uniform(-9, 9)), 0, r.getrandbits(32)])))
    return [me, o]


def g5c8c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [r.getrandbits(32), r.choice([0, 1, 0xffffffff, r.getrandbits(32)])]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: vals[min(k, 1)])
    t = r.choice([0.0, 0.0069, 0.007, 0.0070001, 0.5, -1.0, 90.0, 1e-9, -0.0, r.uniform(-4, 4), r.uniform(0, 0.01), 0.00699, 360.0, 0.00699411379173398, 0.00699411379173398])
    tt = struct.unpack('<f', struct.pack('<I', NAN))[0] if r.random() < 0.05 else t
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=tt)
    me = rnd(c, 0x80)
    e.wbytes(me + 0x4c, struct.pack('<I', r.choice([_bits(r.uniform(-7, 7)), _bits(r.uniform(-1, 1)), 0, _bits(0.0872664600610733), NAN, _bits(100.0)])))
    return [me, rnd(c, 0x20)]


S(0x5034f0, 'GUESS push rotation matrix to object', 'thiscall', None, ret=None, gen=g5034f0, nan_heap=True, note='batch32137')
S(0x441790, 'GUESS apply renderer state', 'thiscall', None, ret='al', gen=g441790, nan_heap=True, note='batch32137')
S(0x5c8c50, 'GUESS compute half angles', 'thiscall', None, ret=None, gen=g5c8c50, nan_heap=True, note='batch32137')
