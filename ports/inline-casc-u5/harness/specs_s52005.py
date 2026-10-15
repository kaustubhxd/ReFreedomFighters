"""specs_s52005.py - tier H. 0x526880: engine slot 0x1c0 returns a random float in 0..0.2 (threshold 0.1 gives both branches), hooked 0x516250 (a handle or 0), 0x52a070 and 0x516f40 (vector by content), /GS check; this block random with float fields +0x68/+0x6c/+0x7c (zero, negative, small, big), mode word +0xd49 in 0..3 (unaligned), counts +0x8c/+0x90 in -1..4."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _fbits(r):
    k = r.random()
    if k < 0.2:
        v = r.choice(EDGE_F)
    elif k < 0.25:
        return r.getrandbits(32)
    elif k < 0.6:
        v = r.uniform(-3, 3)
    else:
        v = r.uniform(-60, 60)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g526880(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rv = r.choice([0.0, 0.05, 0.1, 0.1000001, 0.15, 0.2, r.uniform(0, 0.2), float('nan')])
    sysobj(c, rand=lambda em, k: rv)
    hook_rec(c, 0x516250, 0, this=True, pop=0, ret=r.choice([0, r.getrandbits(32)]))
    hook_rec(c, 0x52a070, 1, this=True)
    hook_rec(c, 0x516f40, 1, this=True, deref={0: 3})
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    me = rnd(c, 0x1700)
    for off in (0x68, 0x6c, 0x7c):
        e.w32(me + off, _fbits(r))
    if r.random() < 0.25:
        f20 = struct.unpack('<I', struct.pack('<f', 20.0))[0]
        one = r.choice([0x3f800000, 0xbf800000])
        e.w32(me + 0x68, f20)
        e.w32(me + 0x7c, one)
    e.wbytes(me + 0xd49, r.choice([0, 1, 2, 3, 1, 2]).to_bytes(4, 'little'))
    e.w32(me + 0x8c, r.choice([-1, 0, 1, 2, 3, 4]) & 0xffffffff)
    e.w32(me + 0x90, r.choice([-1, 0, 1, 2, 3, 4]) & 0xffffffff)
    return [me]


S(0x526880, 'GUESS fill record float fields', 'thiscall', None, ret=None, gen=_g526880, note='batch52005')
