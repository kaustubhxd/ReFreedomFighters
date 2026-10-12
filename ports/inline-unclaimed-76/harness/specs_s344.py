"""specs_s344.py - gap band, batch 344: 0x60f1a0 (thiscall, two arguments). The engine global 0x70039c is a random block (flag byte at +0x63,
values at +0x6f and +0x73). The object's vtable: slot 0x50 (thiscall, no arguments, recorded) and slot 0xe0 (thiscall, two arguments,
recorded, returns a per-run value)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def s50(em, r):
        em.calllog.append(('s50', 0x50, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def se0(em, r):
        em.calllog.append(('se0', 0xe0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=rv, argbytes=8)

    eng = e.alloc(0x200, 4)
    e.wbytes(eng, rng.randbytes(0x200))
    e.wbytes(eng + 0x63, bytes([rng.choice([0, 1])]))
    e.w32(0x70039c, eng)
    self_ = e.alloc(0x1400, 4)
    e.wbytes(self_, rng.randbytes(0x1400))
    e.w32(self_, e.fake_vtable('obj344', 0x100, {0x50: s50, 0xe0: se0}))
    e.wbytes(self_ + 0x33, bytes([rng.choice([0, 1])]))
    return [self_, rng.getrandbits(32), rng.getrandbits(32)]


S(0x60f1a0, 'pick60f1a0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen, note='batch344; ret 8; slots 0x50 and 0xe0 stubbed')
