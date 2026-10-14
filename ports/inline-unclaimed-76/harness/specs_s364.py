"""specs_s364.py - area 76, batch 364: 0x5589e0 (thiscall, one stack argument, ret 4; GUESS, label D).
The holder (this+0x1c) is random memory with the count at +0x7ce in 0..3 (0x59e650 walks it, exe code). The container is a struct as in
batch 359 with the element's first dword random; 0x5003d0 and 0x59e650 run as exe code."""
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
    e.w32(st + 8, rng.choice([16, 4, 0]))
    C = e.alloc(0x40, 4)
    e.w32(C, st)
    e.w32(C + 4, 0)
    e.w32(C + 8, rng.choice([1, 2, 0]))
    holder = e.alloc(0x1000, 4)
    e.wbytes(holder, rng.randbytes(0x1000))
    cnt = rng.choice([1, 2, 3])
    e.w32(holder + 0x7ce, cnt)
    entries = [rng.getrandbits(32) for _ in range(4)]
    for k in range(4):
        e.w32(holder + 0x7c2 + 16 * k, entries[k])
    e.w32(arr, entries[rng.randrange(4)] if rng.random() < 0.5 else rng.getrandbits(32))   # the value often matches an entry
    thisobj = e.alloc(0x40, 4)
    e.w32(thisobj + 0x1c, holder)
    a = e.alloc(0x20, 4)
    e.w32(a + 4, C)
    return [thisobj, a]


S(0x5589e0, 'store5589e0 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='area 76 batch 364; label D; 0x5003d0 and 0x59e650 run as exe code')
