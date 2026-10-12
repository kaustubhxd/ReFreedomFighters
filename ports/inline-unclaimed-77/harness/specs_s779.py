"""specs_s779.py - unclaimed-77 claim 9 (docs/20-unclaimed-77.md): two forwarders. Thiscall. The targets 0x465850 (thiscall, one
argument, ret 4) and 0x48aa80 (thiscall, no arguments, plain ret) are replaced by loggers (GUESS). Each logger records ecx and its
arguments into a ring of 8 entries (32 bytes each) and returns 0, so the forwarded values are compared, not their stack addresses."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _logn(c, nargs):
    """Thiscall logger: records ecx and up to nargs stack arguments (ring of 8 entries, 8 dwords each), returns 0 and pops 4*nargs."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(256, 4)
    c.emu.wbytes(ring, bytes(256))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + ss.P(ring)
         + b'\x89\x08')                                        # mov [eax], ecx
    for i in range(nargs):
        disp = 4 + 4 * i
        b += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x50' + bytes([disp])   # mov edx,[esp+4+4i]; mov [eax+disp], edx
    b += b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, b)


def _gen_a(c):
    self = _rnd(c, 0x1000)
    ss.patch(c, 0x465850, _logn(c, 1))
    return [self, c.rng.getrandbits(32)]


def _gen_b(c):
    self = _rnd(c, 0x1000)
    ss.patch(c, 0x48aa80, _logn(c, 0))
    return [self]


S(0x472440, 'GUESS FUN_472440 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_a,
  note='unclaimed-77 claim 9; tail-jump forwarder to 0x465850 (stub, GUESS)')
S(0x476540, 'GUESS FUN_476540 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_b,
  note='unclaimed-77 claim 9; tail-jump forwarder to 0x48aa80 (stub, GUESS)')
