"""specs_s213148.py - batch 213148: child-widget wiring by name (mode switch, table lookups, linking), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g56bd90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x5613a0, 2, pop=8, this=True)
    hook_rec(c, 0x563510, 1, pop=4, this=True)
    children = {}

    def mk_widget():
        def child(emu, k):
            key = (emu.reg('ecx'), emu.arg32(0))
            if key not in children:
                children[key] = mk_widget()
            return children[key]
        return obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=child),
                             0x284: pystub(c, 1, this=True),
                             0xbc: pystub(c, 1, this=True),
                             0x44: pystub(c, 0, this=True)}, nslots=0xa0)
    # R: vtable slot 0x60 takes (name, q, 0x10)
    R = obj(c, 0x20, {0x60: pystub(c, 3, this=True)}, nslots=0x20)
    T = obj(c, 0x20, {0x138: pystub(c, 0, this=True, ret=R),
                      0x4c: pystub(c, 1, this=True, ret=lambda emu, k: rb())}, nslots=0x60)
    E = rnd(c, 0x100)
    w32u(E + 0x9b, T)
    e.w32(0x70039c, E)
    this = rnd(c, 0xd40)
    k = r.choice([0, 1, 2, 3, 4, 5, 0, 3, 6, 7, 0xffffffff, rb()])
    w32u(this + 0xcee, k)
    w32u(this + 0xc7e, mk_widget())
    w32u(this + 0xc5e, mk_widget())
    w32u(this + 0x44, rb())
    return [this]


S(0x56bd90, 'wire_children', 'thiscall', None, ret=None, gen=g56bd90)
