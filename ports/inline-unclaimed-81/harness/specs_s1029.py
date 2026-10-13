"""specs_s1029.py - area 81, batch 1029: 0x5f2c60 (string append of [A, B)). The object's begin, end and cap-end are a heap block with a random size S (0..60)
and a capacity above S (S+0..S+80). The range is 1..40 bytes of random letters (a separate heap buffer). The allocator 0x6014a0 is a thiscall bump over a
random pool (returns the old bump and advances it by the size). 0x54f870 counts its arguments. The import VCRUNTIME140!memmove is installed as a Python
handler (cdecl: dst, src, n; copies through the emulator's memory and returns dst)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj, r32


def _memmove(e, r):
    dst = e.arg32(0)
    src = e.arg32(1)
    n = e.arg32(2)
    if n:
        e.wbytes(dst, e.rbytes(src, n))
    e.ret(eax=dst, argbytes=0)


def g(c):
    rnd = c.rng
    try:
        c.emu.stub_import('memmove', _memmove)
    except KeyError:
        pass
    pool = c.emu.alloc(0x4000, 16)
    c.emu.wbytes(pool, bytes(rnd.getrandbits(8) for _ in range(0x4000)))
    bump = c.emu.alloc(4, 4)
    c.emu.w32(bump, pool)
    code = (b'\x8b\x15' + struct.pack('<I', bump)          # mov edx,[bump]
            + b'\x8b\x44\x24\x04'                           # mov eax,[esp+4]
            + b'\x01\x05' + struct.pack('<I', bump)         # add [bump],eax
            + b'\x89\xd0'                                   # mov eax,edx
            + b'\xc2\x04\x00')                              # ret 4
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    ss.patch(c, 0x6014a0, a)
    ss.patch(c, 0x54f870, ss.rec(c, 2))
    letters = b'abcdefghijklmnopqrstuvwxyz0123456789'
    self_ = obj(c, 0x40)
    buf = c.emu.alloc(0x200, 16)
    S_ = rnd.randint(0, 60)
    C_ = S_ + rnd.randint(0, 80)
    c.emu.wbytes(buf, bytes(rnd.choice(letters) for _ in range(0x200)))
    c.emu.w32(self_ + 0, buf)
    c.emu.w32(self_ + 4, buf + S_)
    c.emu.w32(self_ + 8, buf + C_)
    src = c.emu.alloc(0x80, 16)
    n = rnd.randint(1, 40)
    c.emu.wbytes(src, bytes(rnd.choice(letters) for _ in range(0x80)))
    return [self_, src, src + n]


S(0x5f2c60, 'GUESS 0x5f2c60 string append', 'thiscall', gen=g)
