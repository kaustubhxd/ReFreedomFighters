"""specs_s66029.py - cascade s4 batch 66029: 0x582060 (dispatch a command code to one of three handlers)."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec, pystub


def _g582060(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.choice([0x1234, 0x5678, 0x0001, 0xffff])
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, kk: r.choice([0x70000 | k, k]))})
    hook_rec(c, 0x5833e0, 2, this=True, deref={1: 2})
    hook_rec(c, 0x441730, 0, this=True)
    hook_rec(c, 0x440530, 0, this=True)
    hook_rec(c, 0x585200, 1, this=True)
    t = e.alloc(0x60, 8)
    own = r.choice([0x0042, 0x1234, 0x0007])
    e.wbytes(t + 0x48, own.to_bytes(2, 'little'))
    glob = r.choice([0x0099, 0x5678, 0x0007])
    e.wbytes(0x71428c, glob.to_bytes(2, 'little'))
    e._image_dirty = True
    code = r.choice([k, own, glob, 0x0bad, k | 0x10000, own | 0x20000, glob | 0x30000])
    mode = r.random()
    if mode < 0.15:
        p = 0
    else:
        p = e.alloc(0x10, 8)
        e.w32(p, r.choice([0, 0, 5]))
        e.w32(p + 4, r.choice([0, 9]))
    return [t, code, p]


S(0x582060, 'GUESS dispatch a command code to one of three handlers', 'thiscall', None, ret='eax', gen=_g582060, note='batch66029')
