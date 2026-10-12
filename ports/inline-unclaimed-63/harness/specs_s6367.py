"""specs_s6367.py - unclaimed-63 batch 67: 0x5eb710 (ZFFActorActionThrow::Save; thiscall, one stack argument s, ret 4).
Fakes per case (the image is restored between runs): s is a save object whose vtable slots +0x64, +0x3c, +0x4c, +0x60 and +0x68 (each
thiscall, one argument, ret 4) record ECX and their argument (the float and the pointer by value or address, as the caller passes them);
the engine 0x70039c has the db at +0x9b, and db+0x44 is a random base. The actor fields (this+8, +0xc, +0x10, +0x14) are random."""
from pilot import S


def _gen_b710(c):
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

    def rec(name, off):
        def h(em, a):
            em.calllog.append((name, off, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h
    e.w32(s, e.fake_vtable('save', 0x400 // 4, {0x64: rec('s.64', 0x64), 0x3c: rec('s.3c', 0x3c), 0x4c: rec('s.4c', 0x4c),
                                                0x60: rec('s.60', 0x60), 0x68: rec('s.68', 0x68)}))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x5eb710, 'ZFFActorActionThrow::Save thiscall', 'thiscall', None, ret=None, gen=_gen_b710,
  note='unclaimed-63 batch 67')
