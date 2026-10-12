"""specs_s1601.py - unclaimed-16 batch 1 (docs/20-unclaimed-16.md): ZActor getters, ZActor::NoCageCheck,
ZFFActor::GetAmmoFor, GetKnockedOut and the three SetCloseCombat* bool setters. Object is 0x1000 random bytes (larger than every offset used), so each
read and write lands inside it. Bool arguments are full random dwords (only the low byte is read, as the exe does)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _obj_u32(c):
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


GETTERS = [
    (0x478630, 'ZActor::EndDir', 0x69a, 'ptr'),
    (0x4789e0, 'ZActor::GetActiveMoveSet', 0x4ae, 'u32'),
    (0x4789f0, 'ZActor::GetActorList', 0x73a, 'u32'),
    (0x478a60, 'ZActor::GetActorState', 0x65c, 'u32'),
    (0x478b30, 'ZActor::GetAudibleRoomList', 0x5ca, 'u32'),
    (0x478b40, 'ZActor::GetCage', 0x6bf, 'u32'),
    (0x478b50, 'ZActor::GetCurrentMoveType', 0x650, 'u32'),
    (0x478b60, 'ZActor::GetCurrentRoom', 0x736, 'u32'),
    (0x47c530, 'ZActor::TrackObjPos', 0x660, 'ptr'),
]

for addr, name, off, kind in GETTERS:
    S(addr, name + ' (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
      note='unclaimed-16; ' + ('address of +0x%x' % off if kind == 'ptr' else 'dword at +0x%x' % off))

S(0x479740, 'ZActor::NoCageCheck (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-16; byte 1 to +0x6c3')

S(0x59fce0, 'ZFFActor::GetAmmoFor (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_u32,
  note='unclaimed-16; returns 999, argument ignored')
S(0x59fe70, 'ZFFActor::GetKnockedOut (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-16; byte at +0x929')

for addr, name in [(0x5a2c30, 'SetCloseCombatAttack'), (0x5a2c50, 'SetCloseCombatEnable'),
                   (0x5a2c70, 'SetCloseCombatEvade')]:
    S(addr, 'ZFFActor::' + name + ' (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
      note='unclaimed-16; bit of dword at +0x7a6 from low byte of bool')
