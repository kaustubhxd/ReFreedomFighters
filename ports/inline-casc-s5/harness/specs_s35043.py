"""specs_s35043.py - 0x607ec0 (thiscall(a, b, c, d) ret 0x10, ret='eax' = this). a: object whose vtable slot 0x50 takes eight stack args (ECX recorded; callee pops 0x20) and returns a signed result
(negative in half the cases, with a different result for the second object's call when it is the same vtable object); logger at 0x700390 (slot 0x20 -> object with slot 0x2c, 2 args, caller-popped). The out
pointer (this+0x110) is a heap address; this is a random 0x120-byte block."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g607ec0(c):
    clear_hooks(c)
    r = c.rng
    rets = [r.choice([0, 1, 0x7fffffff, 0xffffffff, 0x80000000, 0x80004005, r.getrandbits(32)]) for _ in range(2)]
    a = obj(c, 0x20, {0x50: pystub(c, 8, this=True, ret=lambda em, k: rets[min(k, 1)])}, nslots=0x20)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    return [rnd(c, 0x120), a, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x607ec0, 'GUESS bound call constructor', 'thiscall', None, ret='eax', gen=_g607ec0, note='batch35043')
