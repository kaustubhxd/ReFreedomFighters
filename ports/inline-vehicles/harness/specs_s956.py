"""specs_s956.py - residue-03, batch 956: ZFFMortar::Command (0x5dd1b0). The render manager's slot 0x114 is a machine-code
stub answering id1 for name 0x6b6da0 and id2 otherwise (4 pushed args, ret 0x10); slot 0x58 answers the object whose slot 0xbc
is a stub. The command word and value are picked to hit the id1 and id2 branches and the matches."""
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
    code = b'\x8b\x44\x24\x04'                             # mov eax,[esp+4]  (name)
    code += b'\x3d' + struct.pack('<I', 0x6b6da0)          # cmp eax,0x6b6da0
    code += b'\x74\x07'                                    # je +7
    code += b'\xb8' + struct.pack('<I', id2)               # mov eax,id2
    code += b'\xeb\x05'                                    # jmp +5
    code += b'\xb8' + struct.pack('<I', id1)               # mov eax,id1
    code += b'\xc2\x10\x00'                                # ret 16
    idstub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(idstub, code)
    x = obj(c, 0x40, {0xbc: _stub(c, 1)})
    rm = obj(c, 0x100, {0x114: idstub, 0x58: _stub(c, 1, ret=x)})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x80)
    vals = [r32(c) for _ in range(6)]
    for k, off in enumerate((0x49, 0x4d, 0x51, 0x55, 0x59, 0x5d)):
        c.emu.w32(t + off, vals[k])
    v = vals[c.rng.randint(0, 5)] if c.rng.random() < 0.7 else r32(c)
    cmd = [id1, id2, c.rng.randint(0, 0xffff)][c.rng.randint(0, 2)]
    return [t, cmd, v]


S(0x5dd1b0, 'ZFFMortar::Command', 'thiscall', gen=g)
