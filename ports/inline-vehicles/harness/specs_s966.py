"""specs_s966.py - residue-05, batch 966: CActionController::Init (0x4a1190). The render manager's slots 0x138, 0x4c and 0x114
are stubs (0x114 answers the id by name, through a machine-code stub); the object X from 0x138 has a stub slot 0x60."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
from pilot import S
from vh import _stub, obj, r32


def g(c):
    id1 = c.rng.randint(1, 0xffff)
    id2 = c.rng.randint(1, 0xffff)
    code = b'\x8b\x44\x24\x04'
    code += b'\x3d' + struct.pack('<I', 0x68f774)
    code += b'\x74\x07'
    code += b'\xb8' + struct.pack('<I', id2)
    code += b'\xeb\x05'
    code += b'\xb8' + struct.pack('<I', id1)
    code += b'\xc2\x10\x00'
    idstub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(idstub, code)
    x = obj(c, 0x40, {0x60: _stub(c, 2)})
    rm = obj(c, 0x100, {0x138: _stub(c, 0, ret=x), 0x4c: _stub(c, 2, ret=r32(c)), 0x114: idstub})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x900)
    return [t]


S(0x4a1190, 'CActionController::Init', 'thiscall', gen=g)
