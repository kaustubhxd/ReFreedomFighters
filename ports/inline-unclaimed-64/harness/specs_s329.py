"""specs_s329.py - decomp area 64 (docs/20-unclaimed-64.md): 0x51b0b0 lookup, flag from the entry, then obj vtbl slot 0x36c."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flag(c):
    e = c.emu
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Index is 0.
    data = _rnd(c, 0x100)
    if c.rng.random() < 0.3:
        e.w32(data, 0)                          # entry is zero: flag 0
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, c.rng.randrange(0, 8))
    e.w32(T + 0x8, c.rng.randrange(1, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)
    # obj's vtable: slot 0x36c takes one stack word (popped by the callee) and returns a value the port returns.
    obj_vt = e.logging_vtable('obj51b0', 0x400, argwords={0x36c: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, obj)
    return [self_, p]


S(0x51b0b0, 'flagForward (GUESS)', 'thiscall', None, ret='eax', gen=_flag,
  note='batch329; one stack pointer p; ret 4; exe 0x5003d0 runs as original; obj vtbl 0x36c with one stack word')
