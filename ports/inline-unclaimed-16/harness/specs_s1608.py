"""specs_s1608.py - unclaimed-16 batch 8 (docs/20-unclaimed-16.md): 0x47bc70 (GUESS name). The object is 0x1000 random
bytes; the flag at +0x5d2 is random. Flag zero: slot 0x20 of the object returns r, whose slot 0x7c is a logging stub
(two arguments: the original a1 and a2). Flag nonzero: arg1 is a 36-byte matrix and arg2 12 bytes, each in its own heap
block so no argument aliases the object."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _root(c):
    obj = _rnd(c, 0x1000)
    c.emu.wbytes(obj + 0x5d2, bytes([c.rng.choice([0, 1, 2, 0x80, c.rng.getrandbits(8)])]))
    r = _rnd(c, 0x100)
    c.emu.w32(r, c.emu.logging_vtable('root_r', 0x100, argwords={0x7c: 2}))
    c.emu.w32(obj, c.emu.logging_vtable('root_self', 0x100, impl={0x20: lambda e, a: (r, None)}))
    return [obj, _rnd(c, 0x40), _rnd(c, 0x40)]


S(0x47bc70, 'ZActor::SetRootMatrixAndPos (GUESS; map says GetActorRootTM) thiscall', 'thiscall', None,
  ret=None, gen=_root, note='unclaimed-16 b8; name conflict: map says getter, body writes; flag 0 tail-calls slot 0x7c')
