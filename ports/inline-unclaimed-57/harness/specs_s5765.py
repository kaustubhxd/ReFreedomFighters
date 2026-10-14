"""specs_s5765.py - unclaimed-57, batch 65: 0x5d8f40 (GUESS name unnamed_5d8f40). Thiscall, one stack argument (the archive object
ar, ret 4), returns al = 1. Hooked callees: the base helper 0x45f960 is a logging stub that writes nothing (owned by another area);
the archive object ar has a fake vtable whose slots +0x3c, +0x44 take one dword value and +0x4c takes one float. Every slot logs the
argument bit pattern it received (the values come from the object's own fields, so they are stable across runs)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ar(c):
    e = c.emu

    def slot(off):
        def h(em, r):
            em.calllog.append(('ar', off, None, (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h
    e.hook(0x45f960, lambda em, r: (em.calllog.append(('base45f960', 0, None, ())), em.ret(eax=0, argbytes=4)))
    vt = e.fake_vtable('d8f40_ar', 160, {0x3c: slot(0x3c), 0x44: slot(0x44), 0x4c: slot(0x4c)})
    ar = _rnd(c, 0x80)
    e.w32(ar, vt)
    self_obj = _rnd(c, 0x100)
    return [self_obj, ar]


S(0x5d8f40, 'unnamed_5d8f40 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_ar,
  note='unclaimed-57 batch 65; base 0x45f960 hooked (logs, writes nothing); ar slots +0x3c, +0x44, +0x4c fake (log the argument bits)')
