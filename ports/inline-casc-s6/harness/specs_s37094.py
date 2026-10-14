"""specs_s37094.py - cascade s6 batch 37094 (0x5f2230, thiscall(), plain ret). The object's vtable has recording stubs at slots 0xb0 (8 arguments) and 0xb4 (5 arguments); the
stubs keep 8 call rows so all 7 + 5 calls are compared; [this+0xc] -> block whose dword at +0xa8 is random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g5f2230(c):
    clear_hooks(c)
    e = c.emu
    t = obj(c, 0x40, {0xb0: pystub(c, 8, this=True), 0xb4: pystub(c, 5, this=True)})
    e.w32(t + 0xc, rnd(c, 0xc0))
    return [t]


S(0x5f2230, 'GUESS register_properties', 'thiscall', None, ret=None, gen=_g5f2230, note='batch37094')
