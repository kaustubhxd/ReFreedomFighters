"""specs_s6507.py - unclaimed-65 batch 7 (docs/20-unclaimed-65.md, claim 7): GUESS FUN_4c35e0. The list at this+0x48 (null in 20%)
has slot +0x4c (writes 1), +0x5c (writes the out flag from a counter, returns an item) and +0x44 (logs). The render object
(global 0x70039c, +0x9b) has slot +0x58 (returns r, zero in a third of cases). r has slot +0x10c (two args, returns s); s has slot
+0x5c (three args) and +0x84 (two args), both logging. The callees use the stack-pop convention of the original (no add esp)."""
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
    items = [c.rng.getrandbits(32) | 1 for _ in range(n_items)]
    counter = {'i': 0, 'n': n_items}

    # s: slot +0x5c takes three stack arguments, slot +0x84 two; both pop their own arguments (ret 0xc / 0x8)
    s_vt = c.emu.logging_vtable('fn-s', 0x90, argwords={0x5c: 3, 0x84: 2})
    s = _rnd(c, 0x40)
    c.emu.w32(s, s_vt)
    # r: slot +0x10c takes two stack arguments and returns s
    r_vt = c.emu.logging_vtable('fn-r', 0x110, impl={0x10c: lambda e, a: (s, None)}, argwords={0x10c: 2})
    r = _rnd(c, 0x40)
    c.emu.w32(r, r_vt)
    # R (render object): slot +0x58 takes one argument and returns r (zero in a third of cases)
    rv = 0 if c.rng.random() < 0.33 else r
    R_vt = c.emu.logging_vtable('fn-render', 0x60, impl={0x58: lambda e, a: (rv, None)}, argwords={0x58: 1})
    R = _rnd(c, 0x40)
    c.emu.w32(R, R_vt)
    rr = _rnd(c, 0x200)
    c.emu.w32(rr + 0x9b, R)
    c.emu.w32(0x70039c, rr)

    def out1(e, r_):
        ptr = e.arg32(0)
        e.calllog.append(('list-4c', e.reg('ecx'), ()))
        e.w32(ptr, 1)
        e.ret(eax=0, argbytes=4)

    def next_item(e, r_):
        ptr = e.arg32(0)
        more = 1 if counter['i'] + 1 < counter['n'] else 0
        item = items[counter['i'] % len(items)]
        counter['i'] += 1
        e.calllog.append(('list-5c', e.reg('ecx'), ()))
        e.w32(ptr, more)
        e.ret(eax=item, argbytes=4)

    def list44(e, r_):
        ptr = e.arg32(0)
        e.calllog.append(('list-44', e.reg('ecx'), ()))
        e.w32(ptr, 0)
        e.ret(eax=0, argbytes=4)
    list_vt = c.emu.fake_vtable('fn-list', 0x60, {0x4c: out1, 0x5c: next_item, 0x44: list44})
    lst = _rnd(c, 0x40)
    c.emu.w32(lst, list_vt)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x48, 0 if c.rng.random() < 0.2 else lst)
    c.emu.w32(self_ + 0x44, c.rng.getrandbits(32))
    return [self_]


S(0x4c35e0, 'GUESS FUN_4c35e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-65 batch 7 (residue 18, GUESS name); list walk with render +0x58, s +0x10c/+0x5c/+0x84')
