"""specs_s910.py - unclaimed-01 claim 9 (docs/20-unclaimed-01.md): COpenWindow::Save (0x5c3dc0). The save object is a
logging fake vtable with slots +0x60 and +0x3c (each one argument). The byte at +0x48 and the unaligned dword at +0x49
come from random bytes; the result is true (al = 1)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    o = _rnd(c, 0x100)
    save = _rnd(c, 0x40)
    vt = c.emu.logging_vtable('ZSaveGame', 0x30, argwords={0x60: 1, 0x3c: 1})
    c.emu.w32(save, vt)
    return [o, save]


S(0x5c3dc0, 'COpenWindow::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-01 claim 9; slot +0x60 with byte +0x48, slot +0x3c with dword +0x49, returns true')
