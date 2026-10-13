"""specs_s3526.py - area 35 claim 26 (docs/20-unclaimed-35.md): 0x47e5e0 (GUESS name), float return (st0).

GUESS recording stubs. Each stub logs its register and stack arguments; 'p' arguments are pointers into the caller's frame
(stack addresses), so the stub logs the pointed-to value, never the address. 'v' arguments are logged as values. 0x634d7c is an IAT thunk to
_libm_sse2_sqrt_precise (harness handler, not stubbed here). 0x634dc4 is an IAT thunk to _CIfmod, which has no harness
handler: it is replaced by a stub at the thunk address that computes x87 fmod with fprem (st1 mod st0, result in st0, one pop).
The object's vtable (fake, slots +0x57c, +0x578, +0x588, +0x254, +0x620, +0x62c, +0x5f8) uses the same stub kinds."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, regs, stack, cleanup, ret_eax=0, ret_float=None):
    """GUESS recording stub. regs: [(reg, kind)] for ecx/edx; stack: [kind] for stack args. kind 'p' = pointer: logs the
    three dwords behind it, then writes three per-case dwords there (the GUESS output); 'v' = value, logged once.
    Log layout: cells[0] = call count (so extra or missing calls show), then the arguments in order."""
    nslots = 1 + sum(3 if k == 'p' else 1 for _, k in regs) + sum(3 if k == 'p' else 1 for k in stack)
    cells = c.emu.alloc(4 * nslots, 4)
    c.emu.wbytes(cells, bytes(4 * nslots))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\xff\x05' + ss.P(cnt)                                # inc dword [cnt]
    code += b'\xa1' + ss.P(cnt) + b'\xa3' + ss.P(cells)           # mov eax, [cnt]; mov [cells], eax
    pos = 1
    def dw():
        return struct.pack('<I', c.rng.getrandbits(32) if c.rng.random() < 0.85 else 0)
    for reg, kind in regs:
        base = b'\x8b\x01' if reg == 'ecx' else b'\x8b\x02'     # mov eax, [ecx] / [edx]
        if kind == 'p':
            for j in (0, 4, 8):
                ld = base if j == 0 else (b'\x8b\x41' + bytes([j]) if reg == 'ecx' else b'\x8b\x42' + bytes([j]))
                code += ld + b'\xa3' + ss.P(cells + 4 * pos)
                pos += 1
            for j in (0, 4, 8):                                       # GUESS output into the pointed buffer
                code += (b'\xc7\x41' if reg == 'ecx' else b'\xc7\x42') + bytes([j]) + dw()
        else:
            code += (b'\x89\xc8' if reg == 'ecx' else b'\x89\xd0') + b'\xa3' + ss.P(cells + 4 * pos)
            pos += 1
    for k, kind in enumerate(stack):
        d = 4 + 4 * k
        if kind == 'p':
            code += b'\x8b\x54\x24' + bytes([d])                  # mov edx, [esp + d]
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
        code += b'\xd9\x05' + ss.P(rf)                             # fld dword [rf]
    else:
        code += b'\xb8' + ss.P(ret_eax)                             # mov eax, ret_eax
    code += (b'\xc2' + struct.pack('<H', cleanup)) if cleanup else b'\xc3'
    return ss.code(c, code)


def _fbits(c, lo=-3.0, hi=3.0):
    return struct.unpack('<f', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _disp(c):
    self_obj = _rnd(c, 0x800)
    for off in (0x726, 0x754, 0x703, 0x705, 0x699):
        c.emu.wbytes(self_obj + off, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(self_obj + 0x64c, c.rng.choice([0xa, 0xb, 0xa, 0xb, 3, 7]))
    c.emu.w32(self_obj + 0x6ce, c.rng.getrandbits(32))
    fl = [0x48, 0x4c, 0x50, 0x67c, 0x684, 0x660, 0x664, 0x668, 0x69a, 0x69e, 0x6a2, 0x6da, 0x6de, 0x6e2, 0x6e6,
          0x6ea, 0x6ee, 0x6f2, 0x6f6, 0x6fa, 0x70e, 0x706, 0x70a, 0x644, 0x75d, 0x688, 0x755, 0x24]
    for off in fl:
        c.emu.wbytes(self_obj + off, struct.pack('<f', c.rng.uniform(-4.0, 4.0)))
    c.emu.wbytes(self_obj + 0x759, struct.pack('<f', c.rng.uniform(1.0, 4.0)))   # divisor: nonzero
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    c.emu.w32(mgr + 0x40, c.rng.randrange(-200000, 200000) & 0xffffffff)
    r254 = c.rng.choice([0, 1])
    r588 = c.rng.choice([0, 1])
    f47f = _fbits(c)
    vt = c.emu.fake_vtable('ZFFDisp47e', 0x640, {
        0x57c: _stub(c, [], ['p', 'p'], 8),
        0x578: _stub(c, [], ['p', 'p'], 8),
        0x588: _stub(c, [], [], 0, ret_eax=r588),
        0x254: _stub(c, [], [], 0, ret_eax=r254),
        0x620: _stub(c, [], ['p', 'v', 'v'], 12),
        0x62c: _stub(c, [], ['v'], 4),
        0x5f8: _stub(c, [], [], 0),
    })
    c.emu.w32(self_obj, vt)
    ss.patch(c, 0x47f490, _stub(c, [('ecx', 'v')], ['p', 'p', 'v'], 12, ret_float=f47f))
    ss.patch(c, 0x4e09e0, _stub(c, [('ecx', 'p'), ('edx', 'p')], [], 0))
    ss.patch(c, 0x441940, _stub(c, [('ecx', 'p'), ('edx', 'p')], [], 0))
    ss.patch(c, 0x4419f0, _stub(c, [('ecx', 'p'), ('edx', 'p')], [], 0))
    ss.patch(c, 0x4de480, _stub(c, [('ecx', 'p'), ('edx', 'p')], [], 0))
    ss.patch(c, 0x4de040, _stub(c, [('ecx', 'p'), ('edx', 'p')], ['v'], 4))
    ss.patch(c, 0x4e09b0, _stub(c, [('ecx', 'p')], [], 0))
    ss.patch(c, 0x47aad0, _stub(c, [('ecx', 'v')], ['v', 'v'], 8))
    ss.patch(c, 0x477740, _stub(c, [('ecx', 'v')], ['v', 'v'], 8))
    ss.patch(c, 0x47c690, _stub(c, [('ecx', 'v')], ['v'], 4))
    ss.patch(c, 0x47ce80, _stub(c, [('ecx', 'v')], [], 0))
    ss.patch(c, 0x47cdf0, _stub(c, [('ecx', 'v')], ['p', 'v'], 8))
    # _CIfmod thunk (0x634dc4): st0 = divisor, st1 = dividend; fprem loop, then st0 = result with one pop.
    ss.patch(c, 0x634dc4, ss.code(c, b'\xd9\xc9' + b'\xd9\xf8' + b'\xdf\xe0' + b'\xf6\xc4\x04' + b'\x75\xf7' + b'\xdd\xd9' + b'\xc3'))
    return [self_obj]


S(0x47e5e0, 'GUESS 0x47e5e0 thiscall (float return)', 'thiscall', None, ret='st0', gen=_disp,
  note='area 35 claim 26; helpers GUESS-recording stubs; CRT 0x634d7c and 0x634dc4 run as exe code')
