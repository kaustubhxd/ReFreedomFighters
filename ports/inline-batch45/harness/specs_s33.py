"""specs_s33.py - inline session batch 33 (Haiku, night): 0x5e17b0 CalcNewSpeed (virtual call to ZPlayer::GetMoveSpeeds,
GetAnimFromStatus and vsetlen run as original code)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


BASEMOVE_VT = 0x6b75a0   # ZFFHeroMovementBaseMove vtable
ANIMLIST_VT = 0x68b604   # ZAnimDefsList vtable (slot 0x10 is GetAnim, 0x4837e0)
PLAYER_VT = 0x68b650     # ZPlayer vtable (slot 0x5c4 is GetMoveSpeeds, 0x483b10)


def _cns(c):
    r = c.rng
    obj = _rnd(c, 0x800)
    c.emu.w32(obj, BASEMOVE_VT)
    p = _rnd(c, 0x500)
    c.emu.w32(p + 0x417, r.getrandbits(32))
    c.emu.w32(obj + 4, p)
    player = _rnd(c, 0x900)
    c.emu.w32(player, PLAYER_VT)
    c.emu.w32(obj + 0x36d, player)
    c.emu.wf32(player + 0x80f, c.fv())
    c.emu.wbytes(obj + 0x371, bytes([0 if r.random() < 0.7 else 1]))
    c.emu.wbytes(obj + 0x372, bytes([0 if r.random() < 0.8 else 1]))
    anim = _rnd(c, 0x80)
    c.emu.w32(anim, ANIMLIST_VT)
    c.emu.w32(anim + 0x14, 0)   # no REFTAB list (see batch 32 note)
    c.emu.w32(obj + 0x523, anim)
    outA = _rnd(c, 0x20)
    outB = _rnd(c, 0x20)
    return [obj, r.getrandbits(32), r.getrandbits(32), outA, outB]


S(0x5e17b0, 'ZFFHeroMovementBaseMove::CalcNewSpeed', 'thiscall', None, ret=None, gen=_cns,
  note='batch33; virtual call through the player vtable slot 0x5c4; GetAnimFromStatus and vsetlen as original code')
