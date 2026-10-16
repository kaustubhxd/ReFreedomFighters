"""specs_s352.py - area 76, batch 353: 0x6053c0 (stdcall, one stack argument, ret 4; reads ECX).

The fixture sets ECX and EDX through ('regs', ['ecx', 'edx', 's']) so the port and the exe see the same registers.
Table 0x724770 holds four stdcall stubs (argument popped, value per stub; recorded with ECX). The count at 0x724768 is random
(0..4), so both the table call and the out-of-range tail path run. 0x5fa270 is hooked (stdcall, one argument, records ECX and
the argument, returns a per-run value). The object is 0x40 random bytes; its word at +0x10 is random."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    count = rng.choice([0, 1, 2, 3, 4])
    e.w32(0x724768, count)
    rv = [rng.getrandbits(32) for _ in range(4)]

    def stub(i):
        def h(em, r):
            em.calllog.append(('ent%d' % i, 0, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=rv[i], argbytes=4)
        return h

    for i in range(4):
        e.w32(0x724770 + 4 * i, e._new_stub('ent%d' % i, stub(i)))

    r5 = rng.getrandbits(32)

    def h5fa(em, r):
        em.calllog.append(('h5fa270', 0x5fa270, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=r5, argbytes=4)

    e.hook(0x5fa270, h5fa)

    obj = e.alloc(0x40, 4)
    e.wbytes(obj, rng.randbytes(0x40))
    e.wbytes(obj + 0x10, (rng.choice([0, 1, 2, 3, 4, 5, rng.getrandbits(16)]) & 0xffff).to_bytes(2, 'little'))
    return [rng.getrandbits(32), rng.getrandbits(32), obj]


S(0x6053c0, 'index6053c0 (GUESS)', ('regs', ['ecx', 'edx', 's']), None, ret='eax', gen=_gen,
  note='area 76 batch 353; parked row; ret 4; table stubs and 0x5fa270 hooked')
