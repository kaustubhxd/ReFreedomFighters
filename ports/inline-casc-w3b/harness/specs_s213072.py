"""specs_s213072.py - batch 213072: timed interpolation with 64-bit divide and ease curve, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g662870(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    eng = rnd(c, 0x80)
    e.w32(0x70039c, eng)
    dur = r.choice([1, 2, 10, 100, 1000, 2000, r.randint(1, 100000), -5, 0x7fffffff, r.randint(-1000, 0)])
    stamp = r.choice([0, 100, 5000, r.randint(-2**30, 2**30)])
    mode = r.random()
    if dur > 0:
        if mode < 0.1:
            el = -r.randint(1, 50)
        elif mode < 0.2:
            el = dur
        elif mode < 0.3:
            el = dur - 1
        elif mode < 0.4:
            el = 0
        elif mode < 0.5:
            el = dur // 2
        elif mode < 0.55:
            el = dur + r.randint(1, 10)
        else:
            el = r.randint(0, dur)
    else:
        el = r.randint(-2000, 2000)
    if mode > 0.9:
        dur = -r.randint(2000, 50000)
        el = dur - r.randint(1, 3)
    if dur == 0 and el < 0:
        el = 0
    clk = (stamp + el) & 0xffffffff
    e.w32(eng + 0x40, clk)
    this = rnd(c, 0x30)
    for off, v in ((0, r.uniform(-10, 10)), (4, r.uniform(-10, 10)), (8, r.uniform(-10, 10))):
        e.wbytes(this + off, struct.pack('<f', v))
    e.w32(this + 0xd, stamp & 0xffffffff)
    e.w32(this + 0x11, dur & 0xffffffff)
    v = lambda emu, k: r.choice([0.0, 1.0, 0.5, r.uniform(-0.5, 1.5), r.uniform(0, 1), -1.0, float('nan')]) if r.random() < 0.95 else 0.25
    hook_rec(c, 0x662940, 1, this=True, pop=4, st0=v)
    return [this]


S(0x662870, 'timed_interpolation', 'thiscall', None, ret='st0', gen=g662870)
