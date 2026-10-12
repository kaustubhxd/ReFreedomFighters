"""specs_s616.py - band 0x421000-0x441000, batch 616 (see src/batch616.cpp).
0x431f80 and 0x433e40 use the sys object at [0x70039c] (+0x1907 holds the keys object for 0x431f80; 0x1e8 is a slot of sys).
0x433e40 also calls exe 0x432cd0 on the receiver, so the receiver is a fake object with slots 0 and 0x4c.
0x435b30 frees through 0x634273: hooked by address (cdecl, recorded, no pops).
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


def _gen_apply(c):
    r = c.rng
    sys_ = c.emu.alloc(0x2000, 16)
    c.emu.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0x2000)))
    keys = c.emu.fake_object('keys', 0x40, nslots=0x20, slots={0: _rec('keys.0', 0, 1, 0)})
    c.emu.w32(sys_ + 0x1907, keys)
    c.emu.w32(SYS_GLOBAL, sys_)
    self_ = c.emu.alloc(0x200, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    return [self_]


def _gen_and(c):
    r = c.rng
    sys_ = c.emu.fake_object('sys', 0x2000, nslots=0x100, slots={0x1e8: _rec('sys.1e8', 0x1e8, 0, r.getrandbits(32))})
    c.emu.w32(SYS_GLOBAL, sys_)
    self_ = c.emu.fake_object('recv', 0x200, nslots=0x60, slots={0x0: _rec('recv.0', 0, 0, r.getrandbits(32)),
                                                                 0x4c: _rec('recv.4c', 0x4c, 0, r.getrandbits(32))})
    return [self_]


def _gen_free(c):
    r = c.rng
    def hook_free(e, rr):
        e.calllog.append(('free', 0x634273, 0, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)   # cdecl: the caller pops
    c.emu.hook(0x634273, hook_free)
    self_ = c.emu.alloc(0x20, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x20)))
    p = c.emu.alloc(0x10, 16) if r.random() < 0.7 else 0
    c.emu.w32(self_ + 8, p)
    return [self_]


S(0x431f80, 'CConfiguration::ApplyKeys', 'thiscall', None, ret=None, gen=_gen_apply)
S(0x433e40, 'and of ext 0x432cd0 and sys slot 0x1e8', 'thiscall', None, ret='al', gen=_gen_and)
S(0x435b30, 'reset vtable, free +8 via 0x634273', 'thiscall', None, ret=None, gen=_gen_free)
