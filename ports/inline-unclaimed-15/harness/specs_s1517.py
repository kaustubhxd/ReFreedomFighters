"""specs_s1517.py - unclaimed-15 claim 17 (docs/20-unclaimed-15.md): ZFFHERO::~ZFFHERO (0x58b5a0).

Stubbed (unverified, not lifted): 0x634273 (cdecl delete, logs its two arguments), 0x45fa70 (thiscall, two arguments, logs
ecx and both), 0x4cbec0 and 0x480ff0 (thiscall, no arguments, log ecx). Each logging stub returns with the right ret and a
per-case eax. The render manager (global 0x70039c) has a logged slot +0x1a8 (one argument). Its sub-object (+0x9b) has
slot +0x138 returning X (code stub), slot +0x4c returning a per-case value (code stub) and slot +0x114 (logged, four arguments). X's slot +0x88 is a DWORD WRITER: it stores a table value through its second stack argument (the address of
the local) and records its first argument in a heap cell. The hero object (self) is 0x1000 random bytes; its +0x54 is
zero or a 0x18-byte object, and its +0xee4 is zero or a logged object whose slot 0 takes one argument."""
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


def _thiscall_log(c, nargs, ret):
    """thiscall stub: stores ecx and its nargs stack arguments in heap cells, returns ret in eax, ret 4*nargs."""
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _cdecl_log2(c):
    """cdecl (p, size) stub: stores its two stack arguments in two heap dwords, returns with ret 0."""
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\xc3')
    return ss.code(c, code)


def _ret_const(c, value):
    return ss.code(c, b'\xb8' + ss.P(value) + b'\xc3')


def _dword_writer(c, table):
    """thiscall writer with two arguments: records its first argument in a heap cell, stores the next table dword through
    its second argument (a stack address), counter += 1; ret 8."""
    tab = c.emu.alloc(4 * len(table), 4)
    c.emu.wbytes(tab, b''.join(ss.P(v) for v in table))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    arg0 = c.emu.alloc(4, 4)
    c.emu.w32(arg0, 0)
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(arg0)            # mov eax, [esp+4] ; mov [arg0], eax
            + b'\x8b\x54\x24\x08'                                  # mov edx, [esp+8]  (pointer argument)
            + b'\xa1' + ss.P(cnt)                                  # mov eax, [cnt]
            + b'\x8b\x0c\x85' + ss.P(tab)                          # mov ecx, [tab + eax*4]
            + b'\x89\x0a'                                          # mov [edx], ecx
            + b'\xff\x05' + ss.P(cnt)                              # inc dword [cnt]
            + b'\xc2\x08\x00')                                     # ret 8
    return ss.code(c, code)


def _dtor(c):
    self_obj = _rnd(c, 0x1000)
    c.emu.w32(self_obj + 0x54, c.rng.choice([0, _rnd(c, 0x18)]))
    o = _rnd(c, 0x40)
    ovt = c.emu.logging_vtable('ZFFHeroChild', 0x40, impl={}, argwords={0: 1})
    c.emu.w32(o, ovt)
    c.emu.w32(self_obj + 0xee4, c.rng.choice([0, o]))
    ss.patch(c, 0x634273, _cdecl_log2(c))
    ss.patch(c, 0x45fa70, _thiscall_log(c, 3, 0))   # three arguments (ret 0xc)
    ss.patch(c, 0x4cbec0, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x480ff0, _thiscall_log(c, 0, 0))
    # X (returned by slot +0x138): its slot +0x88 writes a dword into the local.
    x = _rnd(c, 0x200)
    xvt = c.emu.fake_vtable('ZHeroX', 0x80, {0x88: _dword_writer(c, [c.rng.getrandbits(32) for _ in range(8)])})
    c.emu.w32(x, xvt)
    # The render sub-object (rm + 0x9b).
    sub = _rnd(c, 0x200)
    subvt = c.emu.fake_vtable('ZHeroRenderSub', 0x140, {
        0x138: _ret_const(c, x),
        0x4c: _ret_const(c, c.rng.getrandbits(32)),
        0x114: _thiscall_log(c, 4, c.rng.getrandbits(32)),   # four arguments (ret 0x10); ebx and r4c are left over
    })
    c.emu.w32(sub, subvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, sub)
    rmvt = c.emu.fake_vtable('ZRenderManager', 0x1b0, {0x1a8: _thiscall_log(c, 2, 0)})   # two arguments (ebx is left over)
    c.emu.w32(rm, rmvt)
    c.emu.w32(0x70039c, rm)
    return [self_obj]


S(0x58b5a0, 'ZFFHERO::~ZFFHERO (unknown) thiscall', 'thiscall', None, ret=None, gen=_dtor,
  note='unclaimed-15 claim 17; 0x634273, 0x45fa70, 0x4cbec0, 0x480ff0 stubbed; render slots logged; X writer')
