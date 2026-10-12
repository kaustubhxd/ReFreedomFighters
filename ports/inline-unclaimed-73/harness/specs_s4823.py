"""specs_s4823.py - area 73 batch 48 (gap band, GUESS names). FUN_4e8140 calls vtable slot +8 (two args, 0) and returns
the dword at +0x11 of the result, or 0 when it is null. FUN_4e6bf0 is an index store: it decrements this+0x10, then
writes ((arg - this[0]) / this[0xc]) as a word at array(this+4)[new index]. The divisor is kept nonzero per case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _e8140(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    if c.rng.random() < 0.3:
        val = 0
    else:
        val = _rnd(c, 0x40)
        if c.rng.random() < 0.5:
            e.w32(val + 0x11, 0)
    vt = e.logging_vtable('e8140', 16, impl={8: (lambda v: (lambda em, a: (v, None)))(val)}, argwords={8: 2})
    e.w32(self_o, vt)
    return [self_o, c.rng.getrandbits(32)]


def _e6bf0(c):
    e = c.emu
    self_o = _rnd(c, 0x20)
    e.w32(self_o, c.rng.getrandbits(32))              # base
    arr = _rnd(c, 0x400)
    e.w32(self_o + 4, arr)                            # word array
    e.w32(self_o + 0xc, c.rng.randint(1, 0xffff))     # divisor, never zero
    e.w32(self_o + 0x10, c.rng.randint(1, 0x7f))      # index, decremented before use
    return [self_o, c.rng.getrandbits(32)]


S(0x4e8140, 'GUESS FUN_4e8140 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_e8140,
  note='area 73 batch 48; vtable slot +8(arg, 0), returns dword at +0x11 of the result or 0')
S(0x4e6bf0, 'GUESS FUN_4e6bf0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_e6bf0,
  note='area 73 batch 48; this[0x10]--, word array[this[0x10]] = (arg - this[0]) / this[0xc]')
