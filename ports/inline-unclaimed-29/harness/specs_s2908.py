"""specs_s2908.py - unclaimed-29 batch 8 (docs/20-unclaimed-29.md, claim 8, slice 8): 0x439840 (name unknown, GUESS).
this's slot +0x58 returns P (a per-case object whose first dword is a mode 0, 1 or 2). Mode 0: slot +0x10 of the object at P-4.
Mode 1: the function pointer at 0x7003b0 (a counting stub), then a walk over the list at P+0xd. The list's slots +0x4c and +0x5c
and this's slot +0x58 are fakes. No exe function is patched, so no flush is needed beyond the stub code."""
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
    import serial_stubs as ss
    # the counting function pointer (thiscall-free; the caller pushes nothing)
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0, log=False))
    # the list at P+0xd: slot +0x4c writes 1; slot +0x5c writes 1 for a counter, else 0 and returns an item
    counter = {'n': c.rng.randint(0, 2)}
    item = c.rng.getrandbits(32) | 1

    def out1(e, r):
        ptr = e.arg32(0)
        e.calllog.append(('list-4c', e.reg('ecx'), ()))
        e.w32(ptr, 1)
        e.ret(eax=0, argbytes=4)

    def next_item(e, r):
        ptr = e.arg32(0)
        more = 1 if counter['n'] > 0 else 0
        counter['n'] -= 1
        e.calllog.append(('list-5c', e.reg('ecx'), ()))
        e.w32(ptr, more)
        e.ret(eax=item, argbytes=4)
    list_vt = c.emu.fake_vtable('zlist-walk', 0x60, {0x4c: out1, 0x5c: next_item})
    lst = _rnd(c, 0x40)
    c.emu.w32(lst, list_vt)

    # P-4 holds the vtable whose slot +0x10 logs one argument
    vt_q = c.emu.logging_vtable('zq', 0x14, argwords={0x10: 1})
    block = _rnd(c, 0x40)
    c.emu.w32(block, vt_q)
    p = block + 4
    c.emu.w32(p, c.rng.choice([0, 1, 2]))
    c.emu.w32(p + 0xd, lst)

    # this: slot +0x58 (one argument) logs and returns P
    vt_self = c.emu.logging_vtable('zself', 0x60, impl={0x58: lambda e, a: (p, None)}, argwords={0x58: 1})
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_, vt_self)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x439840, 'unknown_439840 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-29 batch 8 (slice 8, no GC name); mode 0 slot +0x10 of p-4; mode 1: 0x7003b0 then list walk')
