"""specs_s35127.py - 0x551bd0 (stdcall(A, k, arr) ret 0xc, ret='eax'). A: object with slot 0x18 (1 arg, returns o, null in 1/4); o: slot 0x4c (0 args, returns e); 0x5003d0 hooked (thiscall, 1 arg; returns a distinct record pointer per call), 0x5002f0 hooked (thiscall, 1 arg); arr = 5 random dwords."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g551bd0(c):
    clear_hooks(c)
    r = c.rng
    recs = [rnd(c, 0x10) for _ in range(5)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: recs[min(k, 4)])
    hook_rec(c, 0x5002f0, 1, this=True)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0x14)
    A = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=o)}, nslots=8)
    return [A, r.getrandbits(32), rnd(c, 0x20)]


S(0x551bd0, 'GUESS look up object by key and store five values', 'stdcall', None, ret='eax', gen=_g551bd0, note='batch35127')
