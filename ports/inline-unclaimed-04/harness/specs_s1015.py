"""specs_s1015.py - unclaimed-04 batch 16 (docs/20-unclaimed-04.md): four slice-3 leaves (GUESS labels).
0x658130 is thiscall with two stack arguments (ret 8) and returns al = 1. 0x608130 and 0x499970 store a vtable (the
object is 0x100 random bytes; 0x499970 also clears the dword at +0xc). 0x658db0 returns the dword at +0x48 plus 0x20."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x100)]


def _obj_two(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x658130, 'unknown::returns_true (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj_two,
  note='unclaimed-04 batch 16; al = 1, ret 8')
S(0x608130, 'unknown::set_vtable_6bc88c (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-04 batch 16; stores vtable 0x6bc88c')
S(0x658db0, 'unknown::get_48_plus20 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-04 batch 16; dword at +0x48 plus 0x20')
S(0x499970, 'unknown::set_vtable_68e9cc_clear_c (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-04 batch 16; stores vtable 0x68e9cc and clears +0xc')
