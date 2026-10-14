"""specs_s3510.py - area 73 batch 10: ZRender::UnlockDrawBaseGeomsBuffer (0x651360). The object at this+0xbd has a logging slot
+0x24 (two arguments, logged). The fields at +0x1f and +0x23 are random dwords."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _unlock(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    obj = _rnd(c, 0x40)
    e.w32(obj, e.logging_vtable('drawbuf', 0x28 // 4, impl={0x24: lambda em, a: (0, None)}, argwords={0x24: 2}))
    e.w32(self_o + 0xbd, obj)
    return [self_o]


S(0x651360, 'ZRender::UnlockDrawBaseGeomsBuffer (unknown) thiscall', 'thiscall', None, ret=None, gen=_unlock,
  note='area 73 batch 10; slot +0x24 on this+0xbd with (this+0x1f, this+0x23); this+0x1f = 0')
