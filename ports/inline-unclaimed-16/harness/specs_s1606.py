"""specs_s1606.py - unclaimed-16 batch 6 (docs/20-unclaimed-16.md): ZFFActor::DestroyWeapons. The render-manager
object's slot 0x58 returns the two pointers in order (first lookup, then second); each returned object has a logging
vtable with slot 0x320 (no arguments). Not verified: the logging vtables are stubs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _item(c):
    o = _rnd(c, 0x100)
    c.emu.w32(o, c.emu.logging_vtable('weapon', 0x400, argwords={0x320: 0}))
    return o


def _destroy(c):
    p1 = _item(c) if c.rng.random() < 0.7 else 0
    p2 = _item(c) if c.rng.random() < 0.7 else 0
    seq = [p1, p2]
    q = _rnd(c, 0x100)
    c.emu.w32(q, c.emu.logging_vtable('mgr', 0x80, impl={0x58: lambda e, a: (seq.pop(0), None)},
                                      argwords={0x58: 1}))
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, q)
    c.emu.w32(0x70039c, rm)
    obj = _rnd(c, 0x1000)
    c.emu.w32(obj + 0x78a, c.rng.getrandbits(32))
    c.emu.w32(obj + 0x78e, c.rng.getrandbits(32))
    return [obj]


S(0x59f370, 'ZFFActor::DestroyWeapons (unknown) thiscall', 'thiscall', None, ret=None, gen=_destroy,
  note='unclaimed-16 b6; two slot 0x58 lookups; each non-null clears its slot and calls slot 0x320')
