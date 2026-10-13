"""specs_s330.py - decomp area 64 (docs/20-unclaimed-64.md): 0x558eb0 lookup, sys child slot 0x58, then obj slot 0x4e0 (tail)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(c):
    e = c.emu
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Index is 0.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, c.rng.randrange(0, 8))
    e.w32(T + 0x8, c.rng.randrange(1, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)

    # Both slot arguments are recorded in a heap cell, so a wrong argument shows in the memory compare. The child's
    # return value is drawn once per case (not inside the stub), so both runs see the same value.
    cell = _rnd(c, 0x10)
    rv = c.rng.getrandbits(32)

    def rec58(em, a):
        em.w32(cell, a[0])
        return (rv, None)

    def rec4e0(em, a):
        em.w32(cell + 0x4, a[0])
        return (0, None)

    # Sys global at 0x70039c; its child at +0x9b takes one word at slot 0x58 and returns rv.
    child_vt = e.logging_vtable('child558e', 0x80, argwords={0x58: 1}, impl={0x58: rec58})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    sys_ = _rnd(c, 0x100)
    e.w32(sys_ + 0x9b, child)
    e.w32(0x70039c, sys_)

    # obj's vtable: slot 0x4e0 (the tail target) takes one word.
    obj_vt = e.logging_vtable('obj558e', 0x150, argwords={0x4e0: 1}, impl={0x4e0: rec4e0})
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, obj)
    return [self_, p]


S(0x558eb0, 'forwardValue (GUESS)', 'thiscall', None, ret='eax', gen=_fwd,
  note='batch330; one stack pointer p; ret 4; lookup (exe), sys child slot 0x58, obj slot 0x4e0 (tail)')
