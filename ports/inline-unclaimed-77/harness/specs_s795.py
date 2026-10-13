"""specs_s795.py - unclaimed-77 claim 30 (docs/20-unclaimed-77.md): REFTAB::AddUnique(unsigned int). Thiscall, one argument, ret 4.
The object's slot 0x2c returns a constant pointer value p (zero in half the cases, so both branches run); slot 0x4 returns a random value.
Both are loggers of the key (GUESS): they record the argument and return their constant in eax."""
from pilot import S
import struct
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log_ret(c, retval):
    """Thiscall, one stack argument (ret 4): logs the argument in an 8-entry ring, returns retval in eax."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10' + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(retval) + b'\xc2\x04\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x40)
    p = 0 if c.rng.random() < 0.5 else (c.rng.getrandbits(31) | 0x1000)
    obj = ss.mkobj(c, {0x2c: _log_ret(c, p), 0x4: _log_ret(c, c.rng.getrandbits(32))}, size=0x40)
    return [obj, c.rng.getrandbits(32)]


S(0x4cd980, 'REFTAB::AddUnique (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-77 claim 30; slots 0x2c and 0x4 stubbed (GUESS)')
