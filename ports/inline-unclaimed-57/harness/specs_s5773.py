"""specs_s5773.py - unclaimed-57, batch 73: 0x5c33a0 (GUESS name unnamed_5c33a0). Thiscall, one stack argument a (ret 4), returns al = 1.
The argument a is a fake object with a vtable whose slots +0x50 and +0x68 each take one pointer into this. Each slot logs the offset
of its pointer from this (a tag if it points elsewhere), and writes a fixed dword through the pointer (so a wrong pointer shows in the
heap comparison). ECX is logged as a tag: it is the object a."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c33a0(c):
    e = c.emu
    self_obj = _rnd(c, 0x200)
    a_obj = _rnd(c, 0x40)
    vals = {0x50: c.rng.getrandbits(32), 0x68: c.rng.getrandbits(32)}

    def slot(off):
        def h(em, r):
            p = em.arg32(0)
            rel = p - self_obj if self_obj <= p < self_obj + 0x200 else 'other'
            tag = 'A' if em.reg('ecx') == a_obj else 'other'
            em.calllog.append(('a', off, tag, (rel,)))
            em.w32(p, vals[off])
            em.ret(eax=0, argbytes=4)
        return h

    vt_a = e.fake_vtable('c33a0_a', 160, {0x50: slot(0x50), 0x68: slot(0x68)})
    e.w32(a_obj, vt_a)
    e.w32(self_obj + 4, c.rng.getrandbits(32))
    return [self_obj, a_obj]


S(0x5c33a0, 'unnamed_5c33a0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_c33a0,
  note='unclaimed-57 batch 73; argument object fake slots +0x50 and +0x68 (log the pointer offset, write fixed dwords)')
