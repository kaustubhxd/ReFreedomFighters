"""specs_s1010.py - unclaimed-02 batch 10 (docs/20-unclaimed-02.md): ZSewerControl::PutDataIntoBuffer (0x5b16d0). The three
CBuffer writers (0x5f01c0 dword, 0x5f0190 byte, 0x5f0220 float) are patched to logging stubs for both sides; the stubs
write nothing, so the return depends only on the buffer's byte at +0xc, which the gen sets to zero half the time."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss

WRITE_DWORD, WRITE_BYTE, WRITE_FLOAT = 0x5f01c0, 0x5f0190, 0x5f0220


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, name, addr):
    def h(e, r):
        e.calllog.append((name, e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)
    ss.patch(c, addr, c.emu.stub_fn(name, h))


def _put(c):
    self_ = _rnd(c, 0x160)
    buf = _rnd(c, 0x100)
    c.emu.w8(buf + 0xc, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(8))
    _stub(c, 'CBuffer::WriteDword', WRITE_DWORD)
    _stub(c, 'CBuffer::WriteByte', WRITE_BYTE)
    _stub(c, 'CBuffer::WriteFloat', WRITE_FLOAT)
    return [self_, buf]


S(0x5b16d0, 'ZSewerControl::PutDataIntoBuffer(CBuffer&) thiscall', 'thiscall', None, ret='al', gen=_put,
  note='unclaimed-02 batch 10; writes dword 1 at +4, then 18 x (byte, 3 floats, byte) from this+0xd; returns buf[0xc]==0')
