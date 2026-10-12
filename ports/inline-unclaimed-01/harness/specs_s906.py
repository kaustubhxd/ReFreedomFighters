"""specs_s906.py - unclaimed-01 claim 5 (docs/20-unclaimed-01.md): ZDamageBox::CopyData (0x5db100). Both objects are
0x100 random bytes. Source +0x48 is zero about 40% of the time (no virtual call). The destination's vtable is a logging
fake, so the slot +0xc call is compared (its ecx and the call count)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    dst = _rnd(c, 0x100)
    vt = c.emu.logging_vtable('ZDamageBox', 4)
    c.emu.w32(dst, vt)
    src = _rnd(c, 0x100)
    if c.rng.random() < 0.4:
        c.emu.w32(src + 0x48, 0)
    return [dst, src]


S(0x5db100, 'ZDamageBox::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-01 claim 5; copies fields and 16-byte blocks; slot +0xc when src+0x48 != 0')
