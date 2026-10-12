"""specs_s926.py - unclaimed-80 claim 6 (docs/20-unclaimed-80.md): CEntityTracker::Save (0x5c07f0). The save object is a logging
fake whose slots +0x3c, +0x40, +0x4c, +0x60, +0x64 and +0x68 each take one argument. The record count is 0..3 (about a quarter
zero, so the loop does not run); the record array (stride 0x17) and the pointer array are random and sized for the count."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    count = c.rng.randint(0, 3)
    save = _rnd(c, 0x40)
    c.emu.w32(save, c.emu.logging_vtable('ZSaveGame3', 0x70,
                                         argwords={0x3c: 1, 0x40: 1, 0x4c: 1, 0x60: 1, 0x64: 1, 0x68: 1}))
    o = _rnd(c, 0x200)
    c.emu.w32(o + 0x54, count)
    recs = _rnd(c, 0x17 * 4 + 0x20)
    c.emu.w32(o + 0x50, recs)
    ptrs = _rnd(c, 4 * 4 + 0x10)
    c.emu.w32(o + 0x4c, ptrs)
    return [o, save]


S(0x5c07f0, 'CEntityTracker::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-80 claim 6; save slots 0x3c, 0x40, 0x4c, 0x60, 0x64, 0x68 logged; loop over count records')
