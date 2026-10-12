"""specs_s7913.py - unclaimed-79 batch 13 (docs/20-unclaimed-79.md): ZPlayer::SetActiveMovement (0x484eb0). The object's slot +0x640
logs its argument and returns a random dword."""
from pilot import S
from helpers_trial import logged_slot


def _obj(c, size=0x600):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _setmov(c):
    self_ = _obj(c)
    vt = c.emu.fake_vtable('ZPlayer-setmov', 0x192, {0x640: logged_slot('ZPlayer::slot640', eax=c.rng.getrandbits(32), argbytes=4)})
    c.emu.w32(self_, vt)
    return [self_, c.rng.getrandbits(32)]


S(0x484eb0, 'ZPlayer::SetActiveMovement(unsigned int) thiscall', 'thiscall', None, ret=None, gen=_setmov,
  note='unclaimed-79 batch 13; stores slot +0x640 result at +0x455')
