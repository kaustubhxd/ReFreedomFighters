"""specs_s827.py - core batch 827 (docs/20-unclaimed-65.md). 0x49f210: thiscall, one stack argument (the save object s), ret 4, returns al = 1.
The object s has slots 0x40 (one word argument, logged), 0x4c (one float argument, logged by its bytes), and 0x3c (one dword argument, logged).
Each callee pops its argument. The float at +0x4c is random; the words and the dword are random."""
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


def _gen(c):
    s_vt = c.emu.fake_vtable('c827-s', 0x100, {
        0x40: lambda e, r: (e.calllog.append(('0x40', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))[-1],
        0x4c: lambda e, r: (e.calllog.append(('0x4c', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))[-1],
        0x3c: lambda e, r: (e.calllog.append(('0x3c', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))[-1]})
    s = _rnd(c, 0x40)
    c.emu.w32(s, s_vt)
    this = _rnd(c, 0x100)
    return [this, s]


S(0x49f210, 'CMsgForwardToActors::Save (unknown) thiscall one arg', 'thiscall', None, ret='al', gen=_gen,
  note='core batch 827: four slot calls on the save object, returns 1')
