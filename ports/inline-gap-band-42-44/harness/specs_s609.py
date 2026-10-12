"""specs_s609.py - band 0x421000-0x441000, batch 609: nine short accessors and one constructor (see src/batch609.cpp).
The vslot 0x154 on the global sys object (0x70039c) records its argument; the objects are random-filled blocks so a wrong
store shows as a heap difference.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

SYS_GLOBAL = 0x70039c


def _block(c, size):
    a = c.emu.alloc(size, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _gen_self(size):
    def gen(c):
        return [_block(c, size)]
    return gen


def _gen_byte(c):
    return [_block(c, 0x40), c.rng.getrandbits(8)]


def _gen_dword(c):
    return [_block(c, 0x1c00), c.rng.getrandbits(32)]


def _gen_none(c):
    return []


def _gen_sys(c):
    r = c.rng

    def h154(e, rr):
        e.calllog.append(('sys.154', 0x154, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    sys_ = c.emu.fake_object('sys', 0x100, nslots=0x160, slots={0x154: h154})
    c.emu.w32(SYS_GLOBAL, sys_)
    return [r.getrandbits(32)]


S(0x424450, '0x424450 (byte +0x25e8 = 1)', 'thiscall', None, ret=None, gen=_gen_self(0x2600))
S(0x428ab0, '0x428ab0 (dword 0x7003a0 = 0)', 'cdecl', None, ret=None, gen=_gen_none)
S(0x428fb0, '0x428fb0 (returns this+0x11)', 'thiscall', None, ret='eax', gen=_gen_self(0x40))
S(0x428fc0, '0x428fc0 (returns this+0x35)', 'thiscall', None, ret='eax', gen=_gen_self(0x40))
S(0x429450, '0x429450 (returns byte +0xc)', 'thiscall', None, ret='al', gen=_gen_self(0x40))
S(0x4298a0, '0x4298a0 (byte +0xc = arg)', 'thiscall', None, ret=None, gen=_gen_byte)
S(0x423ee0, '0x423ee0 (dword +0x1b37 = arg)', 'thiscall', None, ret=None, gen=_gen_dword)
S(0x42acc0, '0x42acc0 (constructor)', 'thiscall', None, ret='eax', gen=_gen_self(0x40))
S(0x424d70, '0x424d70 (sys slot 0x154 with arg)', 'cdecl', None, ret='eax', gen=_gen_sys)
