"""specs_s32126.py - h2 () batch 32126: 0x512be0 and 0x46ab30. Slots are recorders; the engine float slot returns x87 values; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g512be0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [struct.unpack('<f', struct.pack('<f', r.uniform(-1, 1)))[0] for _ in range(2)]
    so = sysobj(c, slots={0x1c4: pystub(c, 2, this=True, st0=lambda emu, k: vals[min(k, 1)], side=_log('rnd'))})
    e.w32(so + 0x40, r.randrange(0, 100000))

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(3):
            if r.random() < 0.7:
                emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('fill',))
    sub = obj(c, 0x20, {0x84: pystub(c, 1, this=True, side=fill)}, nslots=0x84 // 4 + 1)
    me = rnd(c, 0x40)
    e.w32(me + 4, sub)
    return [me, rnd(c, 0x10)]


def g46ab30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 0x40) + 0x10
    e.w32(p - 4, r.choice([0, 0, 5, r.getrandbits(32)]))
    fn = pystub(c, 0, ret=r.getrandbits(32), this=True, side=_log('fn'))
    lo = p - r.choice([0x10, 0, 0x100]) if r.random() > 0.2 else p + 8
    hi = p + r.choice([0x10, 0, 0x100, -8])
    g = obj(c, 0x30, {0x20: pystub(c, 1, ret=r.choice([0, 0, 1]), this=True, side=_log('g20')),
                      0xac: pystub(c, 1, this=True, side=_log('gac'))}, nslots=0xac // 4 + 1)
    e.w32(g + 8, fn if r.random() > 0.3 else 0)
    e.w32(g + 0xc, lo & 0xffffffff)
    e.w32(g + 0x10, hi & 0xffffffff)
    e.w32(0x70038c, g)
    tgt = obj(c, 0x20, {0x98: pystub(c, 3, this=True, side=_log('t98'))}, nslots=0x98 // 4 + 1)
    me = obj(c, 0x90, {0x110: pystub(c, 2, this=True, side=_log('s110'))}, nslots=0x110 // 4 + 1)
    e.w32(me + 0x78, tgt)
    pp = r.choice([0, p, p, p])
    return [me, pp, F(r.uniform(-9, 9))]


S(0x512be0, 'GUESS random jitter vector and time stamp', 'thiscall', None, ret=None, gen=g512be0, nan_heap=True, note='batch32126')
S(0x46ab30, 'GUESS resolve id of a pointer and notify target', 'thiscall', None, ret=None, gen=g46ab30, note='batch32126')
