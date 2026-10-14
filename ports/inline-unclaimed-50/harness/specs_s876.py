"""specs_s876.py - area 50, batch 876: 0x5ecfd0 (GUESS name), thiscall with an object and a dword (ret 8), no result.
The object's vt +0x2c (five arguments) and this's vt +0x20 are fake and logged. The flags (+0xa6, +0x35) and the pointer at +0x3a
(to a cell that is zero or not) are generated in every combination."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})

    def v20(e, rr):
        e.calllog.append(('self.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    def v2c(e, rr):
        e.calllog.append(('o.2c', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3), e.arg32(4)))
        e.ret(eax=0, argbytes=20)

    self = vt_object(c, 0x200, {0x20: v20}, nslots=0x20, name='self')
    cell = rnd(c, 8)
    e.w32(cell, r.choice([0, 1, r.getrandbits(32) | 1]))
    e.w32(self + 0x3a, cell)
    e.w8(self + 0xa6, r.choice([0, 1]))
    e.w8(self + 0x35, r.choice([0, 1]))
    e.w8(self + 0x5e, r.getrandbits(8))
    e.w32(self + 0x36, r.getrandbits(32))
    e.w32(self + 0x3a, cell) if False else None
    o = vt_object(c, 0x40, {0x2c: v2c}, nslots=0x100, name='o')
    return [self, o, r.getrandbits(32)]


S(0x5ecfd0, 'Fwd5ecfd0 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch876')
