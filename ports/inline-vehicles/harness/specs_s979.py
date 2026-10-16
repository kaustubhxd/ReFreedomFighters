"""specs_s979.py - residue-05, batch 979: ZItemStateProjectile::GetUseGeom (0x468b10). The item's slots 0x1e0, 0x1d8, 0x2e8, 0x328
are stubs; slot 0x1d8 writes either the inline-buffer pointer (no free) or zero into its first argument (the local's destructor
then frees through 0x634273, a counting stub). The debug channel's cdecl slot 0x30 is a counting stub (three logged arguments);
the object H from slot 0x328 answers slot 0x334 with zero or a value. Random inputs hit all three paths."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    ss.patch(c, 0x634273, cstub(c, 2))
    g1 = obj(c, 0x40)
    free_case = c.rng.random() < 0.5
    code = b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]   (local pointer)
    if free_case:
        code += b'\xc7\x00\x00\x00\x00\x00'                     # mov dword [eax],0 (not the inline buffer)
    else:
        code += b'\x8d\x50\x04'                                 # lea edx,[eax+4]
        code += b'\x89\x10'                                     # mov [eax],edx     (inline buffer)
    code += b'\xb8' + struct.pack('<I', g1)                     # mov eax,g1
    code += b'\xc2\x08\x00'                                     # ret 8
    st1d8 = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st1d8, code)
    g2 = obj(c, 0x40)
    c.emu.w32(g2 + 4, r32(c) if c.rng.random() < 0.6 else 0)
    h = obj(c, 0x40, {0x334: _stub(c, 0, ret=(r32(c) if c.rng.random() < 0.5 else 0))})
    c.emu.w32(h + 4, r32(c) if c.rng.random() < 0.6 else 0)
    it = obj(c, 0x200, {0x1e0: _stub(c, 1, ret=c.rng.randint(0, 1)),
                        0x1d8: st1d8,
                        0x2e8: _stub(c, 0, ret=g2),
                        0x328: _stub(c, 0, ret=(h if c.rng.random() < 0.6 else 0))})
    ch = obj(c, 0x40, {0x30: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    return [obj(c, 0x40), it]


S(0x468b10, 'ZItemStateProjectile::GetUseGeom', 'thiscall', ret='eax', gen=g)
