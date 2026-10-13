"""specs_u18_03.py - area 18, group 3 (unclaimed-18 thread)."""
import struct
from pilot import S
from ckit import obj, rnd


def _rm(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x23000)
    marker = rnd(c, 0x40)
    e.w32(o + 0x22d7, marker)

    def rem(e, res):
        e.calllog.append(('CActorActionMarker::Remove', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    e.hook(0x5eac30, rem)
    return [o, r.getrandbits(32)]


S(0x4bc050, 'ZSoundRandomVolume::ActivateVolume', 'thiscall', None, ret=None,
  gen=lambda c: [rnd(c, 0x100), c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])], note='u18')
S(0x59a850, 'ZGameOSD::RemoveActorActionMarker', 'thiscall', None, ret=None, gen=_rm,
  note='u18; CActorActionMarker::Remove is a logging hook (not lifted)')
