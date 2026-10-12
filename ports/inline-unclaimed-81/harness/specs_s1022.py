"""specs_s1022.py - area 81, batch 1022: ZFFActorActionThrow::Update (0x5eb8c0). The sqrt at 0x634d7c is hooked by a sqrtsd stub (exe side). The fastcall
helper 0x43e920 writes a random vector to its ecx. 0x451890, 0x4e0d00 and 0x43e8e0 are counting stubs; 0x44c840 returns a random float (fld from memory).
this's slot 4 returns the kind (0x12 or 0x13; the second read gives the same kind); m (this+8) has slot 0x84 (writes a random vector into its stack
argument), 0x508 and 0x50c (return x), 0x55c (returns r or null). x's slots 0x32c, 0x2d0 and 0x35c count; r's slot 0x320 counts. The gate tick and
this+0x10 are random so both the early return and the full body run."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def fast_vec_stub(c, src):
    code = b''
    for j in range(3):
        code += b'\x8b\x05' + struct.pack('<I', src + 4 * j) + b'\x89\x41' + bytes([4 * j])
    code += b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def float_stub(c, addr):
    code = b'\xd9\x05' + struct.pack('<I', addr) + b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def fill(c, vals):
    a = c.emu.alloc(4 * len(vals), 4)
    for i, v in enumerate(vals):
        c.emu.w32(a + 4 * i, v)
    return a


def g(c):
    rnd = c.rng
    sq = c.emu.alloc(16, 16)
    c.emu.wbytes(sq, b'\xf2\x0f\x51\xc0\xc3')
    ss.patch(c, 0x634d7c, sq)
    ss.patch(c, 0x43e920, fast_vec_stub(c, fill(c, [rf(c, -3, 3) for _ in range(3)])))
    ss.patch(c, 0x451890, ss.rec(c, 1))
    ss.patch(c, 0x4e0d00, ss.rec(c, 1))
    ss.patch(c, 0x43e8e0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x44c840, float_stub(c, fill(c, [rf(c, -2000, 2000)])))
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, rnd.randint(0, 3000))
    x = obj(c, 0x200, {0x32c: _stub(c, 1), 0x2d0: _stub(c, 2), 0x35c: _stub(c, 0)})
    r = obj(c, 0x40, {0x320: _stub(c, 0)})
    m = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), ofills=((0, 0, fill(c, [rf(c, -3, 3) for _ in range(3)]), 3),)),
                      0x508: _stub(c, 0, ret=x),
                      0x50c: _stub(c, 0, ret=x),
                      0x55c: _stub(c, 1, ret=r if rnd.random() < 0.7 else 0)})
    kind = rnd.choice([0x12, 0x13])
    self_ = obj(c, 0x400, {0x4: _stub(c, 0, ret=kind)})
    c.emu.w32(self_ + 0x8, m)
    c.emu.w32(self_ + 0x10, rf(c, -3, 3))
    c.emu.wbytes(self_ + 0x14, bytes([1 if rnd.random() < 0.15 else 0]))
    return [self_]


S(0x5eb8c0, 'ZFFActorActionThrow::Update', 'thiscall', gen=g)
