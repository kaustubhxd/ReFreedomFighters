"""specs_s955.py - residue-03, batch 955: ZFFActorActionCloseCombat::Load (0x5eb530). The load object's slot 0x40 is a
machine-code stub that returns a table value per call (four calls); slot 0x48 writes a constant through its pointer;
the render manager (0x58) returns constants. Stack-pointer arguments are not recorded (they differ between runs)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
from pilot import S
from vh import _stub, obj, r32


def g(c):
    table = c.emu.alloc(16, 4)
    for k in range(4):
        c.emu.w32(table + 4 * k, r32(c))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]   (out pointer)
    code += b'\x8b\x15' + struct.pack('<I', cnt)                # mov edx,[cnt]
    code += b'\x8b\x0c\x95' + struct.pack('<I', table)          # mov ecx,[table+edx*4]
    code += b'\x89\x08'                                         # mov [eax],ecx
    code += b'\xff\x05' + struct.pack('<I', cnt)                # inc dword [cnt]
    code += b'\xc2\x04\x00'                                     # ret 4
    st40 = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st40, code)
    src = c.emu.alloc(4, 4)
    c.emu.w32(src, r32(c))
    ld = obj(c, 0x40, {0x40: st40,
                       0x48: _stub(c, 1, skip=(0,), ofills=((0, 0, src, 1),)),
                       0x50: _stub(c, 1), 0x68: _stub(c, 1), 0x18: _stub(c, 2)})
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=c.rng.randint(0, 0x7fffffff))})
    c.emu.w32(rm + 0x44, r32(c))
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x40)
    return [t, ld]


S(0x5eb530, 'ZFFActorActionCloseCombat::Load', 'thiscall', gen=g)
