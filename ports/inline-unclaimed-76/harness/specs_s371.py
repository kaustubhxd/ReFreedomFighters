"""specs_s371.py - area 76, residue 18, batch 371: 0x660ce0 and 0x6043a0 (thiscall, no arguments, return eax; GUESS). Fixture:
0x660ce0: this+0x18 -> object whose vtable slot 0x14 (thiscall, no arguments) returns a per-run value (logged); the object is
random or null. 0x6043a0: the global 0x724278 -> a holder whose +0x3c -> an object whose vtable slot 8 (thiscall, one word) returns a
per-run value (logged); this+0x24 is a random word."""
from pilot import S


def _gen_660(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def h14(em, r):
        em.calllog.append(('o14', 0x14, em.reg('ecx'), ()))
        em.ret(eax=rv, argbytes=0)

    vt = e.fake_vtable('o660', 0x20 // 4 * 4, {0x14: h14})
    o = e.alloc(0x40, 4)
    e.w32(o, vt)
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    e.w32(this + 0x18, o if rng.random() < 0.8 else 0)
    return [this]


def _gen_6043(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def h8(em, r):
        em.calllog.append(('x8', 8, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)

    vt = e.fake_vtable('x6043', 0x20 // 4 * 4, {8: h8})
    x = e.alloc(0x40, 4)
    e.w32(x, vt)
    holder = e.alloc(0x40, 4)
    e.w32(holder + 0x3c, x)
    e.w32(0x724278, holder)
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    e.wbytes(this + 0x24, rng.getrandbits(16).to_bytes(2, 'little'))
    return [this]


S(0x660ce0, 'get660ce0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_660,
  note='area 76 batch 371; residue 18; vtable slot 0x14 stubbed')
S(0x6043a0, 'get6043a0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_6043,
  note='area 76 batch 371; residue 18; vtable slot 8 stubbed')
