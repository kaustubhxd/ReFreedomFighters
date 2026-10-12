"""specs_s6374.py - unclaimed-63 batch 74: 0x5eb680 (ZFFActorActionCloseCombat::Save; thiscall, one stack argument s, ret 4, no result).
Fakes per case (the image is restored between runs): s is a save object whose vtable slots +0x64, +0x3c, +0x44, +0x60 (thiscall, one
argument, ret 4), +0x4c (one float argument, ret 4) and +0x10 (thiscall, two arguments, ret 8) record ECX and their arguments; the engine
0x70039c has the db at +0x9b, and db+0x44 is a random base. The actor fields are random bytes (floats NaN included)."""
from pilot import S


def _gen_b680(c):
    e = c.emu
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(0x200))
    e.w32(0x70039c, eng)
    db = e.alloc(0x100, 4)
    e.wbytes(db, bytes(0x100))
    e.w32(db + 0x44, c.rng.getrandbits(32))
    e.w32(eng + 0x9b, db)
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
    e.w32(s, e.fake_vtable('save', 0x400 // 4, {0x64: rec1('s.64', 0x64), 0x3c: rec1('s.3c', 0x3c), 0x44: rec1('s.44', 0x44),
                                               0x4c: rec1('s.4c', 0x4c), 0x60: rec1('s.60', 0x60), 0x10: rec2}))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x5eb680, 'ZFFActorActionCloseCombat::Save thiscall', 'thiscall', None, ret=None, gen=_gen_b680,
  note='unclaimed-63 batch 74')
