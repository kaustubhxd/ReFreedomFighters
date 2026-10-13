"""specs_s796.py - unclaimed-77 claims 31 to 34 (docs/20-unclaimed-77.md), residue 4. Stubs (GUESS): 0x43de70 (the base-destructor thunk, replaced
by a logger of ecx that stores nothing and returns plain). The objects are 0x1000 random bytes; the byte read at +0x1e is random."""
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log_ecx(c):
    """Thiscall, no arguments, plain ret: logs ecx in an 8-entry ring, writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x89\x08' + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


def _obj(c):
    return [_rnd(c, 0x1000)]


def _gen_grt(c):
    return [_rnd(c, 0x1000)] + [c.rng.getrandbits(32) for _ in range(8)]


def _gen_44c400(c):
    ss.patch(c, 0x43de70, _log_ecx(c))
    return [_rnd(c, 0x1000)]


S(0x64fb80, 'ZRender::GetClippedPrimTriangles (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_grt,
  note='unclaimed-77 claim 31; ret 0x20, no body')
S(0x608140, 'GUESS FUN_608140 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-77 claim 32; stores vtable 0x6bc884')
S(0x612140, 'ZRender::ShadowMode (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-77 claim 33; byte at +0x1e')
S(0x44c400, 'GUESS FUN_44c400 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_44c400,
  note='unclaimed-77 claim 34; stores vtable 0x67ff2c; 0x43de70 stubbed (GUESS)')
