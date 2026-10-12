"""specs_s2805.py - unclaimed-28 batch 5 (docs/20-unclaimed-28.md): ZFenceGate::Load (0x5c27b0). Three logging fake objects:
the load game (slot +0x68 returns the first object), that object (slot +0x68 returns the second) and the second (slot +0x40)."""
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    self_ = _rnd(c, 0x400)
    o2 = _rnd(c, 0x40)
    vt2 = c.emu.fake_vtable('FenceGate-o2', 0x12, {0x40: logged_slot('LoadGate::slot40', eax=0, argbytes=4)})
    c.emu.w32(o2, vt2)
    o1 = _rnd(c, 0x40)
    vt1 = c.emu.fake_vtable('FenceGate-o1', 0x1b, {0x68: logged_slot('LoadGate::o1slot68', eax=o2, argbytes=4)})
    c.emu.w32(o1, vt1)
    ld = _rnd(c, 0x40)
    vtl = c.emu.fake_vtable('FenceGate-ld', 0x1b, {0x68: logged_slot('ZLoadGame::slot68', eax=o1, argbytes=4)})
    c.emu.w32(ld, vtl)
    return [self_, ld]


S(0x5c27b0, 'ZFenceGate::Load(ZLoadGame*) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-28 batch 5; load chain: ld+0x68(+0x25a) -> +0x68(+0x25b) -> +0x40(+0x50); returns 1')
