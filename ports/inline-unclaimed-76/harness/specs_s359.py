"""specs_s359.py - area 76, batch 359: 0x55c770 (thiscall, one stack argument, ret 4; GUESS, label D).

The accessor 0x5003d0 runs as exe code. Its container C = [a+4] has C+0 = a struct S (S+0 = base array, S+8 = count), C+4 = base
offset, C+8 = count. In range it returns base + index * 8; out of range it calls the callback at 0x7003b0 (a plain stub that returns 0)
and returns the same element address. The object this has +0x1c -> a holder whose +0x945 is the store target."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def cb(em, r):
        em.calllog.append(('cb', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.w32(0x7003b0, e._new_stub('cb7003b0', cb))

    arr = e.alloc(0x100, 4)
    e.wbytes(arr, rng.randbytes(0x100))
    st = e.alloc(0x40, 4)
    e.w32(st, arr)
    e.w32(st + 8, rng.choice([16, 4, 0]))      # the struct's count: 0 takes the callback path
    C = e.alloc(0x40, 4)
    e.w32(C, st)
    e.w32(C + 4, rng.choice([0, 1, 3]))
    e.w32(C + 8, rng.choice([1, 2, 0]))       # the container's count: 0 takes the callback path
    holder = e.alloc(0x1000, 4)
    e.wbytes(holder, rng.randbytes(0x1000))
    thisobj = e.alloc(0x40, 4)
    e.w32(thisobj + 0x1c, holder)
    a = e.alloc(0x20, 4)
    e.w32(a + 4, C)
    return [thisobj, a]


S(0x55c770, 'store55c770 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='area 76 batch 359; label D; 0x5003d0 runs as exe code; callback 0x7003b0 stubbed')
