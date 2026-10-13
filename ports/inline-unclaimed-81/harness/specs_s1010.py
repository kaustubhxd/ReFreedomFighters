"""specs_s1010.py - area 81 (residue 11 remainder), batch 1010: ZHeli::Load (0x51c7b0). The gate 0x5135c0 returns 1 in most cases and 0 otherwise (a
counting stub); the helpers 0x5270f0, 0x5274a0, 0x516d10 and 0x513510 are counting stubs. The load object's slot 0x40 is a machine-code stub that writes
the next value of a table into its pointer argument (so the loop reads differ from one another); slots 0x18, 0x48, 0x50 and 0x6c are counting stubs.
The render manager (sys+0x9b) slot 0x58 returns a random word. The table holds 64 values, more than the 23 reads a case makes."""
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
    ss.patch(c, 0x5135c0, ss.rec(c, 1, ret=1 if rnd.random() < 0.85 else 0))
    for a in (0x5270f0, 0x5274a0, 0x516d10, 0x513510):
        ss.patch(c, a, ss.rec(c, 1))
    tbl = c.emu.alloc(4 * 64, 4)
    for i in range(64):
        c.emu.w32(tbl + 4 * i, r32(c))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = (b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]
            + b'\x8b\x15' + struct.pack('<I', cnt)               # mov edx,[cnt]
            + b'\x8b\x0c\x95' + struct.pack('<I', tbl)           # mov ecx,[tbl+edx*4]
            + b'\x89\x08'                                        # mov [eax],ecx
            + b'\xff\x05' + struct.pack('<I', cnt)               # inc dword [cnt]
            + b'\x31\xc0'                                        # xor eax,eax
            + b'\xc2\x04\x00')                                   # ret 4
    getter = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(getter, code)
    lg = obj(c, 0x40, {0x18: _stub(c, 2), 0x40: getter, 0x48: _stub(c, 1), 0x50: _stub(c, 1), 0x6c: _stub(c, 1)})
    self_ = obj(c, 0x800)
    rm = obj(c, 0x40, {0x58: _stub(c, 1, ret=r32(c))})
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm)
    return [self_, lg]


S(0x51c7b0, 'ZHeli::Load', 'thiscall', None, ret='eax', gen=g)
