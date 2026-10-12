"""specs_s1016.py - unclaimed-07 batch 16 (slice 6): ZPlayer::Save (0x484d20).
The save object s is a logging vtable (slots +0x3c, +0x44, +0x60, +0x68, +0x70 take one argument, +0x4c takes a float's
bits). The save-ready check 0x4753c0 is hooked to a logging stub returning 0 or 1. The child objects in the 0x461 array
(count at 0x459) have a logging slot +0x34. Field values are random; the count is 0..3 and some children are null."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _save(c):
    e = c.emu
    self_o = _rnd(c, 0x800)
    e.w32(self_o + 0x459, c.rng.randint(0, 3))
    children = []
    for i in range(4):
        if c.rng.random() < 0.7:
            ch = _rnd(c, 0x40)
            e.w32(ch, e.logging_vtable('child', 0x38 // 4, impl={0x34: _const(0)}, argwords={0x34: 1}))
            children.append(ch)
        else:
            children.append(0)
    for i, ch in enumerate(children):
        e.w32(self_o + 0x461 + 4 * i, ch)

    ready = c.rng.choice([0, 1, 1, c.rng.getrandbits(32)])

    def ready_stub(em, r):
        em.calllog.append(('ready4753c0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=ready, argbytes=4)

    e.hook(0x4753c0, ready_stub)

    s = _rnd(c, 0x40)
    save_vt = e.logging_vtable('zsave', 0x80 // 4,
                               impl={0x3c: _const(0), 0x44: _const(0), 0x60: _const(0), 0x68: _const(0),
                                     0x70: _const(0), 0x4c: _const(0)},
                               argwords={0x3c: 1, 0x44: 1, 0x60: 1, 0x68: 1, 0x70: 1, 0x4c: 1})
    e.w32(s, save_vt)
    return [self_o, s]


S(0x484d20, 'ZPlayer::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-07 batch 16; hooks 0x4753c0; ~22 save slots; bool result in al, eax not compared; child loop +0x34')
