"""specs_s1012.py - area 81, batch 1012: CActionController::FrameUpdate (0x4a0970). The debug-print floats at sys+0x9c7 and +0x9c3 are zero, so the
trapped branches are never reached. The helpers 0x4a1e00 and 0x4a1710 are counting stubs; 0x634da6 is a cdecl stub that returns 2*x in st0. The
global controller P (0x7002a8) is present in most cases: its slot 0x4c writes a random flag, its slot 0x5c returns the element E and writes the flag
from a table (ones first, then zeros), its slot 0 is a counting stub. The global Q (0x70038c) slot 0xcc returns a fixed R (or null), R's slots 0x5c
and 0xb4 are counting stubs, and the render manager's slot 0x58 returns a random word. Each element has a random +0x804 count and seven pointers."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4a1e00, ss.rec(c, 0))
    ss.patch(c, 0x4a1710, ss.rec(c, 1))
    dbl = c.emu.alloc(16, 16)
    c.emu.wbytes(dbl, b'\xdd\x44\x24\x04' + b'\xdc\xc0' + b'\xc3')   # fld qword [esp+4]; fadd st0,st0; ret
    ss.patch(c, 0x634da6, dbl)
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9c7, 0)
    c.emu.w32(sysobj + 0x9c3, 0)
    rm = obj(c, 0x40, {0x58: _stub(c, 1, ret=r32(c))})
    c.emu.w32(sysobj + 0x9b, rm)
    R = obj(c, 0x40, {0x5c: _stub(c, 3), 0xb4: _stub(c, 1)}) if rnd.random() < 0.7 else 0
    Q = obj(c, 0x40, {0xcc: _stub(c, 1, ret=R)})
    c.emu.w32(0x70038c, Q)
    c.emu.wbytes(0x7002d4, bytes([rnd.randint(0, 255), rnd.randint(0, 255)]))
    if rnd.random() < 0.85:
        E = obj(c, 0x40)
        tbl = c.emu.alloc(4 * 64, 4)
        for i in range(64):
            c.emu.w32(tbl + 4 * i, (rnd.randint(0, 1) if i < 32 else 0))
        cnt = c.emu.alloc(4, 4)
        c.emu.w32(cnt, 0)
        getter = c.emu.alloc(64, 16)
        code = (b'\x8b\x44\x24\x04'                                 # mov eax,[esp+4]  (&flag)
                + b'\x8b\x15' + struct.pack('<I', cnt)              # mov edx,[cnt]
                + b'\x8b\x0c\x95' + struct.pack('<I', tbl)          # mov ecx,[tbl+edx*4]
                + b'\x89\x08'                                       # mov [eax],ecx
                + b'\xff\x05' + struct.pack('<I', cnt)              # inc dword [cnt]
                + b'\xb8' + struct.pack('<I', E)                    # mov eax,E
                + b'\xc2\x04\x00')                                  # ret 4
        c.emu.wbytes(getter, code)
        P = obj(c, 0x40, {0x4c: _stub(c, 1, skip=(0,), ofills=((0, 0, c.emu.alloc(4, 4), 1),)), 0x5c: getter, 0: _stub(c, 1)})
    else:
        P = 0
    c.emu.w32(0x7002a8, P)
    n = rnd.randint(0, 4)
    self_ = obj(c, 0x200)
    c.emu.w32(self_ + 0x48, n)
    for j in range(n):
        X = obj(c, 0x840)
        c.emu.w32(X + 0x804, rnd.randint(-2, 6) & 0xffffffff)
        for k in range(8):
            c.emu.w32(X + 4 + 4 * k, obj(c, 0x40))
        c.emu.w32(self_ + 0x5c + 4 * j, X)
        c.emu.w32(self_ + 0x4c + 4 * j, rnd.randint(-3, 8) & 0xffffffff)
    return [self_]


S(0x4a0970, 'CActionController::FrameUpdate', 'thiscall', gen=g)
