"""specs_s634.py - band 0x421000-0x441000, batch 634 (see src/batch634.cpp).
0x4272e0: ZSysFileGC::LoadDllExports(const char*). Calls ext_676114(path, &out1, &out2, &out3);
if result nonzero, returns out1:out2 in eax:edx (64-bit pair); else returns 0:0.
The external function is hooked to always succeed; outputs are zeros (unmodified locals).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402


def _gen(c):
    r = c.rng
    # Patch IAT slot 0x676114 with stub that always succeeds (returns 1)
    # The stub does NOT write to outputs, so locals remain 0
    stub_addr = ss.rec(c, 4, ret=1)
    c.emu.w32(0x676114, stub_addr)
    c.emu._image_dirty = True
    # Test argument: allocate valid path string
    path_str = c.emu.alloc(256, 4)
    test_path = b"test.dll\x00"
    c.emu.wbytes(path_str, test_path + bytes(256 - len(test_path)))
    return [path_str]


S(0x4272e0, 'ZSysFileGC::LoadDllExports(const char*)', 'stdcall', None, ret='eax:edx', gen=_gen)
