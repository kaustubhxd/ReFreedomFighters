"""specs_s2483.py - decomp area 24, batch 2483.
0x4a0e90 CAction::FrameUpdate(), thiscall, void: sets bit 0 of the dword at +0x5a.
0x5e7590 ZFFHeroMovementBaseMove::WantControl(3 pointers), thiscall, ret 0xc, AL = 1.
0x5c4190 ZRepositionCharacter::End(), thiscall, void: tail jump to slot 0xc of the object at +0x48 (recorder, zero args)."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _frame(c):
    clear_hooks(c)
    o = rnd(c, 0x100)
    return [o]


def _want(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x100)
    return [o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _end(c):
    clear_hooks(c)
    e = c.emu
    o = rnd(c, 0x100)
    child = obj(c, 0x40, {0xc: pystub(c, 0)})
    e.w32(o + 0x48, child)
    return [o]


S(0x4a0e90, 'CAction::FrameUpdate', 'thiscall', None, ret=None, gen=_frame, note='batch2483')
S(0x5e7590, 'ZFFHeroMovementBaseMove::WantControl', 'thiscall', None, ret='al', gen=_want, note='batch2483')
S(0x5c4190, 'ZRepositionCharacter::End', 'thiscall', None, ret=None, gen=_end, note='batch2483')
