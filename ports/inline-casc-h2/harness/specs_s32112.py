"""specs_s32112.py - h2 () batch 32112: one tier H function (sibling of 0x520bb0). Callees/slots are recorders; the buffer is recorded with deref and modified by the 0x4e09b0 hook."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g520b10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(4):
            emu.w32(base + 4 * i, r.getrandbits(32))

    def tweak(emu, k):
        base = emu.reg('ecx')
        emu.w32(base + 4, r.getrandbits(32))
        emu.calllog.append(('norm',))
    hook_rec(c, 0x5233a0, 2, this=True, pop=8, nullflag=(0,), side=fill)
    hook_rec(c, 0x4e09b0, 0, this='mark', pop=0, side=tweak)
    hook_rec(c, 0x521600, 1, this=True, pop=4, deref={0: 4}, side=lambda emu, k: emu.calllog.append(('use', emu.r32(emu.reg('ecx') + 0x216))))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    vt = e.alloc(0x20, 4)
    e.w32(vt, pystub(c, 3, this=True, side=_log('emb')))
    me = rnd(c, 0x26a0)
    e.wbytes(me + 0x2695, vt.to_bytes(4, 'little'))
    e.w32(me + 0x5c, rnd(c, 0x20))
    return [me, F(r.choice([r.uniform(-9, 9), _f(NAN), 0.0])), r.choice([0, 1, 0x1ff, r.getrandbits(32)])]


S(0x520b10, 'GUESS store parameters, build and normalise record, apply (GS frame)', 'thiscall', None, ret=None, gen=g520b10, nan_heap=True, note='batch32112')
