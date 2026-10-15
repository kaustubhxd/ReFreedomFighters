"""specs_s32119.py - h2 (Sonnet) batch 32119: 0x5718b0. Callees are recorders; the 32-byte record is checked through the destination heap block."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5718b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x20)
    hook_rec(c, 0x596ce0, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('a'))
    hook_rec(c, 0x596cf0, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('b'))
    hook_rec(c, 0x5a83c0, 1, this=True, pop=4, ret=rec, nullflag=(0,), side=_log('c'))
    hook_rec(c, 0x59b6d0, 0, this=True, pop=0, ret=r.randrange(0, 8), side=_log('d'))
    hook_rec(c, 0x5ade90, 0, this=True, pop=0, side=_log('e'))
    hook_rec(c, 0x5ae680, 0, this=True, pop=0, side=_log('f'))
    tgt = rnd(c, 0x600)
    ent = rnd(c, 0x1d20)
    e.wbytes(ent + 0x1d0f, rnd(c, 0x10).to_bytes(4, 'little'))
    g = rnd(c, 0x860)
    e.wbytes(g + 0x852, (ent if r.random() < 0.8 else 0).to_bytes(4, 'little'))
    me = rnd(c, 0x1c0)
    e.w32(me + 0x90, g if r.random() < 0.85 else 0)
    e.w32(me + 0x94, rnd(c, 0x20))
    e.w32(me + 0x1ac, tgt)
    return [me]


S(0x5718b0, 'GUESS copy 32-byte record into slot table and refresh', 'thiscall', None, ret=None, gen=g5718b0, note='batch32119')
