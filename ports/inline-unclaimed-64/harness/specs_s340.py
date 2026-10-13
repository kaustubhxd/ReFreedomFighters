"""specs_s340.py - decomp area 64 (docs/20-unclaimed-64.md): 0x516470 serialiser over a stream; exe helpers 0x524780, 0x524410, 0x524760."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ser(c):
    e = c.emu
    # The stream's vtable: 0x6c, 0x50 and 0x68 take one word each; 0x18 takes two. The exe's helpers call 0x50 too. Each
    # slot pops its words (thiscall). (0x6c takes self: the exe pushes esi before that call.)
    vt = e.logging_vtable('stream516', 0x40, argwords={0x6c: 1, 0x50: 1, 0x68: 1, 0x18: 2})
    stream = _rnd(c, 0x40)
    e.w32(stream, vt)
    self_ = _rnd(c, 0x100)
    return [self_, stream]


S(0x516470, 'serialise (GUESS)', 'thiscall', None, ret='al', gen=_ser,
  note='batch340; one stack pointer stream; ret 4; stream vtbl 0x6c, 0x50, 0x68, 0x18; exe 0x524780, 0x524410, 0x524760')
