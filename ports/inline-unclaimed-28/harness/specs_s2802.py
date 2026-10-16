"""specs_s2802.py - unclaimed-28 batch 2 (docs/20-unclaimed-28.md): CFireController::Save (0x584eb0) and CTelePortList::Save
(0x4b83b0). The save game is a logging fake vtable (slots 0x3c, 0x4c, 0x68). The fire controller's count at +0x4c is 0 to 4,
so the record loop runs 0 to 4 times; the object has random bytes everywhere else."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _savegame(c):
    slots = {
        0x3c: logged_slot('ZSaveGame::slot3c', eax=0, argbytes=4),
        0x4c: logged_slot('ZSaveGame::slot4c', eax=0, argbytes=4),
        0x68: logged_slot('ZSaveGame::slot68', eax=0, argbytes=4),
    }
    vt = c.emu.fake_vtable('ZSaveGame-2802', 0x1c, slots)
    sg = _rnd(c, 0x100)
    c.emu.w32(sg, vt)
    return sg


def _fire(c):
    self_ = _rnd(c, 0x200)
    c.emu.w32(self_ + 0x4c, c.rng.randint(0, 4))
    return [self_, _savegame(c)]


def _tele(c):
    self_ = _rnd(c, 0x100)
    return [self_, _savegame(c)]


S(0x584eb0, 'CFireController::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_fire,
  note='unclaimed-28 batch 2; count at +0x4c, 28-byte records from +0x50; slots 0x4c (float), 0x3c (3 dwords), 0x68')
S(0x4b83b0, 'CTelePortList::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_tele,
  note='unclaimed-28 batch 2; slot 0x3c with dwords +0x4c, +0x50, +0x48')
