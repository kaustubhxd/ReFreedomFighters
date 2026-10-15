"""specs_s971.py - residue-04, batch 971: CMAINCAMERACONTROL::SetDefaultFog (0x4fdac0). The render manager's slot 0x138 returns
a stub object whose slot 0x84 writes a float by name (machine-code stub: 0x6954e8 gets V1, anything else gets V2). V1 and V2 are
zero or random, so both branches (defaults and stored values) are reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
from pilot import S
from vh import _stub, obj, r32, rf


def g(c):
    v1 = 0 if c.rng.random() < 0.5 else rf(c, -2, 2)
    v2 = 0 if c.rng.random() < 0.5 else rf(c, -2, 2)
    code = b'\x8b\x44\x24\x04'                               # mov eax,[esp+4]   (name)
    code += b'\x8b\x54\x24\x08'                              # mov edx,[esp+8]   (out pointer)
    code += b'\x3d' + struct.pack('<I', 0x6954e8)            # cmp eax,0x6954e8
    code += b'\x75\x09'                                      # jne +9
    code += b'\xc7\x02' + struct.pack('<I', v1) + b'\xc2\x08\x00'   # mov [edx],V1; ret 8
    code += b'\xc7\x02' + struct.pack('<I', v2) + b'\xc2\x08\x00'   # mov [edx],V2; ret 8
    st84 = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st84, code)
    x = obj(c, 0x40, {0x84: st84})
    rm = obj(c, 0x100, {0x138: _stub(c, 0, ret=x)})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    sub = obj(c, 0x100)
    t = obj(c, 0x80)
    c.emu.w32(t + 0x44, sub)
    return [t]


S(0x4fdac0, 'CMAINCAMERACONTROL::SetDefaultFog', 'thiscall', gen=g)
