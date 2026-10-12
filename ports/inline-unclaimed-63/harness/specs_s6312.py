"""specs_s6312.py - unclaimed-63 batch 12 (docs/20-unclaimed-63.md): ZGEOM::ChkFaceLineColi (0x45d320), stdcall with two
arguments (ret 8). Stub: the collision object M (global 0x70039c -> rm; rm+0x1aa3 -> obj; obj+0x1c -> M) has a vtable slot +0x60
that writes a value through its first argument (the address of the caller's local, so the write is not compared), records its
other five arguments (the coli, ids, coli+0xc pointers and the byte and -1 values) in rings, and returns R; the callee pops 24.
The coli byte at +0x6c is random."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen(c):
    coli = _rnd(c, 0x80)
    c.emu.wbytes(coli + 0x6c, bytes([c.rng.getrandbits(8)]))
    ids = _rnd(c, 0x40)
    rm = _rnd(c, 0x2000)
    obj = _rnd(c, 0x40)
    M = _rnd(c, 0x40)
    c.emu.w32(rm + 0x1aa3, obj)
    c.emu.w32(obj + 0x1c, M)
    c.emu.w32(0x70039c, rm)
    vt = c.emu.alloc(0x200, 4)
    cells = _cell(c, 5)
    K = c.rng.getrandbits(32)
    R = c.rng.getrandbits(32)
    code = b'\x8b\x44\x24\x04' + b'\xc7\x00' + _le(K)              # mov eax,[esp+4]; mov dword [eax], K
    for j in range(5):                                             # record arguments 2..6
        code += bytes([0x8b, 0x44, 0x24, 8 + 4 * j]) + b'\xa3' + _le(cells + 4 * j)
    code += b'\xb8' + _le(R) + b'\xc2\x18\x00'                     # mov eax, R; ret 24
    c.emu.w32(vt + 0x60, _stub(c, code))
    c.emu.w32(M, vt)
    _flush(c)
    return [coli, ids]


S(0x45d320, 'ZGEOM::ChkFaceLineColi (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen,
  note='unclaimed-63 batch 12; collision object vtbl+0x60 stub (six args, ret 24); /GS check not reproduced')
