"""specs_s6960.py - area 73 batch 69 (gap band, GUESS names). FUN_4f76f0 and FUN_4f75e0 (both ret 4) store (float)(int)arg at
this+0x9b (4f76f0) or this+0x9f (4f75e0); when the dword at this+0x93 is non-zero, vtable +0x36c(that dword) is called; then
vtable +0x370() is called on this."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x93, c.rng.choice([0, c.rng.getrandbits(32)]))
    e.w32(o, e.logging_vtable('f76f0', 0x380 // 4,
                              impl={0x36c: lambda em, a: (0, None), 0x370: lambda em, a: (0, None)},
                              argwords={0x36c: 1, 0x370: 0}))
    return [o, c.rng.getrandbits(32)]


S(0x4f76f0, 'GUESS FUN_4f76f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 69; [this+0x9b] = (float)arg; if [this+0x93]: vt+0x36c([this+0x93]); vt+0x370()')
S(0x4f75e0, 'GUESS FUN_4f75e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 69; [this+0x9f] = (float)arg; if [this+0x93]: vt+0x36c([this+0x93]); vt+0x370()')
