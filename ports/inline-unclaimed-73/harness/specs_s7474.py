"""specs_s7474.py - area 73 batch 74 (tail-jump row, zero arguments from the call site 0x4edf7e: no pushes before the call).
FUN_4f43d0: vtable word 0x699664; a non-null pointer at +0xac is deleted (cdecl 0x634273(ptr, 1)); then tail-jump to 0x4ee440
with the same zero arguments (hooked by address, zero arguments)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h_del(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)

    def h_4ee440(em, r):
        em.calllog.append(('4ee440', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)
    e.hook(0x634273, h_del)
    e.hook(0x4ee440, h_4ee440)
    o = _rnd(c, 0x100)
    e.w32(o + 0xac, _rnd(c, 0x20) if c.rng.random() < 0.6 else 0)
    return [o]


S(0x4f43d0, 'GUESS FUN_4f43d0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 74; zero args (call site 0x4edf7e); vt=0x699664; [+0xac] delete(ptr,1); jmp 0x4ee440 (hooked)')
