"""specs_s1002.py - unclaimed-02 batch 2 (docs/20-unclaimed-02.md): ZFFHeroMovementCloseCombat::TerminateControl
(0x5e71c0) and ZFFHeroMovementGuide::TerminateControl (0x5e7210). The close-combat one calls virtual slot +0x220 of the
object at this+0x36d (a fake vtable that logs the call and its argument), then clears a bit in that object.
Guide: this+4 is a random 0x800-byte record whose bit 0x400000 at +0x417 is cleared."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _closecombat(c):
    self_ = _rnd(c, 0x800)
    vt = c.emu.fake_vtable('ZFFHeroMovementCloseCombat-target', 0x89,
                           {0x220: logged_slot('ZFFCloseCombatTarget::slot220', eax=0, argbytes=4)})
    tgt = _rnd(c, 0x800)
    c.emu.w32(tgt, vt)
    c.emu.w32(self_ + 0x36d, tgt)
    return [self_, c.rng.getrandbits(32)]


def _guide(c):
    self_ = _rnd(c, 0x800)
    obj = _rnd(c, 0x800)
    c.emu.w32(self_ + 4, obj)
    return [self_, c.rng.getrandbits(32)]


S(0x5e71c0, 'ZFFHeroMovementCloseCombat::TerminateControl(bool) thiscall', 'thiscall', None, ret='al',
  gen=_closecombat, note='unclaimed-02 batch 2; calls slot +0x220 with 0, clears bit 0x10000000, byte +0x5ac, returns 1')
S(0x5e7210, 'ZFFHeroMovementGuide::TerminateControl(bool) thiscall', 'thiscall', None, ret='al',
  gen=_guide, note='unclaimed-02 batch 2; clears dword +0x550 and bit 0x400000 at owner +0x417, returns 1')
