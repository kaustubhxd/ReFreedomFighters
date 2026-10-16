"""specs_s367.py - area 76, batch 367: 0x55b260 (thiscall, one stack argument, ret 4; GUESS, label D).
0x5003d0 runs as exe code (struct container as in batch 359). 0x5a20d0 (a formatter with an SEH frame) and 0x5a0da0 are hooked by
address: each logs ECX and its arguments and writes nothing; 0x5a20d0 pops its two words, 0x5a0da0 pops none. The holder is random."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h20(em, r):
        em.calllog.append(('h5a20d0', 0x5a20d0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h0d(em, r):
        em.calllog.append(('h5a0da0', 0x5a0da0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x5a20d0, h20)
    e.hook(0x5a0da0, h0d)

    cb_addr = e._new_stub('cb7003b0', lambda em, r: (em.calllog.append(('cb', 0, None, ())), em.ret(eax=0, argbytes=0)))
    e.w32(0x7003b0, cb_addr)
    arr = e.alloc(0x100, 4)
    e.wbytes(arr, rng.randbytes(0x100))
    st = e.alloc(0x40, 4)
    e.w32(st, arr)
    e.w32(st + 8, rng.choice([16, 4, 0]))
    C = e.alloc(0x40, 4)
    e.w32(C, st)
    e.w32(C + 4, 0)
    e.w32(C + 8, rng.choice([1, 2, 0]))
    holder = e.alloc(0x1000, 4)
    e.wbytes(holder, rng.randbytes(0x1000))
    thisobj = e.alloc(0x40, 4)
    e.w32(thisobj + 0x1c, holder)
    a = e.alloc(0x20, 4)
    e.w32(a + 4, C)
    return [thisobj, a]


S(0x55b260, 'store55b260 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='area 76 batch 367; label D; 0x5a20d0 and 0x5a0da0 hooked')
