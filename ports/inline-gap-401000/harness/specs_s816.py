"""specs_s816.py - core batch 816 (docs/20-unclaimed-65.md). 0x4a1140: thiscall, no arguments. It writes fields of this, calls slot 0x1e0 of the
object at this+0x44 (one argument 0x1007d1, callee pops), stores al, and tail-jumps to 0x4a0d40 with cl = 1. The object at +0x44 has the
slot 0x1e0 (HOOKED here: logs ecx and its argument, returns a random al) and its +8 block has a random dword at +0x3c. 0x4a0d40 is HOOKED
by address (GUESS): a bare return that logs ecx and pops nothing (its own arity is another claim; both runs jump to the same hook)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x4a0d40, c.emu.stub_fn('4a0d40 hook', lambda e, r: (e.calllog.append(('0x4a0d40', e.reg('ecx') & 0xff)),
                                                                     e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    ret1e0 = c.rng.getrandbits(8)
    o_vt = c.emu.fake_vtable('c816-o', 0x500, {
        0x1e0: lambda e, r: (e.calllog.append(('0x1e0', e.reg('ecx'), e.arg32(0))), e.ret(eax=ret1e0, argbytes=4))[-1]})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, o_vt)
    blk = _rnd(c, 0x40)
    c.emu.w32(obj + 8, blk)
    c.emu.w32(blk + 0x3c, c.rng.getrandbits(32))
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x44, obj)
    return [this]


S(0x4a1140, 'core method 0x4a1140 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 816: field writes, slot 0x1e0 call, then a tail jump to 0x4a0d40 with cl = 1')
