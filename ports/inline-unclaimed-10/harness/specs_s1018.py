"""specs_s1018.py - unclaimed-10, batch 14: ZDamageBox2::CopyData (0x5db910). Thiscall, one argument (source), ret 4.
Stubs: the source's child (+0x48, half the cases null) with slot +0x4c (out pointer, no effect) and slot +0x5c (out pointer;
writes tmp = 1 for its first two calls in a case, 0 after, from a counter kept in the child's +0x10; returns the call number);
this's child (+0x48, always set) with slot +4 (one argument). The counter is set to 0 in gen. The kind at +0x4c is random
over {0, 1, 2, random}, so all three tail cases are exercised."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    e = c.emu

    def out58(em, a):
        ecx = em.reg('ecx')
        n = em.r32(ecx + 0x10)
        em.w32(ecx + 0x10, n + 1)
        em.w32(a[0], 1 if n < 2 else 0)
        return (n, None)

    vt_src = e.logging_vtable('dbsrc', 32, impl={0x5c: out58}, argwords={0x4c: 1, 0x5c: 1})
    vt_self = e.logging_vtable('dbself', 8, argwords={4: 1})
    src = _rnd(c, 0x800)
    dst = _rnd(c, 0x800)
    kind = c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])
    e.w32(src + 0x4c, kind)
    if c.rng.random() < 0.5:
        child = _rnd(c, 0x40)
        e.w32(child, vt_src)
        e.w32(child + 0x10, 0)
        e.w32(src + 0x48, child)
    else:
        e.w32(src + 0x48, 0)
    dchild = _rnd(c, 0x40)
    e.w32(dchild, vt_self)
    e.w32(dst + 0x48, dchild)
    return [dst, src]


S(0x5db910, 'ZDamageBox2::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-10 batch 14; source child slots +0x4c/+0x5c and this child slot +4 stubbed')
