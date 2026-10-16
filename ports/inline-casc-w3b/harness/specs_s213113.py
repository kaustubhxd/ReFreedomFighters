"""specs_s213113.py - batch 213113: element list initialiser with config read, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g592850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    hook_rec(c, 0x4de7a0, 0, pop=0, this='mark')

    def s84(emu, k):
        lg(emu, 'v84', emu.arg32(0), 12)
    this = obj(c, 0xf60, {0x84: pystub(c, 1, this=True, side=s84)}, nslots=0x60)
    e.w32(this + 0xd4a, r.choice([0, 0, 1, 2, 3, 5, 6]))

    def s88(emu, k):
        if r.random() < 0.25:
            return
        emu.w32(emu.arg32(1), r.choice([0, 1, r.getrandbits(32), r.getrandbits(8)]))
    C = obj(c, 0x20, {0x88: pystub(c, 2, this=True, nullflag=(1,), side=s88)}, nslots=0x60)
    X = rnd(c, 0x20)
    T = obj(c, 0x20, {0x138: pystub(c, 0, this=True, ret=C), 0x58: pystub(c, 1, this=True, ret=lambda emu, k: X if r.random() < 0.8 else 0)}, nslots=0x60)
    eng = obj(c, 0x100, {}, nslots=4)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x592850, 'element_list_init', 'thiscall', None, ret=None, gen=g592850)
