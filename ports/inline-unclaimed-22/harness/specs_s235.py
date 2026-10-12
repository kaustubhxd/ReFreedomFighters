"""specs_s235.py - area 59, batch235 (src/batch235.cpp): 0x440aa0, list walk with vtable calls. 0x45eeb0 is a recorder
(ecx and its two arguments, ret 8). Every vtable callee is a logged sparse slot; the list is 0 to 3 nodes long, and the
slot 0x28 result alternates between zero and nonzero across cases."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _rec_ecx


def _obj(c, slots):
    o = _rnd(c, 0x40)
    c.emu.w32(o, _multi_vt(c, slots))
    return o


def _g_440aa0(c):
    self_ = _rnd(c, 0x100)
    nodes = [_rnd(c, 0x80) for _ in range(c.rng.randint(0, 3))]
    for i, n in enumerate(nodes):
        c.emu.w32(n + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
    c.emu.w32(self_ + 0x50, nodes[0] if nodes else 0)
    # the object of the global: slot 0x50 returns b; slot 0x58 returns obj2
    obj2 = _obj(c, {0x1e4: (lambda em, args: (0, None), 2)})
    rv58 = obj2   # never null: the callee dereferences it
    rv50 = c.rng.getrandbits(32)
    g = _obj(c, {0x50: (lambda em, args, v=rv50: (v, None), 1),
                 0x58: (lambda em, args, v=rv58: (v, None), 1)})
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, g)
    c.emu.w32(0x70039c, rm)
    A = _obj(c, {0x28: (lambda em, args, v=c.rng.choice([0, 1, c.rng.getrandbits(32)]): (v, None), 1)})
    _rec_ecx(c, 0x45eeb0, 2)
    c.emu.mu.ctl_flush_tb()
    return [self_, A, c.rng.getrandbits(32)]


S(0x440aa0, 'walkList (GUESS)', 'thiscall', None, ret=None, gen=_g_440aa0,
  note='batch235; list at +0x50 (next +0x60), vtable calls on the global object and A; 0x45eeb0 recorded')
