"""specs_s44004.py - t5 () batch 44004: 0x4861f0."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g4861f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467410, 6, this=True, pop=0x18, ret=r.getrandbits(32))
    s = obj(c, 0x20, {0x2d0: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=0x2d4 // 4)
    sv = r.choice([s, s, s, 0])
    holder = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=sv), 8: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=0x14 // 4)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    inner = obj(c, 0x20, {0x30: pystub(c, 2, ret=r.getrandbits(32), pop=0, side=_log('log2'))}, nslots=0x34 // 4)
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    me = rnd(c, 0x20)
    e.w32(me + 0xc, holder)
    return [me]


S(0x4861f0, 'GUESS reset occupant and clear', 'thiscall', None, ret='al', gen=g4861f0, nan_heap=True, note='batch44004')
