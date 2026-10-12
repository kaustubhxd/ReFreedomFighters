"""specs_s958.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x429a50 (field +0x71) and 0x429a80 (field +0xd), see src/batch958.cpp.
The field holds a logging object (null 25%) with slots +0x20 and +0x8 (one stack argument each, callee-cleaned, returning 0). Slot +0x20
rewrites the field to a per-case value (a second object 50%, else null), so the re-read after the first call is checked. Both paths run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _mk(c, self_o, off):
    vt = c.emu.logging_vtable('ZFieldObj', 0x9, argwords={0x20: 1, 0x8: 1})
    o3 = _rnd(c, 0x40)
    c.emu.w32(o3, vt)
    rewrite = o3 if c.rng.random() < 0.5 else 0

    def impl20(e, args, self_o=self_o, off=off, rewrite=rewrite):
        e.w32(self_o + off, rewrite)
        return (0, None)

    vt2 = c.emu.logging_vtable('ZFieldObj', 0x9, impl={0x20: impl20}, argwords={0x20: 1, 0x8: 1})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt2)
    return o


def _gen_for(off):
    def gen(c):
        self_o = _rnd(c, 0x200)
        if c.rng.random() < 0.25:
            c.emu.w32(self_o + off, 0)
        else:
            c.emu.w32(self_o + off, _mk(c, self_o, off))
        return [self_o]
    return gen


S(0x429a50, 'two field slot calls (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_for(0x71),
  note='unclaimed-80 gap band; field +0x71; slots +0x20 and +0x8')
S(0x429a80, 'two field slot calls (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_for(0xd),
  note='unclaimed-80 gap band; field +0xd; slots +0x20 and +0x8')
