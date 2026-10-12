"""specs_s918.py - unclaimed-01 claim 17 (docs/20-unclaimed-01.md): ZLnkAction::~ZLnkAction (0x460c80). The exe's delete
(0x634273, cdecl) is patched with a logging cdecl stub: it records its two arguments in a ring and counts the call, then
returns with ret 0 (the caller pops, as the exe's call site does). The patch is undone by the next run's restore."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cdecl_log(c):
    P = lambda v: struct.pack('<I', v & 0xffffffff)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(16, 4)
    c.emu.wbytes(ring, bytes(16))
    b = (b'\x8b\x54\x24\x04' + b'\x89\x15' + P(ring)            # mov edx,[esp+4]; mov [ring],edx
         + b'\x8b\x54\x24\x08' + b'\x89\x15' + P(ring + 4)      # mov edx,[esp+8]; mov [ring+4],edx
         + b'\xff\x05' + P(cnt) + b'\xc3')                      # inc [cnt]; ret 0 (cdecl)
    return ss.code(c, b)


def _dtor(c):
    ss.patch(c, 0x634273, _cdecl_log(c))
    o = _rnd(c, 0x40)
    return [o, c.rng.getrandbits(32)]


S(0x460c80, 'ZLnkAction::~ZLnkAction (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-01 claim 17; delete 0x634273 patched with a logging cdecl stub')
