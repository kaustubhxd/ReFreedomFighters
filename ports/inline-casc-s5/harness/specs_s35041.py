"""specs_s35041.py - 0x41e590 (thiscall, no args). [this+4] = C (null in 1/6; slots 0xc (returns a count, zero in 1/3) and 0 (delete, 1 arg)); logger at 0x700390: slot 0x20 (2 args) returns, by call index, one
of three line objects whose slot 0x2c recorders take 2, 3 and 2 stack args (caller-popped, ECX = their vtable); 0x634273 cdecl recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g41e590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    lg2s = [obj(c, 0x20, {0x2c: pystub(c, n, this=True, pop=0)}, nslots=0x20) for n in (2, 3, 2)]

    def pick(em, kk):
        return lg2s[min(kk, 2)]
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=pick, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    cnt = 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1
    C = 0 if r.random() < 1 / 6 else obj(c, 0x20, {0xc: pystub(c, 0, ret=cnt, this=True), 0: pystub(c, 1, this=True)}, nslots=8)
    me = rnd(c, 0x40)
    e.w32(me + 4, C)
    return [me]


S(0x41e590, 'GUESS destroy owned object with leak log', 'thiscall', None, ret=None, gen=_g41e590, note='batch35041')
