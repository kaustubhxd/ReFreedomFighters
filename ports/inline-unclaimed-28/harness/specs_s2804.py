"""specs_s2804.py - unclaimed-28 batch 4 (docs/20-unclaimed-28.md): ZSewerControl::TakeDataOutOfBuffer (0x5b1870). The readers
0x5f0280 (dword) and 0x5f02f0 (byte) are patched to stubs that write a random value into the destination pointer; the first
dword is 1 about 70% of the time (the loop path). The error path calls through the logger global 0x700390, which the gen
points at a fake object whose vtable slot +0x20 returns a second fake object with a logging cdecl slot +0x2c."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

READ_DWORD, READ_BYTE = 0x5f0280, 0x5f02f0


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _read_stub(c, name, addr, width, first_one):
    st = {'n': 0}

    def h(e, r):
        dst = e.arg32(0)
        st['n'] += 1
        if width == 4:
            v = 1 if (first_one and st['n'] == 1) else c.rng.getrandbits(32)
            e.w32(dst, v)
        else:
            e.w8(dst, c.rng.getrandbits(8))
        e.calllog.append((name, e.reg('ecx'), dst))
        e.ret(eax=0, argbytes=4)
    ss.patch(c, addr, c.emu.stub_fn(name, h))


def _take(c):
    self_ = _rnd(c, 0x200)
    buf = _rnd(c, 0x100)
    c.emu.w8(buf + 0xc, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(8))
    first_one = c.rng.random() < 0.7
    _read_stub(c, 'CBuffer::ReadDword', READ_DWORD, 4, first_one)
    _read_stub(c, 'CBuffer::ReadByte', READ_BYTE, 1, first_one)
    obj2 = _rnd(c, 0x20)
    vt2 = c.emu.fake_vtable('logger-obj2', 0x30, {0x2c: logged_slot('Logger::cdecl2c', eax=0, argbytes=0)})
    c.emu.w32(obj2, vt2)
    vt1 = c.emu.fake_vtable('logger-obj1', 0x9, {0x20: logged_slot('Logger::get20', eax=obj2, argbytes=8)})
    obj1 = _rnd(c, 0x20)
    c.emu.w32(obj1, vt1)
    c.emu.w32(0x700390, obj1)
    return [self_, buf]


S(0x5b1870, 'ZSewerControl::TakeDataOutOfBuffer(CBuffer&) thiscall', 'thiscall', None, ret='al', gen=_take,
  note='unclaimed-28 batch 4; reads dword sentinel, 19 x (byte, 3 dwords, byte); error path logs via 0x700390')
