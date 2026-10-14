"""specs_s35094.py - 0x4f0ee0 (thiscall(v) ret 4). this: 0x100 random bytes with vtable slot 0x23c (2 args); flags dword [+0x1c] random; unaligned dwords [+0x2a] (null in 1/4) and [+0x2e] (0..4); engine [+0x1aa3] (unaligned) -> object whose
[+0x18] is an object with slot 0x12c (2 args: pointer and this+0x18, both heap); v = 0xff in 2/5 of the cases, else a random dword (low byte may be 0xff too)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4f0ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    X = rnd(c, 0x30)
    e.w32(X + 0x18, obj(c, 0x20, {0x12c: pystub(c, 2, this=True)}, nslots=0x4c))
    e.wbytes(so + 0x1aa3, X.to_bytes(4, 'little'))
    me = obj(c, 0x100, {0x23c: pystub(c, 2, this=True)}, nslots=0x90)
    e.wbytes(me + 0x2a, (0 if r.random() < 0.25 else rnd(c, 0x100)).to_bytes(4, 'little'))
    e.wbytes(me + 0x2e, r.choice([0, 1, 2, 3, 4]).to_bytes(4, 'little'))
    v = 0xff if r.random() < 0.4 else r.choice([0, 1, 0x7f, 0x100, 0x1ff, r.getrandbits(32)])
    return [me, v]


S(0x4f0ee0, 'GUESS set alpha byte and refresh children', 'thiscall', None, ret=None, gen=_g4f0ee0, note='batch35094')
