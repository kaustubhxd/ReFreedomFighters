"""specs_s6370.py - unclaimed-63 batch 70: 0x5bd9e0 (CCheckInsideByType::Save; thiscall, one stack argument s, ret 4, returns true).
Fakes per case (the image is restored between runs): s is a save object whose vtable slots +0x44, +0x40, +0x3c and +0x60 (thiscall, one
argument, ret 4) and +0x10 (thiscall, two arguments, ret 8) record ECX and their arguments. this is random bytes (so the dword, word and
byte fields and the 0x24-byte block vary)."""
from pilot import S


def _gen_9e0(c):
    e = c.emu
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(0x40))

    def rec1(name, off):
        def h(em, a):
            em.calllog.append((name, off, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h

    def rec2(em, a):
        em.calllog.append(('s.10', 0x10, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    e.w32(s, e.fake_vtable('s', 0x400 // 4, {0x44: rec1('s.44', 0x44), 0x40: rec1('s.40', 0x40), 0x3c: rec1('s.3c', 0x3c),
                                            0x60: rec1('s.60', 0x60), 0x10: rec2}))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x5bd9e0, 'CCheckInsideByType::Save thiscall', 'thiscall', None, ret='al', gen=_gen_9e0,
  note='unclaimed-63 batch 70')
