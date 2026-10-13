"""specs_s1002.py - area 81 (residue 0), batch 1002: ZInputActions::RemoveActionMaps (0x43a800). The list object's slots 0x4c (writes the flag)
and 0x44 are stubs; 0x5c is a machine-code iterator that returns the next element and writes the flag (one to K-1 times). The CRT free
(0x634273, cdecl) and the GUESS helper 0x43a900 are stood in. Elements have a vtable word (written by the port), a free pointer, a slot-0
object and a back pointer whose field at +0x1334 is random. Zero-length lists are reached through the K=1..3 counts."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    ss.patch(c, 0x634273, cstub(c, 2))
    ss.patch(c, 0x43a900, ss.rec(c, 0))
    k = c.rng.randint(1, 3)
    elems = []
    for _ in range(k):
        e = obj(c, 0x1400)
        m = obj(c, 0x40) if c.rng.random() < 0.6 else 0
        o = obj(c, 0x40, {0: _stub(c, 1)}) if c.rng.random() < 0.6 else 0
        c.emu.w32(e + 8, m)
        c.emu.w32(e + 0x19, o)
        b = obj(c, 0x1400)
        c.emu.w32(b + 0x1334, e if c.rng.random() < 0.5 else r32(c))
        c.emu.w32(e + 0x11, b)
        elems.append(e)
    table = c.emu.alloc(4 * (k + 1), 4)
    for i, e in enumerate(elems):
        c.emu.w32(table + 4 * i, e)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code5c = (b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]   (flag pointer)
              + b'\x8b\x15' + struct.pack('<I', cnt)              # mov edx,[cnt]
              + b'\x8b\x0c\x95' + struct.pack('<I', table)        # mov ecx,[table+edx*4]
              + b'\xff\x05' + struct.pack('<I', cnt)              # inc dword [cnt]
              + b'\xc7\x00\x00\x00\x00\x00'                       # mov dword [eax],0 (the caller tests a full dword)
              + b'\x83\xfa' + bytes([k - 1])                      # cmp edx,K-1
              + b'\x7d\x06'                                       # jge +6
              + b'\xc7\x00\x01\x00\x00\x00'                       # mov dword [eax],1
              + b'\x89\xc8'                                       # mov eax,ecx
              + b'\xc2\x04\x00')                                  # ret 4
    a5c = c.emu.alloc(len(code5c) + 16, 16)
    c.emu.wbytes(a5c, code5c)
    l = obj(c, 0x40, {0x4c: _stub(c, 1, skip=(0,)), 0x44: _stub(c, 1, skip=(0,)), 0x5c: a5c})
    t = obj(c, 0x2000)
    c.emu.w32(t + 0x1214, l if c.rng.random() < 0.9 else 0)
    return [t]


S(0x43a800, 'ZInputActions::RemoveActionMaps', 'thiscall', None, gen=g)
