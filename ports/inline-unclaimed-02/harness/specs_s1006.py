"""specs_s1006.py - unclaimed-02 batch 6 (docs/20-unclaimed-02.md): CMsgForwardToActors::Save (0x49f210). Clears bit 0x40 at
this+4 and calls four slots of the ZSaveGame passed in (logging fake vtable): +0x40 twice with zero-extended words,
+0x4c with a float, +0x3c with a dword."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    self_ = _rnd(c, 0x100)
    vt = c.emu.fake_vtable('ZSaveGame-msg', 0x20, {
        0x40: logged_slot('ZSaveGame::slot40', eax=0, argbytes=4),
        0x4c: logged_slot('ZSaveGame::slot4c', eax=0, argbytes=4),
        0x3c: logged_slot('ZSaveGame::slot3c', eax=0, argbytes=4),
    })
    sg = _rnd(c, 0x100)
    c.emu.w32(sg, vt)
    return [self_, sg]


S(0x49f210, 'CMsgForwardToActors::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-02 batch 6; clears bit 0x40 at +4, then slots +0x40 (word +0x48), +0x40 (word +0x4a), +0x4c (float +0x4c), +0x3c (dword +0x50); returns 1')
