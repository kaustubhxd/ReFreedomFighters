"""specs_s790.py - unclaimed-77 claim 20 (docs/20-unclaimed-77.md): CGlobalCom::~CGlobalCom. Thiscall, one argument (random flags),
ret 4, returns this. The CRT delete 0x634273 is a logger stub (GUESS): cdecl, logs its two arguments and pops nothing."""
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _recc2(c):
    """Cdecl stub with two stack arguments (p, n): logs both in an 8-entry ring, pops nothing, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\x31\xc0\xc3')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x40)
    ss.patch(c, 0x634273, _recc2(c))
    return [self, c.rng.getrandbits(32)]


S(0x4d2480, 'CGlobalCom::~CGlobalCom (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-77 claim 20; CRT delete 0x634273 stubbed (GUESS)')
