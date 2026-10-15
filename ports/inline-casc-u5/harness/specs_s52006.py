"""specs_s52006.py - tier H. 0x46d070: every stream method (0x4e0fd0, 0x4e11e0, 0x4e12e0, 0x4e12f0, 0x4e14a0, 0x4e1b30, kind 0x4e1600 returning 3 about half the time with random high bytes) and 0x46cee0 is a recorder hook; the floats at +0xa8/+0xb0/+0xb4/+0xc0 are explicit (zero, NaN, normal); the dword at +0xc7 is unaligned."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.25:
        v = r.choice(EDGE_F)
    elif k < 0.3:
        return r.getrandbits(32)
    else:
        v = r.uniform(-200, 200)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g46d070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x46cee0, 1, this=True)
    for a, n in ((0x4e0fd0, 1), (0x4e11e0, 2), (0x4e12e0, 2), (0x4e12f0, 2), (0x4e14a0, 2)):
        hook_rec(c, a, n, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0)
    kind = 3 if r.random() < 0.5 else r.getrandbits(8)
    hook_rec(c, 0x4e1600, 0, this=True, pop=0, ret=(r.getrandbits(24) << 8) | kind)
    me = rnd(c, 0xe0)
    for off in (0xa8, 0xb0, 0xb4, 0xc0):
        e.w32(me + off, _fbits(r))
    s = rnd(c, 0x20)
    return [me, s]


S(0x46d070, 'GUESS stream block read then rescale', 'thiscall', None, ret=None, gen=_g46d070, note='batch52006')
