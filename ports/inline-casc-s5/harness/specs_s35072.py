"""specs_s35072.py - 0x4fd510 (thiscall(s) ret 4). 0x4e5e40 hooked (thiscall, recorder; returns a call-dependent dword with garbage upper bits so only AX is stored); engine table slots 0x138 (returns an object with
slot 0x4c, 2 args), 0x4c (1 arg, returns an id) and 0x114 (4 args, returns a dword with garbage upper bits). this = random 0x70 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g4fd510(c):
    clear_hooks(c)
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(7)]
    hook_rec(c, 0x4e5e40, 0, this=True, ret=lambda em, k: vals[min(k, 6)])
    o = obj(c, 0x20, {0x4c: pystub(c, 2, this=True)}, nslots=0x14)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32)),
                           0x114: pystub(c, 4, this=True, ret=r.getrandbits(32))}, table_size=0x140)
    return [rnd(c, 0x70), rnd(c, 0x10)]


S(0x4fd510, 'GUESS read words and register entry', 'thiscall', None, ret=None, gen=_g4fd510, note='batch35072')
