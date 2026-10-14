"""specs_s42001.py - batch 42001. 0x476390: hooked 0x6352f0 (writes a random dword through its arg), 0x4e5e80 (st0 float), 0x4e5e40 (ax), 0x4e5e60 (eax),
src vtable slots 0x58 and 0x68."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g476390(c):
    clear_hooks(c)
    r = c.rng

    def put(emu, k):
        emu.w32(emu.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x6352f0, 1, this=True, nullflag=(0,), side=put)
    hook_rec(c, 0x4e5e80, 0, this='mark', st0=lambda e, k: r.uniform(-1e6, 1e6))
    hook_rec(c, 0x4e5e40, 0, this='mark', ret=lambda e, k: r.getrandbits(32))
    hook_rec(c, 0x4e5e60, 0, this='mark', ret=lambda e, k: r.getrandbits(32))
    src = obj(c, 0x80, {0x58: pystub(c, 1, this=True), 0x68: pystub(c, 1, this=True)})
    return [rnd(c, 0x80), src]


S(0x476390, 'GUESS read fields from local via getters, notify src slots 0x58/0x68', 'thiscall', None, ret='al', gen=g476390, note='batch42001')
