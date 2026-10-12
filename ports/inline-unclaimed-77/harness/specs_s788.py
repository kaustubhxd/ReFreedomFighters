"""specs_s788.py - unclaimed-77 claim 18 (docs/20-unclaimed-77.md): ZSysInterface::SetOption(const char*, const char*). Thiscall, two
stack arguments (ret 8). The two strings are random 32-byte blocks. The callee 0x4d3a00 is a logger stub (GUESS): it logs its three
stack arguments (ret 12) and writes nothing; the this value is the constant 0x6ff938 and is not dereferenced."""
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log4d3a00(c):
    """Thiscall, three stack arguments (ret 12): logs the three arguments in an 8-entry ring (3 dwords each), writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\x8b\x54\x24\x0c\x89\x50\x08'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xc2\x0c\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x40)
    ss.patch(c, 0x4d3a00, _log4d3a00(c))
    return [self, _rnd(c, 32), _rnd(c, 32)]


S(0x42fb40, 'ZSysInterface::SetOption (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 18; callee 0x4d3a00 stubbed (GUESS, logs three arguments)')
