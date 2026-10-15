"""specs_s821.py - core batch 821 (docs/20-unclaimed-65.md). 0x4fbd50: thiscall, no arguments, returns bool in al.
The render sub-object's slot 0x58 (one argument) returns object A (first call) and object B (second call), or zero, chosen per case.
A's slot 0x84 (one pointer argument, callee pops) writes three random floats through the pointer; B's slot 0x8c (one pointer argument)
logs the three floats; B's slot 0x180 (pointer and float -10.0f, callee pops) logs them and returns al, chosen per case. The exe's cookie
check 0x633654 is stubbed to a return (as in the other batches). The vtables and the pointers are random per case."""
import os, struct, sys
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
    # the cookie stub keeps eax: the function's bool result is in al when it runs the check
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=e.reg('eax'), argbytes=0)))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    fl = tuple(struct.unpack('<f', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0] for _ in range(3))
    al180 = c.rng.choice([0, 1, 0x100, 0x1234])
    got = {}

    def s84(e, r):
        p = e.arg32(0)
        e.calllog.append(('0x84', e.reg('ecx')))
        e.wbytes(p, struct.pack('<fff', *fl))
        e.ret(eax=0, argbytes=4)

    def s8c(e, r):
        p = e.arg32(0)
        e.calllog.append(('0x8c', e.reg('ecx'), e.rbytes(p, 12)))
        e.ret(eax=0, argbytes=4)

    def s180(e, r):
        p = e.arg32(0)
        e.calllog.append(('0x180', e.reg('ecx'), e.rbytes(p, 12), e.arg32(1)))
        e.ret(eax=al180, argbytes=8)

    o_vt = c.emu.fake_vtable('c821-o', 0x200, {0x84: s84, 0x8c: s8c, 0x180: s180})
    a = _rnd(c, 0x40)
    c.emu.w32(a, o_vt)
    b = _rnd(c, 0x40)
    c.emu.w32(b, o_vt)
    ok_a = c.rng.random() < 0.85
    ok_b = c.rng.random() < 0.85

    def s58(e, r):
        k = sum(1 for x in e.calllog if x[0] == '0x58')
        e.calllog.append(('0x58', e.reg('ecx'), e.arg32(0)))
        if k == 0:
            e.ret(eax=a if ok_a else 0, argbytes=4)
        else:
            e.ret(eax=b if ok_b else 0, argbytes=4)

    r9_vt = c.emu.fake_vtable('c821-r9', 0x100, {0x58: s58})
    r9 = _rnd(c, 0x100)
    c.emu.w32(r9, r9_vt)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    self_ = _rnd(c, 0x100)
    return [self_]


S(0x4fbd50, 'core method 0x4fbd50 (unknown) thiscall no args', 'thiscall', None, ret='al', gen=_gen, setup=_setup,
  note='core batch 821: two slot-0x58 objects, slot 0x84 floats, slot 0x8c and slot 0x180 with -10.0f')
