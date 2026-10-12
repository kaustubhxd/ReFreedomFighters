"""specs_s6359.py - unclaimed-63 batch 59: 0x5b1f40 (ZKillBox::Load; thiscall, one stack argument L, ret 4, returns true in al).
Fakes per case (the image is restored between runs; hooks set in gen):
  * L: a heap object whose vtable slot +0x40 (thiscall, one argument, ret 4) records ECX and writes a random dword through its
    argument (the caller's stack slot, so only its content is recorded);
  * the engine 0x70039c (heap) has the db at +0x9b; db's vtable slot +0x58 (thiscall, one argument, ret 4) records its argument and
    returns a random dword;
  * this: +0x4 random (so the bit 0x40 test is visible), +0x4a stored result.
L is a non-null object in every case; the flag bit 0x40 is set in half the cases."""
from pilot import S


def _gen_1f40(c):
    e = c.emu
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(0x200))
    e.w32(0x70039c, eng)
    db = e.alloc(0x100, 4)
    e.wbytes(db, bytes(0x100))
    e.w32(eng + 0x9b, db)
    e.w32(db, e.fake_vtable('db', 0x400 // 4, {0x58: lambda em, a: (em.calllog.append(('db.58', 0x58, em.reg('ecx'), (em.arg32(0),))),
                                                                    em.ret(eax=c.rng.getrandbits(32), argbytes=4))}))

    def write_out(em, a):
        em.calllog.append(('L.40', 0x40, em.reg('ecx'), ()))
        em.w32(em.arg32(0), c.rng.getrandbits(32))
        em.ret(eax=0, argbytes=4)
    L = e.alloc(0x40, 4)
    e.wbytes(L, bytes(0x40))
    e.w32(L, e.fake_vtable('L', 0x400 // 4, {0x40: write_out}))
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    if c.rng.random() < 0.5:
        e.w32(this + 4, e.r32(this + 4) | 0x40)
    e.mu.ctl_flush_tb()
    return [this, L]


S(0x5b1f40, 'ZKillBox::Load thiscall', 'thiscall', None, ret='al', gen=_gen_1f40,
  note='unclaimed-63 batch 59')
