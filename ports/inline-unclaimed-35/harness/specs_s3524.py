"""specs_s3524.py - area 35 claim 24 (docs/20-unclaimed-35.md): 0x49ff60 (residue name, medium).

Stubbed: readers 0x4e5e60 (int, sequence), 0x4e5e40 (word, sequence), 0x4e5ea0 (string, sequence of heap strings; logs ecx);
0x4cc1d0 (thiscall, logs ecx, returns R2); 0x4cbec0 (no-op, the local's address is not logged); 0x633654 (no-op; the exe's
/GS cookie check, whose ecx is a cookie). Fake objects: the global at 0x70039c with +0x9b -> M (vtable slot +0x138 returns R3),
M+0xae4 -> O (slot 0 returns its argument 1 when it matches the string, else a constant); 0x700390 -> G (slot +0x20 returns X);
X (slot +0x30, cdecl, logs 4 args); B = this+0x44 (slot +0x1d8, logs ecx and arg1, returns R1); R3 (slot +0x88 writes a value
through its pointer argument, logs arg0); this (logging slot +0x88). The reader's first dword points at a flag byte."""
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


def _seq(c, tab, kind):
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in tab))
    cells = _log_cells(c, 1)
    code = b'\x89\x0d' + ss.P(cells) + b'\xa1' + ss.P(cnt) + b'\x8b\x04\x85' + ss.P(tb)
    code += b'\xff\x05' + ss.P(cnt) + b'\xc3'
    return ss.code(c, code)


def _thiscall_log(c, nargs, ret):
    cells = _log_cells(c, 1 + nargs)
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _ret0(c):
    return ss.code(c, b'\xc3')


def _slot0_stub(c, match, K):
    cells = _log_cells(c, 2)
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)              # arg0 -> cells[0]
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4))        # arg1 -> cells[1]
    if match:
        code += b'\x8b\x44\x24\x08'                                   # mov eax, [esp+8]  (arg1)
    else:
        code += b'\xb8' + ss.P(K)                                     # mov eax, K
    code += b'\xc2\x08\x00'
    return ss.code(c, code)


def _slot88_r3(c, W):
    cells = _log_cells(c, 1)
    code = (b'\x8b\x54\x24\x08'                                       # mov edx, [esp+8]  (pointer)
            + b'\xc7\x02' + struct.pack('<I', W)                      # mov dword [edx], W
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)             # arg0 -> cells
            + b'\xb8' + ss.P(0) + b'\xc2\x08\x00')
    return ss.code(c, code)


def _slot1d8(c, R1):
    cells = _log_cells(c, 2)
    code = (b'\x89\x0d' + ss.P(cells)                                 # mov [cells], ecx
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)         # arg1 -> cells[1] (the value 1)
            + b'\xb8' + ss.P(R1) + b'\xc2\x08\x00')
    return ss.code(c, code)


def _cdecl4(c):
    cells = _log_cells(c, 4)
    code = b''
    for i in range(4):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 * i)
    code += b'\xb8' + ss.P(0) + b'\xc3'
    return ss.code(c, code)


def _block(c):
    self_obj = _rnd(c, 0x200)
    R = _rnd(c, 0x100)
    fb = _rnd(c, 4)
    flag = c.rng.choice([0xff, 0x03, 0x43, c.rng.getrandbits(8)])
    c.emu.wbytes(fb, bytes([flag]))
    c.emu.w32(R, fb)
    # strings: str1 (the first read), str2 (the second read); later reads reuse str2
    def mkstr():
        n = c.rng.randrange(0, 12)
        b = bytes(c.rng.randrange(65, 123) for _ in range(n)) + b'\x00'
        p = c.emu.alloc(len(b), 4)
        c.emu.wbytes(p, b)
        return p
    str1 = mkstr() if c.rng.random() < 0.85 else mkstr()
    if c.rng.random() < 0.85:
        c.emu.wbytes(str1, bytes(c.rng.randrange(65, 123) for _ in range(c.rng.randrange(1, 10))) + b'\x00')
    str2 = mkstr()
    strs = [str1, str2] + [str2] * 14
    ints = [0 if c.rng.random() < 0.4 else c.rng.getrandbits(32) for _ in range(16)]
    words = [c.rng.getrandbits(32) for _ in range(16)]
    ss.patch(c, 0x4e5e60, _seq(c, ints, 'u32'))
    ss.patch(c, 0x4e5e40, _seq(c, words, 'u32'))
    ss.patch(c, 0x4e5ea0, _seq(c, strs, 'u32'))
    R2 = c.rng.getrandbits(32)
    R1 = c.rng.getrandbits(32)
    ss.patch(c, 0x4cc1d0, _thiscall_log(c, 0, R2))
    ss.patch(c, 0x4cbec0, _ret0(c))
    ss.patch(c, 0x633654, _ret0(c))
    # global objects
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    M = _rnd(c, 0x1000)
    R3 = _rnd(c, 0x100)
    W = c.rng.getrandbits(32)
    r3vt = c.emu.fake_vtable('ZFFR3', 0x90, {0x88: _slot88_r3(c, W)})
    c.emu.w32(R3, r3vt)
    mvt = c.emu.fake_vtable('ZFFMgrM', 0x150, {0x138: _thiscall_log(c, 0, R3)})
    c.emu.w32(M, mvt)
    c.emu.w32(mgr + 0x9b, M)
    O = _rnd(c, 0x100)
    match = c.rng.random() < 0.6
    ovt = c.emu.fake_vtable('ZFFSlot0', 0x40, {0: _slot0_stub(c, match, c.rng.getrandbits(32))})
    c.emu.w32(O, ovt)
    c.emu.w32(M + 0xae4, O)
    G = _rnd(c, 0x100)
    X = _rnd(c, 0x100)
    xvt = c.emu.fake_vtable('ZFFX', 0x40, {0x30: _cdecl4(c)})
    c.emu.w32(X, xvt)
    gvt = c.emu.fake_vtable('ZFFG', 0x40, {0x20: _thiscall_log(c, 2, X)})
    c.emu.w32(G, gvt)
    c.emu.w32(0x700390, G)
    B = _rnd(c, 0x100)
    bvt = c.emu.fake_vtable('ZFFB', 0x1e0, {0x1d8: _slot1d8(c, R1)})
    c.emu.w32(B, bvt)
    c.emu.w32(self_obj + 0x44, B)
    selfvt = c.emu.logging_vtable('ZFFSelf', 0x90, impl={}, argwords={0x88: 2})
    c.emu.w32(self_obj, selfvt)
    return [self_obj, R]


S(0x49ff60, 'residue-name reader block (medium) thiscall', 'thiscall', None, ret=None, gen=_block,
  note='area 35 claim 24; SEH and /GS cookie not modelled; readers and fake objects stubbed (logged)')
