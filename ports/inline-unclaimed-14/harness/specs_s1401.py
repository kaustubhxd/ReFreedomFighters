"""specs_s1401.py - unclaimed-14 batch 1 (docs/20-unclaimed-14.md): ZOctree origin copies (0x4e3340, 0x4e3360), ZFFActor
close-combat flag setters (0x5a2c30, 0x5a2c50, 0x5a2c70) and ZCollisionBase::UnlockCollisionBox (0x4ede70).
Each function is thiscall with the object as 0x800 random bytes, so every store lands inside it. Bool arguments are
random 32-bit values drawn from edge values too, so the low-byte test is exercised with nonzero high bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_ptr(c):
    # GetOrigin: the out pointer is a fresh 12-byte buffer, so the copy is compared byte for byte.
    return [_rnd(c, 0x800), _rnd(c, 12)]


def _obj_in(c):
    # SetOrigin: the argument is a fresh 12-byte source buffer.
    return [_rnd(c, 0x800), _rnd(c, 12)]


def _obj_bool(c):
    return [_rnd(c, 0x800), c.rng.choice([0, 1, 0x100, 0xff, 0x80, 0x10000, c.rng.getrandbits(32)])]


def _obj_box(c):
    # UnlockCollisionBox: the argument is never read; a random value stands in for the box pointer.
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x4e3340, 'ZOctree::GetOrigin (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_ptr,
  note='unclaimed-14 batch 1; copies this+4..+0x10 to the out pointer')
S(0x4e3360, 'ZOctree::SetOrigin (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_in,
  note='unclaimed-14 batch 1; copies the argument to this+4..+0x10')
S(0x5a2c30, 'ZFFActor::SetCloseCombatAttack (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-14 batch 1; low byte of arg, bit 0x2 at +0x7a6')
S(0x5a2c50, 'ZFFActor::SetCloseCombatEnable (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-14 batch 1; low byte of arg, bit 0x1 at +0x7a6')
S(0x5a2c70, 'ZFFActor::SetCloseCombatEvade (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-14 batch 1; low byte of arg, bit 0x4 at +0x7a6')
S(0x4ede70, 'ZCollisionBase::UnlockCollisionBox (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_box,
  note='unclaimed-14 batch 1; calls 0x4eb340 with this+4 (original code)')
