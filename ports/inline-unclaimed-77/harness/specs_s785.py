"""specs_s785.py - unclaimed-77 claim 15 (docs/20-unclaimed-77.md): ZEngineDataBase::CreateGlobalStripColiTree. Thiscall, no arguments,
plain ret. The object's +0xafc is random; the render-manager (global 0x70039c) has a pointer at +0x1aa3 to a block whose +0x1c is the
tree-builder's this. The callee 0x4edc10 is a logger stub (GUESS): it logs this and its argument, and returns."""
from pilot import S
import struct
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log_tree(c):
    """Thiscall, one stack argument (ret 4): logs ecx (this) and the argument in an 8-entry ring, writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x89\x08'
         + b'\x8b\x54\x24\x04\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xc2\x04\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0xC00)
    ss.patch(c, 0x4edc10, _log_tree(c))
    Q = _rnd(c, 0x40)
    P = _rnd(c, 0x40)
    c.emu.w32(P + 0x1c, Q)
    RM = _rnd(c, 0x1b00)
    c.emu.w32(RM + 0x1aa3, P)
    c.emu.w32(0x70039c, RM)
    return [self]


S(0x48edc0, 'ZEngineDataBase::CreateGlobalStripColiTree (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 15; tree builder 0x4edc10 stubbed (GUESS, logs this and its argument)')
