"""specs_s1008.py - area 81 (residue 0), batch 1008: CEntityTracker::FrameUpdate (0x5bfe00). The helpers 0x43e920 (fastcall, copies a random vector to
ecx) and 0x44c840 (returns a random float through the x87 stack) are machine-code stand-ins; 0x591ae0 returns the object G and 0x646040 returns a
random bool (counting stubs). The entries are objects with a 0x438 bool slot, a 0x24c slot that returns q, and 0x110, 0x114 and 0x694 counting slots.
The sys tick and the entries' +0x11 floats are random so both the activation and the deactivation paths run."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def fill(c, vals):
    a = c.emu.alloc(4 * len(vals), 4)
    for i, v in enumerate(vals):
        c.emu.w32(a + 4 * i, v)
    return a


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


def g(c):
    rnd = c.rng
    f34 = fill(c, [rf(c, -3, 3) for _ in range(3)])
    g44 = obj(c, 0x40, {0x80: _stub(c, 2, skip=(0, 1), ofills=((0, 0, f34, 3),))})
    G = obj(c, 0x100)
    c.emu.w32(G + 0x44, g44)
    ss.patch(c, 0x591ae0, ss.rec(c, 0, ret=G))
    ss.patch(c, 0x43e920, fast_vec_stub(c, fill(c, [rf(c, -1, 1) for _ in range(3)])))
    ss.patch(c, 0x44c840, float_stub(c, fill(c, [rf(c, -1000, 20000)])))
    ss.patch(c, 0x646040, ss.rec(c, 0, ret=rnd.choice([0, 1])))
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, rnd.randint(0, 8000))
    n = rnd.randint(0, 3)
    base = c.emu.alloc(0x17 * 4 + 16, 4)
    for i in range(n):
        q = obj(c, 0x40)
        o = obj(c, 0x100, {0x438: _stub(c, 0, ret=rnd.choice([0, 1])), 0x24c: _stub(c, 0, ret=q),
                           0x110: _stub(c, 2), 0x114: _stub(c, 1), 0x694: _stub(c, 1)})
        c.emu.wbytes(o + 0x917, bytes([1 if rnd.random() < 0.7 else 0]))
        p = obj(c, 0x40)
        c.emu.w32(p + 0x3c, (r32(c) | 0x1000) if rnd.random() < 0.5 else (r32(c) & ~0x1000 & 0xffffffff))
        c.emu.w32(o + 8, p)
        r = obj(c, 0x40)
        c.emu.w32(r + 4, 2 if rnd.random() < 0.4 else rnd.choice([1, 3, 5]))
        c.emu.w32(r + 8, 4 if rnd.random() < 0.25 else rnd.choice([1, 2, 3]))
        c.emu.w32(o + 0x54, r)
        ent = base + 0x17 * i
        c.emu.w32(ent, o)
        c.emu.wbytes(ent + 0x10, bytes([1 if rnd.random() < 0.4 else 0]))
        c.emu.w32(ent + 0x11, rf(c, -2, 2))
    self_ = obj(c, 0x100, {0x98: _stub(c, 1), 0x44: 0})
    obj44 = obj(c, 0x40, {0x130: _stub(c, 3)})
    c.emu.w32(self_ + 0x44, obj44)
    c.emu.wbytes(self_ + 0x48, bytes([rnd.randint(0, 255), rnd.randint(0, 255)]))
    c.emu.wbytes(self_ + 0x4a, bytes([rnd.randint(0, 255), rnd.randint(0, 255)]))
    c.emu.w32(self_ + 0x54, n)
    c.emu.w32(self_ + 0x58, rnd.randint(0, 4))
    c.emu.w32(self_ + 0x5c, rnd.randint(0, 3))
    c.emu.w32(self_ + 0x50, base)
    c.emu.w32(self_ + 0x64, obj(c, 0x40) if rnd.random() < 0.8 else 0)
    c.emu.wbytes(self_ + 0x68, bytes([1 if rnd.random() < 0.8 else 0]))
    return [self_]


S(0x5bfe00, 'CEntityTracker::FrameUpdate', 'thiscall', gen=g)
