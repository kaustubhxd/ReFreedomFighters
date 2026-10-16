"""specs_s369.py - area 76, batch 369: 0x477580 (thiscall, one stack argument, ret 4, returns this; GUESS).
0x634273 (the cdecl free wrapper) runs as exe code; 0x41e2c0 (the free) is hooked: it logs its pointer and writes nothing. The three
owned pointers are random (0 or a fresh allocation); the flag argument is random (bit 0 sometimes set)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h_free(em, r):
        em.calllog.append(('free41e2c0', 0x41e2c0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    e.hook(0x41e2c0, h_free)
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    for off in (0xc, 0x10, 0x14):
        p = e.alloc(0x20, 4) if rng.random() < 0.7 else 0
        e.w32(this + off, p)
    return [this, rng.getrandbits(32)]


S(0x477580, 'dtor477580 (GUESS)', 'thiscall', None, ret='eax', gen=_gen,
  note='area 76 batch 369; lower half of label D; 0x634273 runs as exe code; 0x41e2c0 hooked')
