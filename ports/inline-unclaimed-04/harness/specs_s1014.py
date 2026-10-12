"""specs_s1014.py - unclaimed-04 batch 15 (docs/20-unclaimed-04.md): five slice-3 leaves (GUESS labels).
Objects are random blocks large enough for their offsets (0x6000 bytes for the counter at +0x5d39). 0x57c4f0 reads a
global, which the image holds; the port reads the same address."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x100)]


def _big(c):
    return [_rnd(c, 0x6000)]


S(0x49d6b0, 'unknown::get_10 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-04 batch 15; dword at +0x10')
S(0x57c4f0, 'unknown::get_global_6ecdc0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-04 batch 15; global 0x6ecdc0')
S(0x432630, 'unknown::byte_fc (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-04 batch 15; byte at +0xfc')
S(0x48f6f0, 'unknown::inc_5d39 (unknown) thiscall', 'thiscall', None, ret=None, gen=_big,
  note='unclaimed-04 batch 15; dword at +0x5d39 incremented')
S(0x54ccf0, 'unknown::set_vtable_6a3dd0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-04 batch 15; stores vtable 0x6a3dd0')
