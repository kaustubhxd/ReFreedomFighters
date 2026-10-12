"""specs_s619.py - band 0x421000-0x441000, batch 619 (see src/batch619.cpp).
0x4346c0 is stdcall: the receiver is the first stack argument. Its slot 4 is a recording fake (four arguments).
0x433cf0 reads the MYSTR at [0x70039c]+0x1a17 through the exe's c_str (not hooked); the receiver's slot 0x48 records its argument.
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


def _gen_four(c):
    r = c.rng
    o = c.emu.fake_object('four', 0x40, nslots=0x20, slots={4: _rec('four.4', 4, 4, r.getrandbits(32))})
    return [o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _gen_c_str(c):
    r = c.rng
    sys_ = c.emu.alloc(0x2000, 16)
    c.emu.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(sys_ + 0x1a17, r.getrandbits(32))   # the MYSTR's first word (the string pointer c_str returns)
    c.emu.w32(SYS_GLOBAL, sys_)
    self_ = c.emu.fake_object('self', 0x40, nslots=0x60, slots={0x48: _rec('self.48', 0x48, 1, 0)})
    return [self_]


S(0x4346c0, 'stdcall: slot 4 of this with (a, 0, b, c)', 'stdcall', None, ret=None, gen=_gen_four)
S(0x433cf0, 'c_str of [0x70039c]+0x1a17 then slot 0x48 of this', 'thiscall', None, ret=None, gen=_gen_c_str)
