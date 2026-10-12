"""specs_s2425.py - decomp area 24, batch 2425: CGeomSound::FrameUpdate (0x4a35b0), thiscall, plain ret.
The field at +0x54 is a signed slot. A non-negative slot is cleared to -1 when it is at most (engine time >> 10),
the time being the dword at +0x40 of the engine object (0x70039c). The spec sets the time and the slot over a range
that covers negative, equal, below and above cases."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    t = r.randint(0, 1 << 20)
    e.w32(so + 0x40, t)
    o = rnd(c, 0x80)
    tt = t >> 10
    e.w32(o + 0x54, r.choice([0xffffffff, 0, tt, tt + 1, max(tt - 1, 0), r.randint(0, 2 * tt + 2), 0xfffffffe]))
    return [o]


S(0x4a35b0, 'CGeomSound::FrameUpdate', 'thiscall', None, ret=None, gen=_gen, note='batch2425')
