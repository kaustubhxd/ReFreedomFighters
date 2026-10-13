"""specs_s3525.py - area 35 claim 25 (docs/20-unclaimed-35.md): 0x4a51e0, the residue-name dispatcher (medium).

Stubbed: 0x4e7d70, 0x4a5da0, 0x4e7ce0, 0x4e7c50, 0x4a5fe0 (thiscall, logged); 0x4e7930 (thiscall, four args, float return; logs
ecx, arg0, arg3 and writes constants through arg1 and arg2, which are stack addresses); 0x4a5f20 (thiscall, one float arg,
float return, logged); 0x4419f0, 0x43e960, 0x4de4f0 (fastcall, logged where the register is a heap address); 0x633654 (no-op).
This object's vtable (logging, +0x64, +0x68 and +0x3c); B = this+0x44 (logging, +0x80, and +0x20 returning C); C (logging,
+0x94). The nine selector words and this+0x5d are chosen from the same set, so every branch is reachable."""
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


def _log_cells(c, n):
    cells = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(cells, bytes(4 * n))
    return cells


def _thiscall_log(c, nargs, ret):
    cells = _log_cells(c, 1 + nargs)
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0]


def _float_cell(c, bits):
    cell = c.emu.alloc(4, 4)
    c.emu.wbytes(cell, struct.pack('<I', bits))
    return cell


def _stub_4e7930(c):
    W1, W2, R = c.rng.getrandbits(32), c.rng.getrandbits(32), _fbits(c)
    cells = _log_cells(c, 3)
    rf = _float_cell(c, R)
    code = (b'\x89\x0d' + ss.P(cells)                              # mov [cells], ecx
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 4)       # arg0 -> cells[1]
            + b'\x8b\x44\x24\x10' + b'\xa3' + ss.P(cells + 8)       # arg3 -> cells[2]
            + b'\x8b\x54\x24\x08' + b'\xc7\x02' + struct.pack('<I', W1)    # *arg1 = W1
            + b'\x8b\x54\x24\x0c' + b'\xc7\x02' + struct.pack('<I', W2)    # *arg2 = W2
            + b'\xd9\x05' + ss.P(rf)                                # fld dword [rf]
            + b'\xc2\x10\x00')                                      # ret 16
    return ss.code(c, code)


def _float_ret_log(c, R):
    cells = _log_cells(c, 2)
    rf = _float_cell(c, R)
    code = (b'\x89\x0d' + ss.P(cells)
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 4)
            + b'\xd9\x05' + ss.P(rf)
            + b'\xc2\x04\x00')
    return ss.code(c, code)


def _fastcall_log(c, reg):
    cells = _log_cells(c, 1)
    op = b'\x89\x0d' if reg == 'ecx' else b'\x89\x15'
    return ss.code(c, op + ss.P(cells) + b'\xc3')


def _ret0(c):
    return ss.code(c, b'\xc3')


SEL = [0x0501, 0x0502, 0x0503, 0x0504, 0x0505, 0x0506, 0x0507, 0x0508, 0x0509]
GLOBAL_SELS = [0x700318, 0x70030c, 0x700310, 0x700308, 0x7002fc, 0x700300, 0x700314, 0x700304, 0x70031c]


def _disp(c):
    self_obj = _rnd(c, 0x200)
    perm = SEL[:]
    c.rng.shuffle(perm)
    for a, v in zip(GLOBAL_SELS, perm):
        c.emu.wbytes(a, struct.pack('<H', v))
    choices = SEL + [0x400, 0x401, c.rng.getrandbits(16)]
    sel = c.rng.choice(choices)
    c.emu.wbytes(self_obj + 0x5d, struct.pack('<H', c.rng.choice(choices)))
    c.emu.wbytes(self_obj + 0x92, bytes([c.rng.choice([0, 0, 1])]))
    c.emu.wbytes(self_obj + 0xbf, bytes([c.rng.choice([0, 1, 1, 2])]))
    c.emu.wbytes(self_obj + 0x14, bytes([c.rng.choice([0x10, 0, 0x30])]))
    r = c.rng.random()
    b7 = 0 if r < 0.3 else (0x3ff if r < 0.6 else c.rng.getrandbits(32))
    c.emu.w32(self_obj + 0xb7, b7)
    c.emu.wbytes(self_obj + 0x4c, struct.pack('<f', c.rng.uniform(0.5, 4.0)))
    cval = struct.unpack('<f', c.emu.rbytes(0x6785d0, 4))[0]
    bb = struct.pack('<f', cval) if c.rng.random() < 0.5 else struct.pack('<f', c.rng.uniform(-3.0, 3.0))
    c.emu.wbytes(self_obj + 0xbb, bb)
    p = _rnd(c, 0x20)
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    c.emu.w32(mgr + 0x40, c.rng.getrandbits(32))
    C = _rnd(c, 0x100)
    cvt = c.emu.fake_vtable('ZDispC', 0x9c, {0x94: _thiscall_log(c, 2, 0)})
    c.emu.w32(C, cvt)
    B = _rnd(c, 0x100)
    bvt = c.emu.fake_vtable('ZDispB', 0x90, {0x80: _thiscall_log(c, 2, 0), 0x20: _thiscall_log(c, 0, C)})
    c.emu.w32(B, bvt)
    c.emu.w32(self_obj + 0x44, B)
    svt = c.emu.logging_vtable('ZDispSelf', 0x90, impl={}, argwords={0x64: 1, 0x68: 2, 0x3c: 0})
    c.emu.w32(self_obj, svt)
    ss.patch(c, 0x4e7d70, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x4e7930, _stub_4e7930(c))
    ss.patch(c, 0x4a5da0, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x4e7ce0, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x4e7c50, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x4a5f20, _float_ret_log(c, _fbits(c)))
    ss.patch(c, 0x4a5fe0, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x4419f0, _fastcall_log(c, 'edx'))
    ss.patch(c, 0x43e960, _fastcall_log(c, 'ecx'))
    ss.patch(c, 0x4de4f0, _fastcall_log(c, 'ecx'))
    ss.patch(c, 0x633654, _ret0(c))
    return [self_obj, sel | (c.rng.getrandbits(16) << 16), p]


S(0x4a51e0, 'residue-name dispatcher (medium) thiscall', 'thiscall', None, ret=None, gen=_disp,
  note='area 35 claim 25; SEH and /GS cookie not modelled; selector paths and helpers stubbed (logged)')
