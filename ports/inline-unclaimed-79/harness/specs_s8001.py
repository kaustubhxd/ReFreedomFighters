"""specs_s8001.py - unclaimed-79 gap-band accessor group 1 (docs/20-unclaimed-79.md). Each function gets a random object; the object is big enough for its offset."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

S(0x4827b0, 'ZPlayer::ControlsEnabled() const getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 1544)],
  note='unclaimed-79 gap-band getter +0x600')

S(0x4834c0, 'ZPlayer::EnableT1() zero', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 1542)],
  note='unclaimed-79 gap-band zero store +0x5fe')

S(0x483b00, 'ZPlayer::GetGroundContact() const getter', 'thiscall', None, ret='al', gen=lambda c: [_obj(c, 1076)],
  note='unclaimed-79 gap-band getter +0x42c')

S(0x483ea0, 'ZPlayer::GetSoundSet() const getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 1558)],
  note='unclaimed-79 gap-band getter +0x60e')

S(0x483ed0, 'ZPlayer::GetStatus() const getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 1055)],
  note='unclaimed-79 gap-band getter +0x417')

S(0x4875d0, 'CPathUserProfile::GetUser() const getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 16)],
  note='unclaimed-79 gap-band getter +0x6')

S(0x48d000, 'ZEngineGeomControl::Clear() zero', 'thiscall', None, ret=None, gen=lambda c: [_obj(c, 212)],
  note='unclaimed-79 gap-band zero store +0xcc')

S(0x48db60, 'ZTimeUpdateList::Count() getter', 'thiscall', None, ret='eax', gen=lambda c: [_obj(c, 2580)],
  note='unclaimed-79 gap-band getter +0xa0c')

