"""specs_s35106.py - 0x45bcf0 (thiscall, no args). this: random 0x260 bytes with count [+0x20] 0..3, [+8] -> block with [+0x6c], [+0x254] -> dword array (0x20 bytes); engine [+0x1aa3] (unaligned) -> X: slot 0x80 (1 arg, non-zero in half) and [X+0x18] = O with slots 0x60 (2 args, returns a handle, null in 1/6 of the calls) and 0xe4 (2 args, returns non-zero in 2/3 of the calls);
logger at 0x700390 (slot 0x20 -> object with slot 0x2c, 2 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g45bcf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hs = [0 if r.random() < 1 / 6 else r.getrandbits(32) | 1 for _ in range(4)]
    qs = [0 if r.random() < 1 / 3 else r.getrandbits(32) | 1 for _ in range(4)]
    O = obj(c, 0x20, {0x60: pystub(c, 2, this=True, ret=lambda em, k: hs[min(k, 3)]), 0xe4: pystub(c, 2, this=True, ret=lambda em, k: qs[min(k, 3)])}, nslots=0x3a)
    vals = [r.random() < 0.5 for _ in range(4)]
    X = obj(c, 0x30, {0x80: pystub(c, 1, this=True, ret=lambda em, k: 1 if vals[min(k, 3)] else 0)}, nslots=0x21)
    e.w32(X + 0x18, O)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, X.to_bytes(4, 'little'))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    me = rnd(c, 0x260)
    e.w32(me + 0x20, r.choice([0, 1, 2, 3, 3]))
    e.w32(me + 8, rnd(c, 0x80))
    e.w32(me + 0x254, rnd(c, 0x20))
    return [me]


S(0x45bcf0, 'GUESS resolve slot resources and cache handles', 'thiscall', None, ret=None, gen=_g45bcf0, note='batch35106')
