"""specs_s32125.py - h2 (Sonnet) batch 32125: 0x4f7e00. The stream reader 0x4e11e0 is a recorder that writes 4 random bytes through its destination (heap pointers recorded as is, the stack slot as a marker)."""
import struct
from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g4f7e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def w(emu, k):
        base = emu.arg32(0)
        emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(4)) if r.random() > 0.2 else bytes([0xff, 0xff, 0xff, 0xff]))
        emu.calllog.append(('rd',))
    hook_rec(c, 0x4f9c90, 1, this=True, pop=4, side=_log('b'))
    hook_rec(c, 0x4e11e0, 2, this=True, pop=8, stackmark=(0,), side=w)
    hook_rec(c, 0x4e1600, 0, this=True, pop=0, ret=r.choice([9, 9, 0, 0xff, 0x109, r.getrandbits(32)]), side=_log('t'))
    hook_rec(c, 0x4e0fd0, 1, this=True, pop=4, side=_log('f'))
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0, side=_log('e'))
    return [rnd(c, 0xc0), rnd(c, 0x40)]


S(0x4f7e00, 'GUESS read record from stream', 'thiscall', None, ret=None, gen=g4f7e00, nan_heap=True, note='batch32125')
