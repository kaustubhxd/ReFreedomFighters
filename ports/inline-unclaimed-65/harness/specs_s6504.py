"""specs_s6504.py - unclaimed-65 batch 4 (docs/20-unclaimed-65.md, claim 4): ZInputActions::GetActionMap. The list at this+0x1214
has slot +0x4c (writes 1) and slot +0x5c (writes the out flag from a per-case counter and returns the next item). Items are fakes
whose dword +0x15 is compared with the argument (the argument equals one item's value in half of the cases)."""
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
    n_items = c.rng.randint(1, 3)
    items = []
    for _ in range(n_items):
        it = _rnd(c, 0x40)
        c.emu.w32(it + 0x15, c.rng.getrandbits(32))
        items.append(it)
    counter = {'i': 0, 'n': n_items}

    def out1(e, r):
        ptr = e.arg32(0)
        e.calllog.append(('list-4c', e.reg('ecx'), ()))
        e.w32(ptr, 1)
        e.ret(eax=0, argbytes=4)

    def next_item(e, r):
        ptr = e.arg32(0)
        i = counter['i']
        counter['i'] += 1
        more = 1 if counter['i'] < counter['n'] else 0
        e.calllog.append(('list-5c', e.reg('ecx'), ()))
        e.w32(ptr, more)
        e.ret(eax=items[i % len(items)], argbytes=4)
    list_vt = c.emu.fake_vtable('actionmap-list', 0x60, {0x4c: out1, 0x5c: next_item})
    lst = _rnd(c, 0x40)
    c.emu.w32(lst, list_vt)
    self_ = _rnd(c, 0x1300)
    c.emu.w32(self_ + 0x1214, 0 if c.rng.random() < 0.2 else lst)   # null list in 20% of cases
    if c.rng.random() < 0.5:
        arg = c.emu.r32(items[c.rng.randrange(n_items)] + 0x15)
    else:
        arg = c.rng.getrandbits(32)
    return [self_, arg]


S(0x438c60, 'ZInputActions::GetActionMap (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-65 batch 4 (residue 18); list at +0x1214; returns the item whose dword +0x15 equals the argument, else 0')
