"""specs_s35079.py - 0x473fe0 (thiscall(o) ret 4, ret='eax'). Engine table byte +0xbac set in a quarter; o: slot 0x350 (returns p or 0); p: slot 0x328 (AL true in half, garbage upper bytes); this slot 0x55c (1 arg, returns q or 0);
q: slots 0x1e0 (1 arg, AL true in 2/3) and 0x320 (returns a random dword)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub, sysobj


def _g473fe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    al = lambda p: ((r.getrandbits(24) << 8) | r.choice([1, 2, 0x80])) if r.random() < p else (r.getrandbits(24) << 8)
    so = sysobj(c, table_size=0xc00)
    tab = e.r32(so + 0x9b)
    e.wbytes(tab + 0xbac, bytes([r.choice([1, 2, 0x80]) if r.random() < 0.25 else 0]))
    p = 0 if r.random() < 0.25 else obj(c, 0x20, {0x328: pystub(c, 0, this=True, ret=al(0.5))}, nslots=0xca)
    o = obj(c, 0x20, {0x350: pystub(c, 0, this=True, ret=p)}, nslots=0xd5)
    q = 0 if r.random() < 0.2 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=al(2 / 3)), 0x320: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0xc9)
    me = obj(c, 0x20, {0x55c: pystub(c, 1, this=True, ret=q)}, nslots=0x158)
    return [me, o]


S(0x473fe0, 'GUESS query object value with 999 as refusal', 'thiscall', None, ret='eax', gen=_g473fe0, note='batch35079')
