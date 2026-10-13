"""specs_s1032.py - area 81, batch 1032: 0x512fa0 (thiscall, no arguments). The object at this+0x12b has slot 0x14 (counting), slot 0x4c (writes a random word into its
out pointer, skipped in the log), and slot 0x64 (returns the next record from a table of three to four records, then zeros; the out pointer is skipped in the log).
Each record is 8 bytes: a random dword at +0 and a float at +4 that is randomly above or below the tick (sys+0x40, random in 0..20000), so both the
writing exit and the null exit run. The table is zero after the records."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def g(c):
    rnd = c.rng
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, rnd.randint(0, 20000))
    nrec = rnd.randint(1, 4)
    tbl = c.emu.alloc(4 * 16, 4)
    for i in range(16):
        c.emu.w32(tbl + 4 * i, 0)
    for i in range(nrec):
        rec = c.emu.alloc(16, 4)
        c.emu.w32(rec, r32(c))
        c.emu.w32(rec + 4, rf(c, -20, 40))
        c.emu.w32(tbl + 4 * i, rec)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = (b'\x8b\x15' + struct.pack('<I', cnt)            # mov edx,[cnt]
            + b'\x8b\x04\x95' + struct.pack('<I', tbl)      # mov eax,[tbl+edx*4]
            + b'\xff\x05' + struct.pack('<I', cnt)          # inc dword [cnt]
            + b'\xc2\x04\x00')                              # ret 4
    getter = c.emu.alloc(64, 16)
    c.emu.wbytes(getter, code)
    fsrc = c.emu.alloc(4, 4)
    c.emu.w32(fsrc, r32(c))
    o = obj(c, 0x40, {0x14: _stub(c, 0), 0x4c: _stub(c, 1, skip=(0,), ofills=((0, 0, fsrc, 1),)), 0x64: getter})
    self_ = obj(c, 0x200)
    c.emu.w32(self_ + 0x12b, o)
    return [self_]


S(0x512fa0, 'GUESS 0x512fa0 record loop', 'thiscall', None, ret='eax', gen=g)
