"""specs_s5782.py - unclaimed-57, batch 82: 0x5d4020 (GUESS name unnamed_5d4020). Thiscall, one stack argument a (ret 4), returns al = 1.
The argument a has a fake vtable: slots +0x44 and +0x3c each take one dword value (logged with the slot offset and a tag for ECX = a).
The dwords come from the self object's fields at +0x80, +0x58, +0x5c, +0x60, +0x64, +0x68, +0x6c, +0x70, +0x74 (random values)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4020(c):
    e = c.emu
    a_obj = _rnd(c, 0x40)

    def slot(off):
        def h(em, r):
            tag = 'A' if em.reg('ecx') == a_obj else 'other'
            em.calllog.append(('a', off, tag, (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h

    vt_a = e.fake_vtable('d4020_a', 160, {0x44: slot(0x44), 0x3c: slot(0x3c)})
    e.w32(a_obj, vt_a)
    self_obj = _rnd(c, 0x100)
    return [self_obj, a_obj]


S(0x5d4020, 'unnamed_5d4020 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_d4020,
  note='unclaimed-57 batch 82; argument object fake slots +0x44 and +0x3c log the dword values')
