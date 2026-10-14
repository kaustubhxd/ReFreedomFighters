"""specs_s35107.py - 0x429350 (thiscall(s) ret 4, ret='al'). s: slot 0xc with ECX recorded and four stack args (non-zero result in a quarter); [this+0xd] (unaligned) = P with slots 0x2c (ECX = vtable, two stack args; non-zero in 1/4) and 0x34 (ECX plus three stack args; non-zero in 1/4);
engine [+0x9db] (unaligned) random; logger at 0x700390 (slot 0x20 (2 args) -> object with slot 0x2c, 2 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g429350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nz = lambda: 0 if r.random() < 0.75 else r.getrandbits(32) | 1
    s = obj(c, 0x20, {0xc: pystub(c, 4, this=True, ret=nz())}, nslots=4)
    P = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, ret=nz()), 0x34: pystub(c, 3, this=True, ret=nz())}, nslots=0xe)
    me = rnd(c, 0x40)
    e.wbytes(me + 0xd, P.to_bytes(4, 'little'))
    so = sysobj(c, table_size=0x20)
    e.wbytes(so + 0x9db, r.getrandbits(32).to_bytes(4, 'little'))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [me, s]


S(0x429350, 'GUESS load data from stream with error reports', 'thiscall', None, ret='al', gen=_g429350, note='batch35107')
