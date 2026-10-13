"""specs_s1209.py - unclaimed-12 batch 9 (docs/20-unclaimed-12.md, claim 9, in slice): two deleting destructors with no base
call. Each sets its vtable, then calls operator delete (0x634273, cdecl, a logging stub) when flag bit 0 is set. Returns this."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S

def _flush_code(c):
    """Drop Unicorn's cached translations for the heap and the exe image after a patch (as area 20 does): a stale
    translation otherwise runs in place of the new stub bytes."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup_delete(c):
    import serial_stubs as ss

    def h(e, r):
        e.calllog.append(('0x634273', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)     # cdecl: the caller pops its two arguments
    ss.patch(c, 0x634273, c.emu.stub_fn('0x634273', h))
    _flush_code(c)


def _dtor_gen(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x441cf0, 'ZOctree::~ZOctree (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor_gen,
  setup=_setup_delete, note='unclaimed-12 batch 9 (in slice, medium name); vtable 0x67d108; delete 0x14 if flag bit 0')
S(0x487930, 'ZMovementAnimation::~ZMovementAnimation (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor_gen,
  setup=_setup_delete, note='unclaimed-12 batch 9 (in slice, low name); vtable 0x68cf50; delete 0x1d if flag bit 0')
