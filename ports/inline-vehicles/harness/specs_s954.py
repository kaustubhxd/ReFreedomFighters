"""specs_s954.py - residue-03, batch 954: ZDamageBox::Save (0x5db4f0). The child object at +0x84 is a vtable stub set:
slot 0x14 returns a random value, slot 0x4c is a no-op, slot 0x5c is a small machine-code stub that writes loc = 1 for the
first K calls and 0 after (K = 0..3 per case), returning one entry object. The save object's slots are counting stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, obj


def g(c):
    k = c.rng.randint(0, 3)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    entry = obj(c, 0x40)
    code = b'\x8b\x44\x24\x04'                       # mov eax,[esp+4]   (loc pointer)
    code += b'\x8b\x15' + struct.pack('<I', cnt)     # mov edx,[cnt]
    code += b'\xff\x05' + struct.pack('<I', cnt)     # inc dword [cnt]
    code += b'\x31\xc9'                              # xor ecx,ecx
    code += b'\x83\xfa' + bytes([k])                 # cmp edx,K
    code += b'\x7d\x02'                              # jge +2
    code += b'\xb1\x01'                              # mov cl,1
    code += b'\x89\x08'                              # mov [eax],ecx
    code += b'\xb8' + struct.pack('<I', entry)       # mov eax,entry
    code += b'\xc2\x04\x00'                          # ret 4
    stub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(stub, code)
    child = obj(c, 0x80, {0x14: _stub(c, 0, ret=c.rng.randint(0, 0x7fffffff)), 0x4c: _stub(c, 1, skip=(0,)), 0x5c: stub})
    sg = ss.save_obj(c, {0x3c: ss.rec(c, 1), 0x4c: ss.rec(c, 1), 0x64: ss.rec(c, 1)})
    this = obj(c, 0x100)
    c.emu.w32(this + 0x84, child)
    return [this, sg]


S(0x5db4f0, 'ZDamageBox::Save', 'thiscall', ret='al', gen=g)
