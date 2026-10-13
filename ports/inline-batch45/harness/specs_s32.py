"""specs_s32.py - inline session batch 32 (Haiku, night): 0x5e3dd0 GetAnimFromStatus (virtual calls to exe code)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


BASEMOVE_VT = 0x6b75a0   # ZFFHeroMovementBaseMove vtable: slot 0x60 GetActiveWalkDefsList, 0x64 GetActiveRunDefsList
ANIMLIST_VT = 0x68b604   # ZAnimDefsList vtable: slot 0x10 at 0x4837e0


def _gas(c):
    r = c.rng
    obj = _rnd(c, 0x800)
    c.emu.w32(obj, BASEMOVE_VT)
    p = _rnd(c, 0x500)
    c.emu.w32(p + 0x417, r.getrandbits(32))
    c.emu.w32(obj + 4, p)
    anim = _rnd(c, 0x80)
    c.emu.w32(anim, ANIMLIST_VT)
    c.emu.w32(anim + 0x14, 0)   # no REFTAB list: GetAnim returns the current value without its loop
    c.emu.w32(obj + 0x523, anim)
    return [obj, r.getrandbits(32)]


S(0x5e3dd0, 'ZFFHeroMovementBaseMove::GetAnimFromStatus', 'thiscall', None, ret='eax', gen=_gas,
  note='batch32; calls through the exe vtables (BaseMove slots 0x60/0x64, ZAnimDefsList slot 0x10); status bits pick the path')
