"""specs_s6355.py - unclaimed-63 core residue 2, batch 55: 0x584aa0 (CExplode::PlaySound_Explode; thiscall, two stack arguments p1 and
p2 after a1, ret 0xc, and a float multiply through the x87 stack).
Fakes per case (the image is restored between runs):
  * 0x43ec00 (six stack arguments, ret 0x18; another area's code): a hook that records its arguments and returns a random object;
  * the engine 0x70039c (heap): +0x9b is the db, whose vtable slot +0x60 (thiscall, one argument) returns the object S, or 0 in a quarter
    of the cases; the engine's vtable slot +0x1c0 (thiscall, two arguments, ret 8) records ECX and its arguments;
  * S is a heap block whose +0x40, +0x60, +0x64, +0x84 are random;
  * this: +0x4a dword, +0x4e word (any 16-bit value, negative included), +0x50 byte (zero in half the cases).
The x87 stack is set by the 0x43ec00 hook (its return leaves a float in st0, which the function's multiply uses): the harness starts
the stack empty, so without this the multiply would not depend on the value at +0x4e."""
from pilot import S


def _gen_584a(c):
    e = c.emu
    eng = e.alloc(0x2000, 4)
    e.wbytes(eng, bytes(0x2000))
    e.w32(0x70039c, eng)
    db = e.alloc(0x100, 4)
    e.wbytes(db, bytes(0x100))
    e.w32(eng + 0x9b, db)
    Sobj = e.alloc(0x100, 4)
    e.wbytes(Sobj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    s_present = c.rng.random() < 0.75
    vtdb = e.fake_vtable('db', 0x400 // 4, {0x60: lambda em, a: (em.calllog.append(('db.60', 0x60, em.reg('ecx'), (em.arg32(0),))),
                                                                  em.ret(eax=Sobj if s_present else 0, argbytes=4))})
    e.w32(db, vtdb)
    vteng = e.fake_vtable('eng', 0x800 // 4, {0x1c0: lambda em, a: (em.calllog.append(('eng.1c0', 0x1c0, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                                                     em.ret(eax=0, argbytes=8))})
    e.w32(eng, vteng)

    st0v = c.rng.choice([1.0, -2.5, 0.0, 3.0e3, float('nan')]) if c.rng.random() < 0.3 else \
        __import__('struct').unpack('<f', c.rng.getrandbits(32).to_bytes(4, 'little'))[0]

    def hook43(em, a):
        em.calllog.append(('h.43ec00', None, em.reg('ecx'), tuple(em.arg32(k) for k in range(6))))
        # the hook leaves a float on the x87 stack (st0), which the function's multiply then uses
        em.ret(eax=0, argbytes=0x18, st0=st0v)
    e.hook(0x43ec00, hook43)
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    e.wbytes(this + 0x50, bytes([0 if c.rng.random() < 0.5 else 1]))
    a1 = e.alloc(0x40, 4)
    e.wbytes(a1, bytes(0x40))
    e.mu.ctl_flush_tb()
    p1 = c.rng.getrandbits(32)
    p2 = c.rng.getrandbits(32)
    return [this, a1, p1, p2]


S(0x584aa0, 'CExplode::PlaySound_Explode thiscall', 'thiscall', None, ret=None, gen=_gen_584a,
  note='unclaimed-63 core residue 2 batch 55; 0x43ec00 hooked (other areas)')
