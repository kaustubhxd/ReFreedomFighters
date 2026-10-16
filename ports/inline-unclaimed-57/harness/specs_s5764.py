"""specs_s5764.py - unclaimed-57, batch 64: 0x5d8ee0 (GUESS name unnamed_5d8ee0). Thiscall, one stack argument (the archive object
ar, ret 4), returns al = 1. Hooked callees: the base helper 0x45f3c0 is a logging stub that writes nothing (it is owned by another
area); the archive object ar has a fake vtable whose slots +0x40, +0x48 and +0x50 each take one pointer argument and write a fixed
dword through it. The slot log holds the slot offset only, never the pointer (it differs between runs), so the field each call
writes is checked through the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ar(c):
    e = c.emu
    vals = {off: c.rng.getrandbits(32) for off in (0x40, 0x48, 0x50)}

    def slot(off):
        def h(em, r):
            em.calllog.append(('ar', off, None, ()))
            em.w32(em.arg32(0), vals[off])
            em.ret(eax=0, argbytes=4)
        return h
    e.hook(0x45f3c0, lambda em, r: (em.calllog.append(('base45f3c0', 0, None, ())), em.ret(eax=0, argbytes=4)))
    vt = e.fake_vtable('d8ee0_ar', 160, {0x40: slot(0x40), 0x48: slot(0x48), 0x50: slot(0x50)})
    ar = _rnd(c, 0x80)
    e.w32(ar, vt)
    self_obj = _rnd(c, 0x100)
    return [self_obj, ar]


S(0x5d8ee0, 'unnamed_5d8ee0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_ar,
  note='unclaimed-57 batch 64; base 0x45f3c0 hooked (logs, writes nothing); ar slots +0x40, +0x48, +0x50 fake (write fixed dwords)')
