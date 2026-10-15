"""specs_s32143.py - h2 (Sonnet) batch 32143: 0x45aa90, 0x5d3f70. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _fv(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def g45aa90(c):
    clear_hooks(c)
    r = c.rng

    def col():
        k = r.random()
        if k < 0.15:
            return r.choice([0, 0xffffffff, 0xff000000, 0x00ff00ff, 0x80808080])
        return r.getrandbits(32)
    t = r.choice([0.0, 1.0, 0.5, r.uniform(0, 1), r.uniform(0, 1), r.uniform(-2, 3), -1.0, 0.25, _fv(NAN), 1e10, 1e-3])
    return [col(), col(), F(t)]


def g5d3f70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    bufval = r.getrandbits(32)

    def fill(emu, k):
        emu.w32(emu.arg32(0), bufval)
        emu.calllog.append(('lookup',))
    hook_rec(c, 0x6352f0, 1, this=True, pop=4, nullflag=(0,), side=fill)
    hook_rec(c, 0x4e5e60, 0, this='mark', pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x4e5e80, 0, this='mark', pop=0, st0=r.choice([0.0, 1.0, r.uniform(-9, 9), 1e30, _fv(NAN)]))
    slots = {off: pystub(c, 1, this=True) for off in (0x48, 0x40)}
    o = obj(c, 0x20, slots, nslots=0x4c // 4)
    me = rnd(c, 0x90)
    return [me, o]


S(0x45aa90, 'GUESS lerp packed colour', 'stdcall', None, ret='eax', gen=g45aa90, nan_heap=True, note='batch32143')
S(0x5d3f70, 'GUESS read object fields from stream', 'thiscall', None, ret='al', gen=g5d3f70, nan_heap=True, note='batch32143')
