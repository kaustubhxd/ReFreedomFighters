"""specs_s340.py - gap band, batch 340: 0x61ab20 (fastcall: idx in ECX, value in EDX, one stack argument; ret 4). The two dword tables at
0x724970 and 0x7249b0 are globals (indices 0..7). The global object at 0x724a00 has a vtable whose slot 0x14c is a thiscall stub with four
arguments (recorded). The stored values are random: some calls find the same values (no store, no call)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    rv_unused = 0

    def slot14c(em, r):
        a = [em.arg32(k) for k in range(4)]
        em.calllog.append(('slot14c', 0x14c, em.reg('ecx'), tuple(a)))
        em.ret(eax=0, argbytes=16)

    obj = e.alloc(0x40, 4)
    e.w32(obj, e.fake_vtable('obj340', 0x200, {0x14c: slot14c}))
    e.w32(0x724a00, obj)
    t1 = [rng.getrandbits(32) for _ in range(8)]
    t2 = [rng.getrandbits(32) for _ in range(8)]
    for i in range(8):
        e.w32(0x724970 + 4 * i, t1[i])
        e.w32(0x7249b0 + 4 * i, t2[i])
    idx = rng.randrange(0, 8)
    value = t1[idx] if rng.random() < 0.3 else rng.getrandbits(32)
    arg = t2[idx] if rng.random() < 0.3 else rng.getrandbits(32)
    return [idx, value, arg]


S(0x61ab20, 'set61ab20 (GUESS)', 'fastcall', None, ret=None, gen=_gen, note='batch340; ret 4; slot 0x14c stubbed')
