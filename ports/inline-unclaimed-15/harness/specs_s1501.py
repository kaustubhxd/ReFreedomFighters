"""specs_s1501.py - unclaimed-15 claim 1 (docs/20-unclaimed-15.md): ZFFActor::SetCloseCombatAttack (0x5a2c30),
SetCloseCombatEnable (0x5a2c50), SetCloseCombatEvade (0x5a2c70) and GetLastHitPos (0x59fe80).
Objects are 0x1000 random bytes (the flag dword sits at +0x7a6, the hit point at +0x8fb..+0x907). The bool argument is
drawn from {0, 1, 0x100, 0x80000000, random}: 0x100 has a zero low byte with a nonzero dword, so a dword test and a byte
test give different answers. GetLastHitPos writes three dwords to a 12-byte out buffer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_bool(c):
    o = _rnd(c, 0x1000)
    return [o, c.rng.choice([0, 1, 0x100, 0x80000000, c.rng.getrandbits(32)])]


def _obj_out(c):
    return [_rnd(c, 0x1000), _rnd(c, 12)]


S(0x5a2c30, 'ZFFActor::SetCloseCombatAttack (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-15 claim 1; bit 0x2 of dword +0x7a6 by low byte of arg')
S(0x5a2c50, 'ZFFActor::SetCloseCombatEnable (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-15 claim 1; bit 0x1 of dword +0x7a6 by low byte of arg')
S(0x5a2c70, 'ZFFActor::SetCloseCombatEvade (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-15 claim 1; bit 0x4 of dword +0x7a6 by low byte of arg')
S(0x59fe80, 'ZFFActor::GetLastHitPos (unknown) thiscall const', 'thiscall', None, ret=None, gen=_obj_out,
  note='unclaimed-15 claim 1; copies dwords +0x8fb, +0x8ff, +0x903 to out')
