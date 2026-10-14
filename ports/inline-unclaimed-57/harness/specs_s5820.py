"""specs_s5820.py - unclaimed-57, batch 120: 0x5dbc20 (ZFireDamageBox::Load(ZLoadGame*), a vtable thunk). Thiscall, one stack argument (ret 4), returns al = 1.
The thunk clears bit 0x40 of this+4 and calls 0x5dbc30 (area 63's batch 6356, thiscall with no arguments), which is a logging stub here (it writes nothing).
The field this+4 is random, so the bit clear is checked by the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    e = c.emu

    def h(em, r):
        em.calllog.append(('5dbc30', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5dbc30, h)
    load = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, load]


S(0x5dbc20, 'ZFireDamageBox::Load (GUESS thunk) thiscall', 'thiscall', None, ret='al', gen=_f,
  note='unclaimed-57 batch 120; thunk to 0x5dbc30 (area 63, batch 6356), callee hooked (logs ECX)')
