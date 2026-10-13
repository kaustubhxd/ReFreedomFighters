"""specs_s3523.py - area 35 claim 23 (docs/20-unclaimed-35.md): 0x4fd020, CMAINCAMERACONTROL::Load(ZLoadGame*) (residue name).

Stubbed: the loader's vtable (logging; slots +0x40, +0x44, +0x48, +0x50, +0x68, +0x70 take one argument, +0x18 takes two);
the global object at 0x70039c+0x1907 (when non-null) with a logging vtable slot +0xc (three arguments); 0x4fd5d0 (thiscall,
no args, logs ecx). The stubs do not write the fields of this; the pointers they receive are logged, so they are checked."""
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


def _cam(c):
    self_obj = _rnd(c, 0x200)
    L = _rnd(c, 0x100)
    lvt = c.emu.logging_vtable('ZLoadGameCam', 0x100, impl={},
                               argwords={0x40: 1, 0x44: 1, 0x48: 1, 0x50: 1, 0x68: 1, 0x70: 1, 0x18: 2})
    c.emu.w32(L, lvt)
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    if c.rng.random() < 0.7:
        gobj = _rnd(c, 0x100)
        gvt = c.emu.logging_vtable('ZCamGlobal', 0x40, impl={}, argwords={0xc: 3})
        c.emu.w32(gobj, gvt)
        c.emu.w32(mgr + 0x1907, gobj)
    else:
        c.emu.w32(mgr + 0x1907, 0)
    ss.patch(c, 0x4fd5d0, _thiscall_log(c, 0, 0))
    return [self_obj, L]


S(0x4fd020, 'CMAINCAMERACONTROL::Load(ZLoadGame*) (residue name) thiscall', 'thiscall', None, ret='al', gen=_cam,
  note='area 35 claim 23; loader vtable and global slot +0xc logged; 0x4fd5d0 stubbed')
