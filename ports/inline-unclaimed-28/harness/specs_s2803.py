"""specs_s2803.py - unclaimed-28 batch 3 (docs/20-unclaimed-28.md): CCivilianPathList::Save (0x5bf1f0). The save game is a logging
fake vtable (slots 0x10 with two arguments, 0x44, 0x4c, 0x60, 0x64, 0x68). The count at +0x90c is -1 to 3 (the loop also runs
for zero or negative counts as skips), and the second count at +0x910 is 0 to 3."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _civ(c):
    self_ = _rnd(c, 0x1000)
    c.emu.w32(self_ + 0x90c, c.rng.choice([-1, 0, 1, 2, 3]))
    c.emu.w32(self_ + 0x910, c.rng.randint(0, 3))
    slots = {
        0x10: logged_slot('ZSaveGame::slot10', eax=0, argbytes=8),
        0x44: logged_slot('ZSaveGame::slot44', eax=0, argbytes=4),
        0x4c: logged_slot('ZSaveGame::slot4c', eax=0, argbytes=4),
        0x60: logged_slot('ZSaveGame::slot60', eax=0, argbytes=4),
        0x64: logged_slot('ZSaveGame::slot64', eax=0, argbytes=4),
        0x68: logged_slot('ZSaveGame::slot68', eax=0, argbytes=4),
    }
    vt = c.emu.fake_vtable('ZSaveGame-2803', 0x1c, slots)
    sg = _rnd(c, 0x100)
    c.emu.w32(sg, vt)
    return [self_, sg]


S(0x5bf1f0, 'CCivilianPathList::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_civ,
  note='unclaimed-28 batch 3; header slots 0x44, loop of 0x3a-byte records (11 slot calls), tail slots')
