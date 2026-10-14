"""specs_s1630.py - soundtimers batch 1630: ZDllSound::AdjustExit (graph record table; log object stubbed)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    n = r.randint(0, 6)
    base = rnd(c, 0xa4 * 8 + 0x20)
    g = rnd(c, 0x1200)
    c.emu.w32(g + 0x11e9, n)
    c.emu.w32(g + 0x11f9, base)
    d = rnd(c, 0x5400)
    c.emu.w32(d + 0x52fe, g)
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    idx = r.choice([0, 1, 2, 5, 6, 7, 0xffffffff, r.getrandbits(32)])
    k = r.random()
    op = r.choice([0.0, 1.0, 0.5, -0.2, 1.7, float('nan'), r.uniform(-1, 2)]) if k < 0.9 else r.uniform(-10, 10)
    if r.random() < 0.05:
        c.emu.w32(d + 0x52fe, 0)
    return [d, idx, _f(op)]


S(0x5354a0, 'ZDllSound::AdjustExit', 'thiscall', None, ret=None, gen=_gen, note='batch1630')
