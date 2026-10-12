"""specs_s302.py - decomp area 39 (docs/20-unclaimed-39.md): 0x5274a0 calls obj vtbl slot 0x6c three times, then exe 0x5270f0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _block(c):
    e = c.emu
    # obj's vtable: 0x6c is the call this function makes; 0x50, 0x68, 0x18 are the calls exe 0x5270f0 makes on obj.
    # argwords = stack words the stub pops (the exe callers are thiscall and do not clean up).
    vt = e.logging_vtable('obj5274', 0x40, argwords={0x18: 2, 0x50: 1, 0x68: 1, 0x6c: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt)
    self_ = _rnd(c, 0x80)
    return [self_, obj]


S(0x5274a0, 'readBlock (GUESS)', 'thiscall', None, ret='al', gen=_block,
  note='batch302; one stack arg obj; ret 4; obj vtbl 0x6c x3; exe 0x5270f0 (ecx = self+0x28)')
