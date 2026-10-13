"""specs_s1018.py - area 81, batch 1018: ZProjectile::CheckHit (0x4b9340), asm-style port. The argument t is random (0 or negative in some cases, so the early
path runs). The helpers 0x443ef0 and 0x43e920 write deterministic vectors (machine code, stand-ins); 0x4dc630 is a counting stub. The object at this+0x44
has slot 0x20 (returns W, whose slot 0x84 writes nothing; its stack argument is skipped) and its +8 object Z holds random floats. The render manager's
slot 0x58 returns a random object r (or null) whose +8 pointer is a Y object; the render manager's +0xadc object has slot 0x2e0 (six arguments) returning
a bool. The register state is compared by the checker (esi, edi, ebx, ebp)."""
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


def fill(c, vals):
    a = c.emu.alloc(4 * len(vals), 4)
    for i, v in enumerate(vals):
        c.emu.w32(a + 4 * i, v)
    return a


def g(c):
    rnd = c.rng
    ss.patch(c, 0x443ef0, fast_vec_stub(c, fill(c, [rf(c, -2, 2) for _ in range(3)])))
    ss.patch(c, 0x43e920, fast_vec_stub(c, fill(c, [rf(c, -2, 2) for _ in range(3)])))
    ss.patch(c, 0x4dc630, ss.rec(c, 2))
    Z = obj(c, 0x80)
    for off in (0x18, 0x24, 0x28, 0x2c):
        c.emu.w32(Z + off, rf(c, -3, 3))
    W = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,))})
    M = obj(c, 0x40, {0x20: _stub(c, 0, ret=W)})
    c.emu.w32(M + 8, Z)
    Y = obj(c, 0x40)
    c.emu.w32(Y + 0x3c, r32(c))
    r = obj(c, 0x40)
    c.emu.w32(r + 8, Y)
    R2 = obj(c, 0x40, {0x2e0: _stub(c, 6, ret=rnd.choice([0, 1]))})
    rm = obj(c, 0x1000, {0x58: _stub(c, 1, ret=r if rnd.random() < 0.7 else 0)})
    c.emu.w32(rm + 0xadc, R2)
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm)
    P = obj(c, 0x80)
    self_ = obj(c, 0x200)
    c.emu.w32(self_ + 0x44, M)
    c.emu.w32(self_ + 0x8d, P)
    c.emu.w32(self_ + 0x65, r32(c) if rnd.random() < 0.8 else 0)
    t = rf(c, -2, 2) if rnd.random() < 0.85 else 0
    return [self_, t]


S(0x4b9340, 'ZProjectile::CheckHit', 'thiscall', gen=g)
