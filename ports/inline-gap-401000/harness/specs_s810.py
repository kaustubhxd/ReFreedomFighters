"""specs_s810.py - core batch 810 (docs/20-unclaimed-65.md). 0x5c74a0: stdcall, one argument s (ret 4), returns a bool in al.
Object at s+8: slot 0x14 (no args; zero in a quarter of the cases returns 1 at once), slots 0x4c and 0x5c (one pointer argument: the
local L is written by the stub, and 0x5c also returns the value edi). The render sub-object at [0x70039c]+0x9b has slot 0x58 (one
argument; returns one of two objects). Those objects have slot 0x1e0 (one argument, al) and slot 0x438 (no args, al). Every answer is a
hash of the case seed and the call count, so the orig and port runs see the same values; the 0x5c loop ends after at most five turns.
Pointer arguments (the frame local) are not logged (the frames differ)."""
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


def _h(seed, *keys):
    return hash((seed,) + keys) & 0xffffffff


def _count(e, name):
    return sum(1 for x in e.calllog if x[0] == name)


def _setup(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    seed = c.rng.getrandbits(32)

    # the object at s+8: slot 0x14 (zero or not), 0x4c (writes L), 0x5c (writes L, returns edi)
    def s14(e, r):
        v = _h(seed, 0x14)
        e.calllog.append(('0x14', e.reg('ecx')))
        e.ret(eax=0 if (v & 3) == 0 else (v | 1), argbytes=0)

    def s4c(e, r):
        e.calllog.append(('0x4c', e.reg('ecx')))
        e.w32(e.arg32(0), _h(seed, 0x4c) | 1)
        e.ret(eax=0, argbytes=4)

    def s5c(e, r):
        k = _count(e, '0x5c')
        e.calllog.append(('0x5c', e.reg('ecx')))
        v = _h(seed, 0x5c, k)
        lv = 0 if (k >= 4 or (v & 3) == 0) else (v | 1)
        e.w32(e.arg32(0), lv)
        e.ret(eax=(v >> 4) & 0xffffffff, argbytes=4)

    o_vt = c.emu.fake_vtable('c810-o', 0x100, {0x14: s14, 0x4c: s4c, 0x5c: s5c})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    s = _rnd(c, 0x40)
    c.emu.w32(s + 8, o)

    # the two objects returned by slot 0x58: slot 0x1e0 (one argument) and slot 0x438 (none), both answer al
    def al_of(v):
        return 0 if (v & 3) == 0 else (v | 1)

    def s1e0(e, r):
        k = _count(e, '0x1e0')
        e.calllog.append(('0x1e0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=al_of(_h(seed, 0x1e0, k)) & 0xff, argbytes=4)

    def s438(e, r):
        k = _count(e, '0x438')
        e.calllog.append(('0x438', e.reg('ecx')))
        e.ret(eax=al_of(_h(seed, 0x438, k)) & 0xff, argbytes=0)

    x_vt = c.emu.fake_vtable('c810-x', 0x500, {0x1e0: s1e0, 0x438: s438})
    xs = []
    for _ in range(2):
        x = _rnd(c, 0x40)
        c.emu.w32(x, x_vt)
        xs.append(x)

    def s58(e, r):
        k = _count(e, '0x58')
        e.calllog.append(('0x58', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=xs[(k + seed) % 2], argbytes=4)

    sub_vt = c.emu.fake_vtable('c810-sub', 0x100, {0x58: s58})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, sub_vt)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, sub)
    c.emu.w32(0x70039c, render)
    return [s]


S(0x5c74a0, 'core method 0x5c74a0 (unknown) stdcall one arg', 'stdcall', None, ret='al', gen=_gen, setup=_setup,
  note='core batch 810: bool result through slots 0x14, 0x4c, 0x5c, 0x58, 0x1e0 and 0x438')
