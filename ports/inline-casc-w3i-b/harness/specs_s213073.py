"""specs_s213073.py - batch 213073: vector copy, hooked difference, x87 normalization, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

NAN = float('nan')


def g662cf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x48)

    def comp():
        return r.choice([0.0, -0.0, 0.0, 1.0, -1.0, 3.0, 4.0, 1e-30, 1e30, 1e-45, 3e38, NAN, float('inf'), r.uniform(-100, 100), r.uniform(-1, 1)])

    def vec(emu, k):
        mode = r.random()
        if mode < 0.25:
            v = (0.0, -0.0, 0.0) if r.random() < 0.5 else (0.0, 0.0, 0.0)
        elif mode < 0.4:
            v = (0.0, 0.0, comp())
        elif mode < 0.55:
            v = (comp(), 0.0, 0.0)
        elif mode < 0.65:
            v = (0.0, comp(), 0.0)
        else:
            v = (comp(), comp(), comp())
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', *v))

    def side(emu, k):
        emu.calllog.append(('edx', emu.reg('edx')))
        vec(emu, k)
    hook_rec(c, 0x43e920, 1, pop=4, this=True, side=side)
    hook_rec(c, 0x662ab0, 1, this=True)
    hook_rec(c, 0x662b00, 1, this=True)
    return [this]


S(0x662cf0, 'direction_normalize', 'thiscall', None, ret=None, gen=g662cf0)
