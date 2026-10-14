"""specs_s1518.py - unclaimed-15 claim 18 (docs/20-unclaimed-15.md): ZFFHERO::Load2 (0x592c60).

Stubbed (unverified, not lifted): 0x474710, 0x592580 and 0x595100 are thiscall no-arg stubs that log ecx. The render sub-object's
slot +0x114 is a code stub with six arguments: it logs ecx and five of its six arguments in heap cells (not the fifth, a stack address), writes the next value of a
per-case table through its fifth argument (the local's address), and returns a per-case eax, ret 24. The hero (self) has a
logged vtable whose slot +0x128 takes one argument. The global object at 0x70038c has a logged slot +0xcc (one argument). The
render sub-object's +0xadc object has a logged slot +0x25c (two arguments; returns an object or 0) whose result has a logged
slot +0x100 (one argument). The hero is 0x1000 random bytes; the render sub-object is 0xb00 bytes so +0xadc is inside it."""
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
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _slot128(c, table):
    """thiscall, three arguments (r16, &local, 0): logs ecx, arg0 and arg2 (arg1 is a stack address); writes the next
    table value through arg1; ret 12."""
    cells = c.emu.alloc(4 * 3, 4)
    c.emu.wbytes(cells, bytes(12))
    tab = c.emu.alloc(4 * len(table), 4)
    c.emu.wbytes(tab, b''.join(ss.P(v) for v in table))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = (b'\x89\x0d' + ss.P(cells)                         # mov [cells], ecx
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 4)    # arg0 -> cells[1]
            + b'\x8b\x44\x24\x0c' + b'\xa3' + ss.P(cells + 8)    # arg2 -> cells[2]
            + b'\x8b\x54\x24\x08'                            # mov edx, [esp+8]  (arg1: pointer)
            + b'\xa1' + ss.P(cnt)                              # mov eax, [cnt]
            + b'\x8b\x0c\x85' + ss.P(tab)                      # mov ecx, [tab + eax*4]
            + b'\x89\x0a'                                     # mov [edx], ecx
            + b'\xff\x05' + ss.P(cnt)                          # inc dword [cnt]
            + b'\xb8' + ss.P(0)                                # mov eax, 0
            + b'\xc2\x0c\x00')                                 # ret 12
    return ss.code(c, code)


def _slot114(c, table, ret):
    """thiscall, six arguments: logs ecx and the six arguments, writes table[counter] through arg4 (the local's
    address, at [esp + 4 + 16]), counter += 1, returns ret; ret 24."""
    cells = c.emu.alloc(4 * 7, 4)
    c.emu.wbytes(cells, bytes(4 * 7))
    tab = c.emu.alloc(4 * len(table), 4)
    c.emu.wbytes(tab, b''.join(ss.P(v) for v in table))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\x89\x0d' + ss.P(cells)                       # mov [cells], ecx
    for i in (0, 1, 2, 3, 5):                               # arg4 is the local's stack address: not logged
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += (b'\x8b\x54\x24\x14'                            # mov edx, [esp + 20]  (arg4: pointer)
             + b'\xa1' + ss.P(cnt)                          # mov eax, [cnt]
             + b'\x8b\x0c\x85' + ss.P(tab)                  # mov ecx, [tab + eax*4]
             + b'\x89\x0a'                                  # mov [edx], ecx
             + b'\xff\x05' + ss.P(cnt)                      # inc dword [cnt]
             + b'\xb8' + ss.P(ret)                          # mov eax, ret
             + b'\xc2\x18\x00')                             # ret 24
    return ss.code(c, code)


def _load2(c):
    self_obj = _rnd(c, 0x1000)
    ss.patch(c, 0x474710, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x592580, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x595100, _thiscall_log(c, 0, 0))
    table128 = [c.rng.getrandbits(32) for _ in range(8)]
    hvt = c.emu.fake_vtable('ZFFHeroLoad', 0x140, {0x128: _slot128(c, table128)})
    c.emu.w32(self_obj, hvt)
    g = _rnd(c, 0x200)
    gvt = c.emu.logging_vtable('ZGlobalLoad', 0x80, impl={0xcc: lambda e, a: (c.rng.getrandbits(32), None)},
                               argwords={0xcc: 1})
    c.emu.w32(g, gvt)
    c.emu.w32(0x70038c, g)
    table = [c.rng.getrandbits(32) for _ in range(8)]
    sub = _rnd(c, 0xb00)
    x2 = _rnd(c, 0x200)
    x2vt = c.emu.logging_vtable('ZFFHeroX2', 0x80, impl={}, argwords={0x100: 1})
    c.emu.w32(x2, x2vt)
    o2 = _rnd(c, 0x200)
    picked = x2 if c.rng.random() < 0.7 else 0
    o2vt = c.emu.logging_vtable('ZFFHeroO2', 0x100, impl={0x25c: lambda e, a: (picked, None)}, argwords={0x25c: 2})
    c.emu.w32(o2, o2vt)
    c.emu.w32(sub + 0xadc, o2)
    subvt = c.emu.fake_vtable('ZHeroRenderSub3', 0x140, {0x114: _thiscall_log(c, 4, c.rng.getrandbits(32))})
    c.emu.w32(sub, subvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, sub)
    c.emu.w32(0x70039c, rm)
    return [self_obj]


S(0x592c60, 'ZFFHERO::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load2,
  note='unclaimed-15 claim 18; 0x474710, 0x592580, 0x595100 stubbed (log ecx); render slot +0x114 logs six args + writer')
