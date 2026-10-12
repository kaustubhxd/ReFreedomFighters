"""specs_s341.py - gap band, batch 341: 0x60cdf0 (stdcall, one byte argument, bool result). Globals: 0x724940 (old flag), 0x724930 (last
state), 0x724a00 (an object whose vtable slot 0xc8 is a thiscall stub with three arguments, recorded). The byte argument is random:
zero or nonzero, with the flags chosen to hit each branch."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def slotc8(em, r):
        a = [em.arg32(k) for k in range(3)]
        em.calllog.append(('slotc8', 0xc8, em.reg('ecx'), tuple(a)))
        em.ret(eax=0, argbytes=12)

    obj = e.alloc(0x40, 4)
    e.w32(obj, e.fake_vtable('obj341', 0x100, {0xc8: slotc8}))
    e.w32(0x724a00, obj)
    e.w32(0x724940, rng.choice([0, 0, 1, rng.getrandbits(32)]))
    e.w32(0x724930, rng.choice([0, 1, 2]))
    return [rng.choice([0, 0, 1, 0x100, rng.getrandbits(8)]) | (rng.getrandbits(24) << 8)]


S(0x60cdf0, 'flag60cdf0 (GUESS)', 'stdcall', None, ret='al', gen=_gen, note='batch341; ret 4; slot 0xc8 stubbed')
