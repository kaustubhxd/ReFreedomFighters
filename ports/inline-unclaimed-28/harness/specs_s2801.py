"""specs_s2801.py - unclaimed-28 batch 1 (docs/20-unclaimed-28.md): CEnemyFlag::Save (0x5c2030). The save game is a logging
fake vtable with the slots the function calls (0x10 takes two arguments, the others one). This object's +0xe4 equals the
flag constant half the time, so the flag byte takes both values."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    self_ = _rnd(c, 0x200)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0xe4, 0x6eef78)
    slots = {
        0x10: logged_slot('ZSaveGame::slot10', eax=0, argbytes=8),
        0x44: logged_slot('ZSaveGame::slot44', eax=0, argbytes=4),
        0x54: logged_slot('ZSaveGame::slot54', eax=0, argbytes=4),
        0x60: logged_slot('ZSaveGame::slot60', eax=0, argbytes=4),
        0x64: logged_slot('ZSaveGame::slot64', eax=0, argbytes=4),
        0x68: logged_slot('ZSaveGame::slot68', eax=0, argbytes=4),
    }
    vt = c.emu.fake_vtable('ZSaveGame-enemyflag', 0x1c, slots)
    sg = _rnd(c, 0x100)
    c.emu.w32(sg, vt)
    return [self_, sg]


S(0x5c2030, 'CEnemyFlag::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-28 batch 1; 17 save-game calls, flag byte in a stack slot holding this')
