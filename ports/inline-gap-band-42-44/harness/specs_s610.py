"""specs_s610.py - band 0x421000-0x441000, batch 610 (see src/batch610.cpp).
The notify helpers 0x431580 and 0x431410 are hooked by address (thiscall, two arguments, ret 8) and record their call.
Arguments are full dwords, including the byte setters (the exe's compare uses the low byte, the notify uses the dword).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

_hooked = {}


def _notify_hooks(c):
    def rec(name):
        def h(e, rr):
            e.calllog.append((name, 0, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
            e.ret(argbytes=8)
        return h
    c.emu.hook(0x431580, rec('notify.431580'))
    c.emu.hook(0x431410, rec('notify.431410'))


def _block(c, size):
    a = c.emu.alloc(size, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _gen_byte(off):
    def gen(c):
        r = c.rng
        _notify_hooks(c)
        self_ = _block(c, 0x200)
        cur = c.emu.r8(self_ + off) if hasattr(c.emu, 'r8') else c.emu.rbytes(self_ + off, 1)[0]
        v = (cur | (r.getrandbits(24) << 8)) if r.random() < 0.5 else r.getrandbits(32)
        return [self_, v]
    return gen


def _gen_dword(c):
    r = c.rng
    _notify_hooks(c)
    self_ = _block(c, 0x200)
    cur = c.emu.r32(self_ + 0x102)
    v = cur if r.random() < 0.4 else r.getrandbits(32)
    return [self_, v]


def _gen_one(c):
    r = c.rng
    self_ = _block(c, 0x40)
    return [self_, r.getrandbits(32)]


def _gen_list(c):
    r = c.rng
    self_ = _block(c, 0x40)
    c.emu.w32(self_ + 0x1c, r.randint(0, 4))
    return [self_, r.getrandbits(32)]


def _gen_flag(c):
    r = c.rng
    self_ = _block(c, 0x40)
    v = r.choice((0, 1, r.getrandbits(32)))
    return [self_, v]


S(0x4333c0, 'CConfiguration::set byte +0xfd', 'thiscall', None, ret=None, gen=_gen_byte(0xfd))
S(0x4333f0, 'CConfiguration::set byte +0xfe', 'thiscall', None, ret=None, gen=_gen_byte(0xfe))
S(0x4335a0, 'CConfiguration::set byte +0xfc', 'thiscall', None, ret=None, gen=_gen_byte(0xfc))
S(0x433e90, 'set byte +0x106', 'thiscall', None, ret=None, gen=_gen_byte(0x106))
S(0x433e60, 'set dword +0x102', 'thiscall', None, ret=None, gen=_gen_dword)
S(0x4359f0, 'constructor (vtable 0x67a630, +4 = arg)', 'thiscall', None, ret='eax', gen=_gen_one)
S(0x435d70, 'push into 3-slot list at +0x10 (count +0x1c)', 'thiscall', None, ret=None, gen=_gen_list)
S(0x43e5d0, 'set/clear bit 0 of dword +0x18', 'thiscall', None, ret=None, gen=_gen_flag)
