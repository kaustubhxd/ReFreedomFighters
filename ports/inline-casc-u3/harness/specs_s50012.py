"""specs_s50012.py - u3 batch 50012 (Haiku slot, run by Sonnet 5.5), tier H. 0x4bbe50: engine object with unaligned dword +0x1a9f, ms counter +0x40, slot 0x1c0 as the engine random (st0 floats, file/line recorded
by sysobj); this holds the ramp state (byte +0x78, floats +0x70 +0x74 +0x79 +0x4c +0x50 +0x54 +0x58 +0x5c +0x60, ints +0x48 +0x64 +0x68, target object chain +0x44 -> +0x18 -> +0x84). dt straddles the 0.08 threshold."""
import struct
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks


def _fb(v):
    return struct.pack('<f', v)


def _g4bbe50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rv = lambda em, k: r.choice([0.0, 0.25, 0.5, 0.999, 1.0, r.random()])
    so = sysobj(c, rand=rv)
    e.wbytes(so + 0x1a9f, (0 if r.random() < 0.08 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    me = rnd(c, 0x90)
    e.wbytes(me + 0x78, bytes([0 if r.random() < 0.08 else r.randrange(1, 256)]))
    t74 = r.uniform(0, 100)
    e.wbytes(me + 0x74, _fb(t74))
    base = int(struct.unpack('<f', _fb(t74))[0] * 1024.0)
    dtms = r.choice([0, 50, 81, 82, 83, 200, 1000, 5000, -100, r.randrange(0, 3000)])
    e.w32(so + 0x40, (base + dtms) & 0xffffffff)
    dt = dtms / 1024.0
    tgt = rnd(c, 0x100)
    mid = rnd(c, 0x40)
    e.w32(mid + 0x18, tgt)
    e.w32(me + 0x44, mid)
    e.w32(me + 0x48, r.choice([0, 1, 1, 0, 2, 7, -1 & 0xffffffff]))
    e.w32(me + 0x64, r.randrange(0, 30))
    e.w32(me + 0x68, r.randrange(0, 12))
    T = r.choice([r.uniform(0.01, 3), dt * (r.randrange(0, 12)), r.uniform(0, 0.5)])
    e.wbytes(me + 0x70, _fb(T))
    for off, lo, hi in ((0x4c, -1, 2), (0x50, -1, 2), (0x54, 0, 3), (0x58, 0, 1), (0x5c, 0, 2), (0x60, 0, 4)):
        e.wbytes(me + off, _fb(r.uniform(lo, hi)))
    e.wbytes(me + 0x79, _fb(r.uniform(-0.5, 1.5)))
    e.wbytes(tgt + 0x84, _fb(r.uniform(-1, 2)))
    if r.random() < 0.3:   # make the second gate fire often
        e.wbytes(me + 0x54, _fb(r.uniform(0, 0.05)))
        e.wbytes(me + 0x58, _fb(r.uniform(0.5, 1.0)))
    return [me]


S(0x4bbe50, 'GUESS timed value ramp with random retargeting', 'thiscall', None, ret=None, gen=_g4bbe50, nan_heap=True, note='batch50012')
