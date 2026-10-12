"""specs_s6366.py - unclaimed-63 batch 66: 0x514600 (ZMoveOnSpline::TargetValid; stdcall-like, one stack argument idx, ret 4, bool in al).
Fakes per case (the image is restored between runs):
  * the engine 0x70039c (heap) has the db at +0x9b; the db's vtable slot +0x58 (thiscall, one argument, ret 4) returns R (zero in a
    quarter of the cases) and records its argument;
  * R's vtable: slot +0x1e0 (thiscall, one argument, ret 4) returns a random bool in al (the other bits random) and records its argument;
    slot +0x438 (thiscall, no arguments) returns a random bool in al;
  * R+8 is an object whose dword at +0x3c is random (bit 10 decides the last result).
The idx is a random dword."""
from pilot import S


def _gen_6600(c):
    e = c.emu
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(0x200))
    e.w32(0x70039c, eng)
    db = e.alloc(0x100, 4)
    e.wbytes(db, bytes(0x100))
    e.w32(eng + 0x9b, db)
    R = e.alloc(0x40, 4)
    e.wbytes(R, bytes(0x40))
    O = e.alloc(0x40, 4)
    e.wbytes(O, bytes(0x40))
    e.w32(O + 0x3c, c.rng.getrandbits(32))
    e.w32(R + 8, O)
    rv = R if c.rng.random() < 0.75 else 0
    e.w32(db, e.fake_vtable('db', 0x500 // 4, {0x58: lambda em, a: (em.calllog.append(('db.58', 0x58, em.reg('ecx'), (em.arg32(0),))),
                                                                    em.ret(eax=rv, argbytes=4))}))
    e.w32(R, e.fake_vtable('R', 0x500 // 4, {
        0x1e0: lambda em, a: (em.calllog.append(('R.1e0', 0x1e0, em.reg('ecx'), (em.arg32(0),))),
                              em.ret(eax=c.rng.getrandbits(32) & ~0xff | c.rng.choice([0, 1]), argbytes=4)),
        0x438: lambda em, a: (em.calllog.append(('R.438', 0x438, em.reg('ecx'), ())),
                              em.ret(eax=c.rng.getrandbits(32) & ~0xff | c.rng.choice([0, 1]), argbytes=0))}))
    e.mu.ctl_flush_tb()
    return [c.rng.getrandbits(32)]


S(0x514600, 'ZMoveOnSpline::TargetValid stdcall', 'stdcall', None, ret='al', gen=_gen_6600,
  note='unclaimed-63 batch 66')
