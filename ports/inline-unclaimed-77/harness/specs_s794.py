"""specs_s794.py - unclaimed-77 claims 27 to 29 (docs/20-unclaimed-77.md). Stubs (GUESS): loggers for 0x57cdc0, 0x5edea0 (plain ret, log ecx),
0x57ece0 (log ecx and one argument), 0x634273 (CRT delete, cdecl, logs two arguments, pops nothing), and the object's slot 0xc (logs its
argument, returns a block pointer in eax)."""
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


def _log_ecx(c):
    """Thiscall, no arguments, plain ret: logs ecx in an 8-entry ring, writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x89\x08' + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


def _log_ecx_arg(c):
    """Thiscall, one argument, ret 4: logs ecx and the argument in an 8-entry ring (8 bytes each), writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x89\x08' + b'\x8b\x54\x24\x04\x89\x50\x04' + b'\xff\x05' + ss.P(cnt)
         + b'\xc2\x04\x00')
    return ss.code(c, b)


def _recc2(c):
    """Cdecl stub with two stack arguments (p, n): logs both, pops nothing, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10' + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt) + b'\x31\xc0\xc3')
    return ss.code(c, b)


def _ret_block(c, blk, logged_ret=None):
    """Thiscall, one argument, ret 4: logs the argument in an 8-entry ring, returns blk in eax."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10' + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(blk) + b'\xc2\x04\x00')
    return ss.code(c, b)


def _gen_57d880(c):
    self = _rnd(c, 0x40)
    ss.patch(c, 0x57cdc0, _log_ecx(c))
    ss.patch(c, 0x57ece0, _log_ecx_arg(c))
    return [self]


def _gen_656680(c):
    blk = _rnd(c, 0x40)
    c.emu.w32(blk + 0x2c, c.rng.getrandbits(32))
    c.emu.wbytes(blk + 2, bytes([0, 0]) if c.rng.random() < 0.5 else bytes([1, 0]))
    obj = ss.mkobj(c, {0xc: _ret_block(c, blk)}, size=0x40)
    return [obj, c.rng.getrandbits(32)]


def _gen_5edf40(c):
    self = _rnd(c, 0x40)
    ss.patch(c, 0x5edea0, _log_ecx(c))
    ss.patch(c, 0x634273, _recc2(c))
    return [self, c.rng.getrandbits(32)]


S(0x57d880, 'GUESS FUN_57d880 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_57d880,
  note='unclaimed-77 claim 27; callees 0x57cdc0 and 0x57ece0 stubbed (GUESS)')
S(0x656680, 'GUESS FUN_656680 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_656680,
  note='unclaimed-77 claim 28; slot 0xc stub returns a block (GUESS)')
S(0x5edf40, 'GUESS FUN_5edf40 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_5edf40,
  note='unclaimed-77 claim 29; 0x5edea0 and CRT delete stubbed (GUESS)')
