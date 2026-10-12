"""specs_s1001.py - unclaimed-04 batch 1 (docs/20-unclaimed-04.md): eight leaf accessors.
Objects are 0x800 random bytes so every load and store lands inside memory the harness compares. The pointer-following
getter 0x647170 gets a second 0x800-byte record at +0x291, so its byte load stays inside the harness's memory."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x800)]


def _big(c):
    return [_rnd(c, 0x1400)]


def _obj_ptr(c):
    o = _rnd(c, 0x800)
    # a quarter of the cases have a null pointer, so the zero branch runs
    c.emu.w32(o + 0x291, 0 if c.rng.random() < 0.25 else _rnd(c, 0x800))
    return [o]


S(0x438790, 'unknown::dec_dword_120c (unknown) thiscall', 'thiscall', None, ret=None, gen=_big,
  note='unclaimed-04 batch 1; dec dword at +0x120c (object is 0x1400 bytes), no GC name')
S(0x647170, 'unknown::byte_via_291 (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj_ptr,
  note='unclaimed-04 batch 1; byte at [[+0x291]+0x15], 0 when the pointer is null')
S(0x647190, 'unknown::byte_295 (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-04 batch 1; byte at +0x295')
S(0x4fc680, 'CMAINCAMERACONTROL::GetOldCam (low) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-04 batch 1; dword at +0x74')
S(0x4fdd10, 'CMAINCAMERACONTROL::ToggleFreeCam (low, GUESS) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-04 batch 1; byte at +0x69 set to 1')
S(0x5231b0, 'CMoveAlongPath::DirFactor (low) thiscall', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-04 batch 1; float at +0x20 to st0')
S(0x523460, 'CMoveAlongPath::GetPath (low) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-04 batch 1; dword at +0x4b to eax')
S(0x523980, 'CMoveAlongPath::PathLength (low) thiscall', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-04 batch 1; float at +0x53 to st0')
