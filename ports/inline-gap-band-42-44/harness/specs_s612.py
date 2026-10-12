"""specs_s612.py - band 0x421000-0x441000, batch 612 (see src/batch612.cpp).
0x429ab0 calls the object's slot 0x2c (no args) and, when this+0xd is set, the referenced object's slot 8 with the object
as its one argument: both recorded. 0x4331f0 notifies through 0x431580 (hooked by address, thiscall, two args, ret 8).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _rec(name, nargs, ret=0):
    def h(e, rr):
        e.calllog.append((name, 0, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _gen_release(c):
    r = c.rng
    if r.random() < 0.6:
        o = c.emu.fake_object('ref', 0x40, nslots=0x20, slots={8: _rec('ref.8', 1)})
    else:
        o = 0
    self_ = c.emu.fake_object('self', 0x40, nslots=0x30, slots={0x2c: _rec('self.2c', 0)})
    c.emu.w32(self_ + 0xd, o)
    return [self_]


def _gen_byte(c):
    r = c.rng
    self_ = c.emu.alloc(0x200, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    c.emu.w8(self_ + 0x101, r.choice((0, 1, 2)))
    # a hook for the notify helper, recorded
    def notify(e, rr):
        e.calllog.append(('notify.431580', 0, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(argbytes=8)
    c.emu.hook(0x431580, notify)
    arg = r.choice((0, 1, 2, r.getrandbits(32), r.getrandbits(8) << 8))
    return [self_, arg]


S(0x429ab0, 'release: slot 0x2c, then slot 8 of this+0xd and clear', 'thiscall', None, ret='al', gen=_gen_release)
S(0x4331f0, 'set byte +0x101 with notify (value = arg == 0)', 'thiscall', None, ret=None, gen=_gen_byte)
