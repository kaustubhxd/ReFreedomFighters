"""specs_s1381.py - unclaimed-13 claim 1 (docs/20-unclaimed-13.md): ZFFActor::SetCloseCombatAttack (0x5a2c30),
SetCloseCombatEnable (0x5a2c50) and SetCloseCombatEvade (0x5a2c70). Objects are 0x800 random bytes; the flag dword is at
+0x7a6. The argument is a random 32-bit value so the byte test (low byte only) is exercised, with edge values 0, 1, 0x100."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_bool(c):
    return [_rnd(c, 0x800), c.rng.choice([0, 1, 0x100, 0x10000, 0xff, c.rng.getrandbits(32)])]


S(0x5a2c30, 'ZFFActor::SetCloseCombatAttack (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-13 claim 1; bit 0x2 of dword +0x7a6')
S(0x5a2c50, 'ZFFActor::SetCloseCombatEnable (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-13 claim 1; bit 0x1 of dword +0x7a6')
S(0x5a2c70, 'ZFFActor::SetCloseCombatEvade (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_bool,
  note='unclaimed-13 claim 1; bit 0x4 of dword +0x7a6')
