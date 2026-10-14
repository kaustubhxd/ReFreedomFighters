"""specs_s35128.py - 0x500760 (stdcall(A, k, name) ret 0xc, ret='eax'). A: object with slot 0x18 (1 arg, returns o, null in 1/4) and slot 0 (2 args, returns X); o: slot 0x4c (0 args, random handle); X: slots 0x30 (1 arg), 0x24 (0 args, returns a value), 0x28 (0 args);
0x5003d0 hooked (thiscall, 1 arg) returning a record whose kind byte is 0, 4 (value = object with slot 0x28) or another."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g500760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 8)
    k = r.choice([0, 4, 4, 0, 1, 2, 5])
    e.wbytes(rec + 4, bytes([k]))
    if k == 4:
        e.w32(rec, obj(c, 0x10, {0x28: pystub(c, 0, this=True)}, nslots=0x1a))
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec)
    X = obj(c, 0x20, {0x30: pystub(c, 1, this=True), 0x24: pystub(c, 0, this=True, ret=r.getrandbits(32)), 0x28: pystub(c, 0, this=True)}, nslots=0x1a)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0x14)
    A = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=o), 0: pystub(c, 2, this=True, ret=X)}, nslots=8)
    return [A, r.getrandbits(32), r.getrandbits(32)]


S(0x500760, 'GUESS create named child and store in tagged slot', 'stdcall', None, ret='eax', gen=_g500760, note='batch35128')
