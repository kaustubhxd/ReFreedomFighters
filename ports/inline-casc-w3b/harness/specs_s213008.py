"""specs_s213008.py - batch 213008: field select by object kind with a logging fallback, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g4869e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.randint(0, 13) if r.random() < 0.9 else r.getrandbits(32)
    a = obj(c, 0x20, {0x330: pystub(c, 0, ret=k, this=True)}, nslots=0xcd)
    if r.random() < 0.4:
        e.w32(a + 4, 0)
    m = obj(c, 0x20, {0x30: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    return [rnd(c, 0x40), a]


S(0x4869e0, 'field_by_kind_log', 'thiscall', None, ret='eax', gen=g4869e0)
