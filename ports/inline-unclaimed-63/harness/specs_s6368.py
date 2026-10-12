"""specs_s6368.py - unclaimed-63 batch 68: 0x4c36d0 (ZWindControl::Save; thiscall, one stack argument s, ret 4, returns true in al).
Fakes per case (the image is restored between runs):
  * s: vtable slot +0x6c (thiscall, one argument, ret 4) records its argument; slot +0x4c (thiscall, one float argument, ret 4) records
    the float bits and returns the next sub-object (the first call returns S1, the second S2);
  * S1 and S2: vtable slot +0x4c (thiscall, one float argument, ret 4) records the float bits; both are heap objects;
  * this: its +0x48 (dword) and +0x4c, +0x50, +0x54, +0x5c (floats) are random bit patterns (NaN included), and +4 is random.
The checker compares the call log (the float bits) and the flag store at this+4."""
from pilot import S


def _gen_36d0(c):
    e = c.emu
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    S1 = e.alloc(0x40, 4)
    e.wbytes(S1, bytes(0x40))
    S2 = e.alloc(0x40, 4)
    e.wbytes(S2, bytes(0x40))

    def sub(name):
        def h(em, a):
            em.calllog.append((name, 0x4c, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h
    e.w32(S1, e.fake_vtable('S1', 0x400 // 4, {0x4c: sub('S1.4c')}))
    e.w32(S2, e.fake_vtable('S2', 0x400 // 4, {0x4c: sub('S2.4c')}))
    count = [0]

    def slot4c(em, a):
        em.calllog.append(('s.4c', 0x4c, em.reg('ecx'), (em.arg32(0),)))
        ret = S1 if count[0] == 0 else S2
        count[0] += 1
        em.ret(eax=ret, argbytes=4)

    def slot6c(em, a):
        em.calllog.append(('s.6c', 0x6c, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(0x40))
    e.w32(s, e.fake_vtable('s', 0x400 // 4, {0x4c: slot4c, 0x6c: slot6c}))
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x4c36d0, 'ZWindControl::Save thiscall', 'thiscall', None, ret='al', gen=_gen_36d0,
  note='unclaimed-63 batch 68')
