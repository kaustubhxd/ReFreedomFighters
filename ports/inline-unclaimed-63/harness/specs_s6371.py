"""specs_s6371.py - unclaimed-63 batch 71: 0x4a6060 (ZRequireMatPosSpeed::Init; thiscall, two stack arguments g and r, ret 8).
Fakes per case (hooks set in gen): 0x4e6180 (the reader; thiscall with the reader in ECX, one argument, ret 4; another area's code) writes a
random float bit pattern (NaN included) through its argument and records ECX and the argument; 0x4e0d00 (thiscall, one float argument,
ret 4; another area's code) records ECX and the float bits. this is random bytes; r and g are heap cells (r is only passed as ECX)."""
from pilot import S


def _gen_6060(c):
    e = c.emu
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    r = e.alloc(0x40, 4)
    e.wbytes(r, bytes(0x40))
    g = c.rng.getrandbits(32)

    def reader(em, a):
        em.calllog.append(('h.4e6180', None, em.reg('ecx'), (em.arg32(0),)))
        em.w32(em.arg32(0), c.rng.getrandbits(32))
        em.ret(eax=0, argbytes=4)

    def setf(em, a):
        em.calllog.append(('h.4e0d00', None, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x4e6180, reader)
    e.hook(0x4e0d00, setf)
    e.mu.ctl_flush_tb()
    return [this, g, r]


S(0x4a6060, 'ZRequireMatPosSpeed::Init thiscall', 'thiscall', None, ret=None, gen=_gen_6060,
  note='unclaimed-63 batch 71; 0x4e6180 and 0x4e0d00 hooked (other areas)')
