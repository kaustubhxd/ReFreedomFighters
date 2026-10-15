"""specs_s66027.py - cascade s4 batch 66027: 0x4fb3e0 (look up nine 16-bit handles by name)."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, pystub


def _g4fb3e0(c):
    clear_hooks(c)
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(9)]
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: vals[min(k, 8)])})
    t = c.emu.alloc(0x70, 8)
    c.emu.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x70)))
    return [t]


S(0x4fb3e0, 'GUESS look up nine 16-bit handles by name', 'thiscall', None, ret=None, gen=_g4fb3e0, note='batch66027')
