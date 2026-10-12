"""specs_s620.py - band 0x421000-0x441000, batch 620 (see src/batch620.cpp).
0x43d360: the sys object at [0x70039c] has slot 0xbc returning a recording object whose slot 0x5c (two arguments) returns
a random value (only its low-bit truthiness is returned). 0x434ab0 is stdcall: the MYSTR at self is assigned by the exe's
0x4cbe80 (not hooked). The MYSTR's first word is compared in the heap.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

SYS_GLOBAL = 0x70039c


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _gen_hap(c):
    r = c.rng
    o = c.emu.fake_object('hap_o', 0x40, nslots=0x80, slots={0x5c: _rec('hap.5c', 0x5c, 2, r.getrandbits(32))})
    sys_ = c.emu.fake_object('sys', 0x40, nslots=0x80, slots={0xbc: _rec('sys.bc', 0xbc, 0, o)})
    c.emu.w32(SYS_GLOBAL, sys_)
    return [c.emu.alloc(0x40, 16)]


def _gen_conv(c):
    r = c.rng
    self_ = c.emu.alloc(0x40, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    text = bytes(r.randint(0x21, 0x7e) for _ in range(r.randint(0, 40)))
    sp = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(sp, text + b'\x00')
    return [self_, sp]   # a valid C string: the assign reads it


S(0x43d360, 'ZHapticsBase::HapticsEnabled', 'thiscall', None, ret='al', gen=_gen_hap)
S(0x434ab0, 'ZSysFile::ConvertFilename (stdcall, returns this)', 'stdcall', None, ret='eax', gen=_gen_conv)
