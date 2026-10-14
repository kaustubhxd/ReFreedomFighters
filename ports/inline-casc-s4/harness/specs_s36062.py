"""specs_s36062.py - cascade s4 batch 36062: 0x56d150 (load a resource set and its named handles)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g56d150(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x563110, 2, this=True)
    for a in (0x56d750, 0x56d840, 0x56d950):
        hook_rec(c, a, 0, this=True)
    ro = obj(c, 0x20, {0x14: pystub(c, 1, this=True, ret=lambda em, k: 0x5000 + 0x10 * k)})
    M = obj(c, 0x20, {0xc: pystub(c, 3, this=True), 0x60: pystub(c, 1, this=True, ret=ro)})
    so = sysobj(c)
    e.w32(so + 0x1907, 0 if r.random() < 0.0 else M)
    s = rnd(c, 0x200)
    return [s, r.getrandbits(32), r.choice([0, 1, 0x100, 0x2, r.getrandbits(32)])]


S(0x56d150, 'GUESS load a resource set and its named handles', 'thiscall', None, ret='al', gen=_g56d150, note='batch36062')
