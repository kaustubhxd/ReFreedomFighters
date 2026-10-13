"""specs_s1003.py - unclaimed-02 batch 3 (docs/20-unclaimed-02.md): ZDamageBox::Init (0x5db3f0) and ZKillBox::Save
(0x5b20e0). Init reads the system interface global 0x70039c -> +0x9b -> +0xadc and calls slot +0x25c of that object
through a logging fake vtable; Save calls slot +0x64 of the ZSaveGame passed in. Objects are random heap bytes."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init(c):
    self_ = _rnd(c, 0x100)
    eaxv = c.rng.getrandbits(32)
    vt = c.emu.fake_vtable('ZDamageBox-sysobj', 0x98,
                           {0x25c: logged_slot('ZSysObj::slot25c', eax=eaxv, argbytes=8)})
    obj = _rnd(c, 0x100)
    c.emu.w32(obj, vt)
    t = _rnd(c, 0x100)
    c.emu.w32(t + 0xadc, obj)
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    return [self_]


def _save(c):
    self_ = _rnd(c, 0x100)
    vt = c.emu.fake_vtable('ZSaveGame-target', 0x33, {0x64: logged_slot('ZSaveGame::slot64', eax=0, argbytes=4)})
    sg = _rnd(c, 0x100)
    c.emu.w32(sg, vt)
    return [self_, sg]


S(0x5db3f0, 'ZDamageBox::Init() thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-02 batch 3; calls sys->+0x9b->+0xadc slot +0x25c(0x685f44, 0), stores eax at +0x48')
S(0x5b20e0, 'ZKillBox::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-02 batch 3; clears bit 0x40 at +4, calls savegame slot +0x64 with dword +0x4a, returns 1')
