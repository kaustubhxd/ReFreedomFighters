"""specs_s3527.py - area 35 claim 27 (docs/20-unclaimed-35.md): 0x44aed0 (residue name, medium). Float return (st0).

GUESS recording stubs (same design as batch 26): call counts, the three dwords behind each pointer argument, and per-case
GUESS output written through pointer arguments. 0x460af0 (thiscall, A/P pointers and a float), 0x460aa0 (thiscall, pointer and
float), 0x4e0870 (fastcall, A and the S10 pointer, float return, per-case). 0x633654 is a no-op (the cookie check). The sqrt
thunk 0x634d7c is the harness's own sqrt handler (not stubbed)."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S, F   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c, lo, hi):
    return struct.pack('<f', c.rng.uniform(lo, hi))


def _stub(c, regs, stack, cleanup, ret_eax=0, ret_float=None):
    """GUESS recording stub (see specs_s3526): regs [(reg, kind)], stack [kind]; 'p' = pointer (logs and writes 3 dwords)."""
    nslots = 1 + sum(3 if k == 'p' else 1 for _, k in regs) + sum(3 if k == 'p' else 1 for k in stack)
    cells = c.emu.alloc(4 * nslots, 4)
    c.emu.wbytes(cells, bytes(4 * nslots))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\xff\x05' + ss.P(cnt)
    code += b'\xa1' + ss.P(cnt) + b'\xa3' + ss.P(cells)
    pos = 1

    def dw():
        return struct.pack('<I', c.rng.getrandbits(32) if c.rng.random() < 0.85 else 0)
    for reg, kind in regs:
        base = b'\x8b\x01' if reg == 'ecx' else b'\x8b\x02'
        if kind == 'p':
            for j in (0, 4, 8):
                ld = base if j == 0 else (b'\x8b\x41' + bytes([j]) if reg == 'ecx' else b'\x8b\x42' + bytes([j]))
                code += ld + b'\xa3' + ss.P(cells + 4 * pos)
                pos += 1
            for j in (0, 4, 8):
                code += (b'\xc7\x41' if reg == 'ecx' else b'\xc7\x42') + bytes([j]) + dw()
        else:
            code += (b'\x89\xc8' if reg == 'ecx' else b'\x89\xd0') + b'\xa3' + ss.P(cells + 4 * pos)
            pos += 1
    for k, kind in enumerate(stack):
        d = 4 + 4 * k
        if kind == 'p':
            code += b'\x8b\x54\x24' + bytes([d])
            for j in (0, 4, 8):
                code += b'\x8b\x42' + bytes([j]) + b'\xa3' + ss.P(cells + 4 * pos)
                pos += 1
            for j in (0, 4, 8):
                code += b'\xc7\x42' + bytes([j]) + dw()
        else:
            code += b'\x8b\x44\x24' + bytes([d]) + b'\xa3' + ss.P(cells + 4 * pos)
            pos += 1
    if ret_float is not None:
        rf = c.emu.alloc(4, 4)
        c.emu.wbytes(rf, struct.pack('<f', ret_float))
        code += b'\xd9\x05' + ss.P(rf)
    else:
        code += b'\xb8' + ss.P(ret_eax)
    code += (b'\xc2' + struct.pack('<H', cleanup)) if cleanup else b'\xc3'
    return ss.code(c, code)


def _disp(c):
    self_obj = _rnd(c, 0x200)
    A = _rnd(c, 0x100)
    P = _rnd(c, 0x100)
    V = _rnd(c, 0x100)
    for base in (A, P, V):
        for j in (0, 4, 8):
            c.emu.wbytes(base + j, _fl(c, -2.0, 2.0))
    f2 = struct.unpack('<f', _fl(c, -2.0, 3.0))[0]
    if c.rng.random() < 0.4:
        # Make t = f2 - S0 exactly 1.0 (float32), with S0 chosen by the sign of dot = (P.y V.y + V.x P.x) + P.z V.z.
        f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
        px, py, pz = [struct.unpack('<f', c.emu.rbytes(P + j, 4))[0] for j in (0, 4, 8)]
        vx, vy, vz = [struct.unpack('<f', c.emu.rbytes(V + j, 4))[0] for j in (0, 4, 8)]
        dot = f32(f32(f32(py * vy) + f32(vx * px)) + f32(pz * vz))
        s0 = 0.0010000000474974513 if dot <= 0.0 else -0.0010000000474974513
        f2 = f32(1.0 + f32(s0))
    r_per = struct.unpack('<f', _fl(c, -2.0, 4.0))[0]
    ss.patch(c, 0x460af0, _stub(c, [('ecx', 'v')], ['p', 'v', 'v'], 12))   # P is read again later: not overwritten
    ss.patch(c, 0x460aa0, _stub(c, [('ecx', 'v')], ['p', 'v'], 8))
    ss.patch(c, 0x4e0870, _stub(c, [('ecx', 'p'), ('edx', 'p')], [], 0, ret_float=r_per))
    ss.patch(c, 0x633654, ss.code(c, b'\xc3'))
    return [self_obj, A, P, F(f2), V]


S(0x44aed0, 'ZSHAPE::GetSplinePosVelocity (residue name) thiscall', 'thiscall', None, ret='st0', gen=_disp,
  note='area 35 claim 27; helpers GUESS-recording stubs; sqrt is the harness handler; SEH/cookie not modelled')
