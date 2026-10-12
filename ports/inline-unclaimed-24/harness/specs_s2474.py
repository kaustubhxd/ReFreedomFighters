"""specs_s2474.py - decomp area 24, batch 2474: ZGATE::RemoveGate(unsigned int), thiscall, ret 4. The child at +0x52 (optional):
slot 0x3c with the argument (recorder, one argument); slot 0x14 (recorder, returns a random dword); when that result is 0,
slot 0 with 1 (deleting-destructor recorder, one argument) if the child is still set, then the child pointer is cleared.
The pointer is kept when the result is nonzero."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    if r.random() < 0.8:
        child = obj(c, 0x40, {0x3c: pystub(c, 1), 0x14: pystub(c, 0, ret=lambda emu, k: r.choice([0, r.getrandbits(32) | 1])),
                              0x0: pystub(c, 1)})
        e.w32(o + 0x52, child)
    else:
        e.w32(o + 0x52, 0)
    return [o, r.getrandbits(32)]


S(0x454560, 'ZGATE::RemoveGate', 'thiscall', None, ret=None, gen=_gen, note='batch2474')
