"""specs_s1004.py - unclaimed-02 batch 4 (docs/20-unclaimed-02.md): CExplode::Save (0x584d00). Clears bit 0x40 at
this+4 and calls slot +0x3c of the ZSaveGame passed in (a logging fake vtable) with the dword at this+0x5e."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    self_ = _rnd(c, 0x100)
    vt = c.emu.fake_vtable('ZSaveGame-target', 0x10, {0x3c: logged_slot('ZSaveGame::slot3c', eax=0, argbytes=4)})
    sg = _rnd(c, 0x100)
    c.emu.w32(sg, vt)
    return [self_, sg]


S(0x584d00, 'CExplode::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-02 batch 4; clears bit 0x40 at +4, calls savegame slot +0x3c with dword +0x5e, returns 1')
