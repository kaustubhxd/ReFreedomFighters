"""specs_s6323.py - unclaimed-63 gap-band batch 23: 0x4d2bc0, 0x4d39c0, 0x4d3ab0, 0x4d3db0 (C-set). The shared callee 0x4d24e0 is
stubbed per gen (ss-style patch, with a flush): it records ECX, its first, second and fourth arguments, and the dword its third
argument points to (a stack address; only the content is compared), and returns 0 (ret 0x10)."""
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


def _patch_callee(c):
    cc = _cell(c, 5)
    # mov [cc+8], ecx ... record ecx, arg1 (esp+4), arg2 (esp+8), arg4 (esp+16), *arg3 (esp+12), return 0
    code = (b'\x89\x0d' + _le(cc) +
            b'\x8b\x44\x24\x04\xa3' + _le(cc + 4) +
            b'\x8b\x44\x24\x08\xa3' + _le(cc + 8) +
            b'\x8b\x54\x24\x0c\x8b\x02\xa3' + _le(cc + 12) +
            b'\x8b\x44\x24\x10\xa3' + _le(cc + 16) +
            b'\x31\xc0' + b'\xc2\x10\x00')
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    ss.patch(c, 0x4d24e0, s)
    _flush(c)


def _gen_2bc0(c):
    dst = _rnd(c, 16)
    _patch_callee(c)
    return [c.rng.getrandbits(32), dst, c.rng.getrandbits(32)]


def _gen_39c0(c):
    _patch_callee(c)
    # the callee reads the content of its third argument, which is this function's second argument: it must be a valid pointer
    p = _rnd(c, 8)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), p, c.rng.getrandbits(32)]


def _gen_3(c):
    _patch_callee(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4d2bc0, 'unnamed C-set 0x4d2bc0 thiscall', 'thiscall', None, ret=None, gen=_gen_2bc0, note='unclaimed-63 band batch 23')
S(0x4d39c0, 'unnamed C-set 0x4d39c0 thiscall', 'thiscall', None, ret=None, gen=_gen_39c0, note='unclaimed-63 band batch 23; 0x4d24e0 stubbed')
S(0x4d3ab0, 'unnamed C-set 0x4d3ab0 thiscall', 'thiscall', None, ret=None, gen=_gen_3, note='unclaimed-63 band batch 23; 0x4d24e0 stubbed')
S(0x4d3db0, 'unnamed C-set 0x4d3db0 thiscall', 'thiscall', None, ret=None, gen=_gen_3, note='unclaimed-63 band batch 23; 0x4d24e0 stubbed')
