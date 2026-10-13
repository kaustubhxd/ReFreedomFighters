"""specs_s3521.py - area 35 claim 21 (docs/20-unclaimed-35.md): 0x4a5820, ZMatPosAnim::ExpandBounds (residue name).

Stubbed (logged): slot +0x4c (one arg, magic) and slot +0x98 (two args) of A = this+0x44 (logging vtable); 0x4e7880
(thiscall, four stack args; ecx is a stack address, not logged); 0x4e7530 (thiscall, five stack args; ecx not logged);
0x4de420 (fastcall, logs ecx and edx). The render manager at 0x70039c has a dword at +0x40. The float at this+0xc7 is
random bits; the byte flags at +0xc4, +0xc6 and +0xd4 are random."""
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


def _thiscall_args_log(c, nargs):
    """thiscall with nargs stack arguments (callee cleans); logs the arguments, not ecx."""
    cells = c.emu.alloc(4 * nargs, 4)
    c.emu.wbytes(cells, bytes(4 * nargs))
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 * i)   # mov eax,[esp+4+4i]; mov [cells+4i],eax
    code += b'\xb8' + ss.P(0) + b'\xc2' + struct.pack('<H', 4 * nargs)                  # mov eax, 0; ret 4*nargs
    return ss.code(c, code)


def _fastcall_log(c):
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x89\x0d' + ss.P(cells)                      # mov [cells], ecx
            + b'\x89\x15' + ss.P(cells + 4)                # mov [cells+4], edx
            + b'\xb8' + ss.P(0) + b'\xc3')                 # mov eax, 0; ret
    return ss.code(c, code)


def _expand(c):
    self_obj = _rnd(c, 0x200)
    c.emu.wbytes(self_obj + 0xd4, bytes([c.rng.choice([0, 1])]))
    A = _rnd(c, 0x200)
    S_ = _rnd(c, 0x100)
    c.emu.w32(A + 8, S_)
    avt = c.emu.logging_vtable('ZMatPosAnimA', 0x140, impl={0x4c: lambda e, a: (c.rng.getrandbits(32), None),
                                                              0x98: lambda e, a: (0, None)},
                               argwords={0x4c: 1, 0x98: 2})
    c.emu.w32(A, avt)
    c.emu.w32(self_obj + 0x44, A)
    mgr = _rnd(c, 0x100)
    c.emu.w32(mgr + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, mgr)
    c.emu.wbytes(self_obj + 0xc4, bytes([c.rng.getrandbits(8)]))
    c.emu.wbytes(self_obj + 0xc6, bytes([c.rng.getrandbits(8)]))
    c.emu.w32(self_obj + 0xc7, c.rng.getrandbits(32))
    ss.patch(c, 0x4e7880, _thiscall_args_log(c, 4))
    ss.patch(c, 0x4e7530, _thiscall_args_log(c, 5))
    ss.patch(c, 0x4de420, _fastcall_log(c))
    return [self_obj, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4a5820, 'ZMatPosAnim::ExpandBounds(float*, float*, float*, ZBaseGeom*) (residue name) thiscall', 'thiscall', None,
  ret=None, gen=_expand,
  note='area 35 claim 21; 0x4e7880 (4 args), 0x4e7530 (5 args), 0x4de420 (fastcall) stubbed; slots +0x4c, +0x98 logged')
