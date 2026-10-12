"""specs_s265.py - unclaimed area 67, slice 6: three release-style functions (logged slot calls, plain ret)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vtobj(c, slot):
    vt = c.emu.logging_vtable('Rel%x' % slot, 0x140, argwords={slot: 1})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    return o


def _global(c):
    if c.rng.random() < 0.6:
        c.emu.w32(0x713f04, _vtobj(c, 4))
    else:
        c.emu.w32(0x713f04, 0)
    c.emu.mu.ctl_flush_tb()
    return []


def _at(off):
    def gen(c):
        o = _rnd(c, 0x100)
        c.emu.w32(o + off, _vtobj(c, 0) if c.rng.random() < 0.7 else 0)
        c.emu.mu.ctl_flush_tb()
        return [o]
    return gen


S(0x557860, 'FUN_557860 (readFreeGlobal713f04)', 'cdecl', None, ret=None, gen=_global, note='batch265; slot 4 with 0, then clear')
S(0x42ad20, 'FUN_42ad20 (releaseAtC)', 'thiscall', None, ret=None, gen=_at(0xc), note='batch265; slot 0 with 1 at +0xc')
S(0x4cdca0, 'FUN_4cdca0 (releaseAt1c)', 'thiscall', None, ret=None, gen=_at(0x1c), note='batch265; slot 0 with 1 at +0x1c')
