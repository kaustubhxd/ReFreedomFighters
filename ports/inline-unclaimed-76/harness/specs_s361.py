"""specs_s361.py - area 76, batch 361 (and 362 via SLOT): 0x55c7a0 (thiscall, one stack argument, ret 4, returns eax; GUESS, label D).
The element accessor 0x5003d0 runs as exe code (struct at [C], as in batch 359). The holder at this+0x1c is a fake object whose vtable
slot (0x6ac here) is a thiscall stub with one argument that returns a per-run value and logs (holder, word)."""
import struct
from pilot import S

SLOT = 0x6ac
NAME = 'store55c7a0'


def make_gen(slot, name):
    def _gen(c):
        e = c.emu
        rng = c.rng
        cb_v = rng.getrandbits(32)

        def cb(em, r):
            em.calllog.append(('cb', 0, None, ()))
            em.ret(eax=0, argbytes=0)

        e.w32(0x7003b0, e._new_stub('cb7003b0', cb))

        ret_v = rng.getrandbits(32)

        def slot_h(em, r):
            em.calllog.append(('slot', slot, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=ret_v, argbytes=4)

        vt = e.fake_vtable('holder', 0x6b0 // 4, {slot: slot_h})
        holder = e.alloc(0x40, 4)
        e.w32(holder, vt)

        arr = e.alloc(0x100, 4)
        e.wbytes(arr, rng.randbytes(0x100))
        e.w32(arr, rng.choice([0, 0x1234, 0xffff0000]))
        st = e.alloc(0x40, 4)
        e.w32(st, arr)
        e.w32(st + 8, rng.choice([16, 4, 0]))
        C = e.alloc(0x40, 4)
        e.w32(C, st)
        e.w32(C + 4, rng.choice([0, 1, 3]))
        e.w32(C + 8, rng.choice([1, 2, 0]))
        thisobj = e.alloc(0x40, 4)
        e.w32(thisobj + 0x1c, holder)
        a = e.alloc(0x20, 4)
        e.w32(a + 4, C)
        return [thisobj, a]
    return _gen


S(0x55c7a0, NAME + ' (GUESS)', 'thiscall', None, ret='eax', gen=make_gen(SLOT, NAME),
  note='area 76 batch 361; label D; 0x5003d0 runs as exe code; holder slot 0x6ac stubbed')
