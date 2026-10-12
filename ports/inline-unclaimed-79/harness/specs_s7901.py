"""specs_s7901.py - unclaimed-79 batch 1 (docs/20-unclaimed-79.md): ZFFActor::ActivateItem (0x59da60). The system interface global
0x70039c points at a fake object whose +0x9b is a logging fake (slot +0x58 returns 0 or 1); this has a logging fake vtable
(slot +0x3f0 returns 7, 8 or other; slot +0x45c logs its two arguments). The id matches this+0x78e about half the time."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _activate(c):
    self_ = _rnd(c, 0x800)
    idv = c.rng.choice([1, 2, 7, 8, c.rng.getrandbits(32)])
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x78e, idv)
    else:
        c.emu.w32(self_ + 0x78e, c.rng.getrandbits(32))
    ret3f0 = c.rng.choice([7, 8, 0, c.rng.getrandbits(32)])
    vs = c.emu.fake_vtable('ZFFActor-activate', 0x118, {
        0x3f0: logged_slot('ZFFActor::slot3f0', eax=ret3f0, argbytes=0),
        0x45c: logged_slot('ZFFActor::slot45c', eax=0, argbytes=8),
    })
    c.emu.w32(self_, vs)
    ret58 = c.rng.choice([0, 1])
    vt = c.emu.fake_vtable('SysItem-58', 0x17, {0x58: logged_slot('SysItem::slot58', eax=ret58, argbytes=4)})
    t = _rnd(c, 0x100)
    c.emu.w32(t, vt)
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    return [self_, idv]


S(0x59da60, 'ZFFActor::ActivateItem(unsigned int) thiscall', 'thiscall', None, ret='al', gen=_activate,
  note='unclaimed-79 batch 1; slot 0x58 gate on the item object, then slot 0x45c with (7 or 8, id) unless slot 0x3f0 already gives it')
