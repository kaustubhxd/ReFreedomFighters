"""specs_s2490.py - decomp area 24, batch 2490.
0x444fb0 (ZROOM::RemoveDynamicGeomFromRoom per the claim doc): thiscall, ret 4. Child at +0xa8: slot 0x28 with the argument (recorder,
returns a fixed dword); when nonzero, tail jump to slot 0x3c of the child with the argument (recorder pops 4, its return value is the
result); otherwise the result is not compared (ret None).
0x44a5b0 (name not in the claim doc): thiscall, ret 4. When +0x18 is set: slot 0x230 of this with (argument, 0) (recorder, callee pops 8),
then the tail jump to slot 0x3c of the child at +0x18 with the argument (recorder pops 4).
The tail target is assumed to pop one dword; see the source note."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _tail(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rv1 = r.choice([0, 1])
    rv2 = r.getrandbits(32)
    child = obj(c, 0x40, {0x28: pystub(c, 1, ret=rv1), 0x3c: pystub(c, 1, ret=rv2)})
    o = rnd(c, 0x100)
    e.w32(o + 0xa8, r.choice([0, child]))
    return [o, r.getrandbits(32)]


def _pre(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    child = obj(c, 0x40, {0x3c: pystub(c, 1)})
    o = obj(c, 0x40, {0x230: pystub(c, 2)})
    e.w32(o + 0x18, r.choice([0, child]))
    return [o, r.getrandbits(32)]


S(0x444fb0, 'ZROOM::RemoveDynamicGeomFromRoom', 'thiscall', None, ret=None, gen=_tail, note='batch2490')
S(0x44a5b0, 'tail to child with precall', 'thiscall', None, ret=None, gen=_pre, note='batch2490')
