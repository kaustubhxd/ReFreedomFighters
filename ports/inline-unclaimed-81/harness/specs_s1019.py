"""specs_s1019.py - area 81, batch 1019: GUESS FUN_4a0ea0 (0x4a0ea0). The helpers 0x43e960, 0x441940 and 0x4e0870 are machine-code stand-ins that copy their
vector arguments into heap records (so the clamps are compared through the heap). The object at this+0x44 (M) has slots 0x84 and 0x8c (one stack argument each,
skipped in the log: they are stack addresses), and +8 is a vector source object. The argument X has slots 0x84 and 0x8c (counting), 0x128 (three arguments;
writes a random value 0..2 into its second argument), and +8 is a vector object. The self word at +0x48 is 6, 8 or random; the bit test byte at +0x5a is
random in most cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def vec_record_stub(c, rec, also_edx=None):
    code = (b'\x8b\x01' + b'\xa3' + struct.pack('<I', rec)
            + b'\x8b\x41\x04' + b'\xa3' + struct.pack('<I', rec + 4)
            + b'\x8b\x41\x08' + b'\xa3' + struct.pack('<I', rec + 8))
    if also_edx is not None:
        code += (b'\x8b\x02' + b'\xa3' + struct.pack('<I', also_edx)
                 + b'\x8b\x42\x04' + b'\xa3' + struct.pack('<I', also_edx + 4)
                 + b'\x8b\x42\x08' + b'\xa3' + struct.pack('<I', also_edx + 8))
    code += b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def vec_obj(c):
    o = obj(c, 0x80)
    for off in (0x30, 0x34, 0x38, 0x40, 0x44, 0x48):
        c.emu.w32(o + off, rf(c, -3, 3))
    return o


def g(c):
    rnd = c.rng
    recA = c.emu.alloc(12, 4)
    recB = c.emu.alloc(12, 4)
    recE = c.emu.alloc(24, 4)
    ss.patch(c, 0x43e960, vec_record_stub(c, recA))
    ss.patch(c, 0x441940, vec_record_stub(c, recB))
    # the real 0x4e0870 returns a length in st0 (fld) that the caller never pops here: record the vector arguments, then leave a float on the x87 stack
    flx = c.emu.alloc(4, 4)
    c.emu.w32(flx, rf(c, -100, 100))
    rec_code = vec_record_stub(c, recE, also_edx=recE + 12)
    body = c.emu.rbytes(rec_code, 64)
    assert body[46] == 0xc3, body[40:50]   # ecx stores 7+8+8 bytes, edx stores 7+8+8 bytes: 46 bytes then ret
    body = body[:46]
    comb = c.emu.alloc(96, 16)
    c.emu.wbytes(comb, body + b'\xd9\x05' + struct.pack('<I', flx) + b'\xc3')
    ss.patch(c, 0x4e0870, comb)
    srcL = c.emu.alloc(4, 4)
    c.emu.w32(srcL, rnd.randint(0, 2))
    Z = vec_obj(c)
    M = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,)), 0x8c: _stub(c, 1, skip=(0,))})
    c.emu.w32(M + 8, Z)
    XZ = vec_obj(c)
    X = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,)), 0x8c: _stub(c, 1, skip=(0,)),
                      0x128: _stub(c, 3, skip=(1,), ofills=((1, 0, srcL, 1),), ret=r32(c))})
    c.emu.w32(X + 8, XZ)
    self_ = obj(c, 0x200)
    c.emu.w32(self_ + 0x44, M)
    c.emu.w32(self_ + 0x48, rnd.choice([6, 8, 6, rnd.randint(0, 9)]))
    c.emu.wbytes(self_ + 0x5a, bytes([rnd.randint(0, 255) if rnd.random() < 0.3 else rnd.choice([0, 2, 8, 16])]))
    c.emu.w32(self_ + 0x56, rnd.randint(-2000, 2000) & 0xffffffff)
    return [self_, X]


S(0x4a0ea0, 'GUESS FUN_4a0ea0', 'thiscall', None, ret='al', gen=g)
