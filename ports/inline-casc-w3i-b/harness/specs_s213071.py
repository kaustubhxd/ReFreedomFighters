"""specs_s213071.py - batch 213071: smoothed value tracker with clock aliasing, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

NICE = [0.0, 0.5, 1.0, 2.0, -1.0, -0.5, 0.25, 100.0, 1e-3, -3.5]


def fl(x):
    return struct.pack('<f', x)


def g6627c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    eng = rnd(c, 0x80)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x40, r.choice([0, 1, 100, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32), 50, 60]))
    alias = r.random() < 0.1
    this = eng + 0x40 - 0xd if alias else rnd(c, 0x40)
    cur = r.choice(NICE) if r.random() < 0.6 else r.uniform(-10, 10)
    thr = r.choice(NICE[:6] + [0.001, 5.0]) if r.random() < 0.6 else r.uniform(-1, 5)
    mode = r.random()
    if mode < 0.3:
        pv = cur - thr
    elif mode < 0.5:
        pv = cur - thr * 1.0001
    elif mode < 0.6:
        pv = cur - thr * 0.9999
    elif mode < 0.7:
        pv = cur + thr
    elif mode < 0.75:
        pv = float('nan')
    elif mode < 0.8:
        pv = float('inf')
    else:
        pv = r.choice(NICE) if r.random() < 0.5 else r.uniform(-10, 10)
    if r.random() < 0.05:
        thr = float('nan')
    if not alias:
        e.wbytes(this + 0xc, bytes([r.choice([0, 1, 1, 0xff])]))
        e.wbytes(this + 0xd, struct.pack('<I', r.choice([0, 10, 50, r.getrandbits(32)])))
        e.wbytes(this + 0x11, struct.pack('<I', r.choice([0, 10, 0x7fffffff, 0x80000000, r.getrandbits(32)])))
    else:
        e.wbytes(this + 0xc, bytes([r.choice([0, 1, 1])]))
        e.wbytes(this + 0x11, struct.pack('<I', r.choice([0, 10, r.getrandbits(32)])))
    e.wbytes(this, fl(cur))
    e.wbytes(this + 8, fl(r.uniform(-10, 10)))
    e.wbytes(this + 0x19, fl(thr))
    p = rnd(c, 8)
    e.wbytes(p, fl(pv))
    v = r.choice([0.0, 1.0, -1.0, r.uniform(-10, 10), float('nan'), 0.5])
    hook_rec(c, 0x662870, 0, this=True, st0=v)
    return [this, p]


S(0x6627c0, 'value_tracker', 'thiscall', None, ret='al', gen=g6627c0)
