"""specs_s1020.py - area 81, batch 1020: CImpactResponse::Command (0x5dc230). The command word at 0x714388 equals cmd in most cases. The object at this+0x44 (P)
and the objects returned by the global controller Q (0x70038c) get a header dword before them (their -4 word is read). Q's slot 0x20 returns 0 or 1, slot 0xcc
returns R1, R1's slot 0x350 returns R2 (or null); Q+8 is a thiscall counting stub (or null), Q+0xc and Q+0x10 bracket P or R2 (usually in range), slot 0xac
counts. The name at this+0x4c is a random string (up to 100 characters) and the allocator 0x41e290 returns a fixed 256-byte buffer. The walked object W
(this+0x48) has slot 0x4c (one argument; writes a random flag into it), slot 0x5c (writes the next flag, ones then zeros, and returns a pointer). The
render manager's slot 0x114 (five arguments, returns a word; the fifth is a stack address and is skipped) and P's slot 0x12c (two arguments) are counting stubs."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def hobj(c, size, slots=None):
    """An object with a readable dword before it (the exe reads [obj-4])."""
    a = c.emu.alloc(size + 4, 4)
    c.emu.w32(a, r32(c))
    o = a + 4
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    vt = c.emu.alloc(0x800, 4, fill=0)
    for off in range(0, 0x800, 4):
        c.emu.w32(vt + off, 0x0dead000 + off)
    for off, code in (slots or {}).items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def fixed_buf_stub(c, buf):
    code = b'\xb8' + struct.pack('<I', buf) + b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def getter(c, val_list_tbl_cnt):
    tbl, cnt, E = val_list_tbl_cnt
    code = (b'\x8b\x44\x24\x04'
            + b'\x8b\x15' + struct.pack('<I', cnt)
            + b'\x8b\x0c\x95' + struct.pack('<I', tbl)
            + b'\x89\x08'
            + b'\xff\x05' + struct.pack('<I', cnt)
            + b'\xb8' + struct.pack('<I', E)
            + b'\xc2\x04\x00')
    a = c.emu.alloc(64, 16)
    c.emu.wbytes(a, code)
    return a


def g(c):
    rnd = c.rng
    ss.patch(c, 0x41e290, fixed_buf_stub(c, c.emu.alloc(256, 4)))
    c.emu.wbytes(0x714388, struct.pack('<H', rnd.randint(0, 0xffff)))
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    rm = obj(c, 0x40, {0x114: _stub(c, 5, skip=(4,), ret=r32(c))})
    c.emu.w32(sysobj + 0x9b, rm)
    R2 = hobj(c, 0x40) if rnd.random() < 0.8 else 0
    R1 = obj(c, 0x40, {0x350: _stub(c, 0, ret=R2)})
    Q2 = ss.rec(c, 0, ret=r32(c))
    Q = obj(c, 0x100, {0x20: _stub(c, 1, ret=rnd.choice([0, 0, 1])),
                       0xac: _stub(c, 1),
                       0xcc: _stub(c, 1, ret=R1)})
    c.emu.w32(Q + 8, Q2 if rnd.random() < 0.8 else 0)
    c.emu.w32(Q + 0xc, 0 if rnd.random() < 0.9 else rnd.randint(0, 0xffffffff))
    c.emu.w32(Q + 0x10, 0xffffffff if rnd.random() < 0.9 else rnd.randint(0, 0x1000))
    c.emu.w32(0x70038c, Q)
    P = hobj(c, 0x40, {0x12c: _stub(c, 2)})
    ff = c.emu.alloc(4, 4)
    c.emu.w32(ff, rnd.randint(0, 1))
    tbl = c.emu.alloc(4 * 32, 4)
    for i in range(32):
        c.emu.w32(tbl + 4 * i, rnd.randint(0, 1) if i < 16 else 0)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    Rv = hobj(c, 0x40)
    W = obj(c, 0x40, {0x4c: _stub(c, 1, skip=(0,), ofills=((0, 0, ff, 1),)),
                      0x5c: getter(c, (tbl, cnt, Rv))})
    slen = rnd.randint(0, 100)
    S_ = c.emu.alloc(slen + 1, 4)
    c.emu.wbytes(S_, bytes(rnd.randint(65, 90) for _ in range(slen)) + b'\0')
    self_ = obj(c, 0x200)
    c.emu.w32(self_ + 0x44, P)
    c.emu.w32(self_ + 0x48, W)
    c.emu.w32(self_ + 0x4c, S_)
    arg = obj(c, 0x40)
    c.emu.w32(arg + 8, r32(c))
    return [self_, rnd.randint(0, 0xffff) if rnd.random() < 0.15 else (struct.unpack('<H', c.emu.rbytes(0x714388, 2))[0]), arg]


S(0x5dc230, 'CImpactResponse::Command', 'thiscall', None, ret='eax', gen=g)
