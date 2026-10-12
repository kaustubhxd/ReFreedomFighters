"""specs_s6356.py - unclaimed-63 batch 56: 0x5dbc30 (the body behind the Load thunk 0x5dbc20; thiscall, no arguments, plain ret).
The SEH-style cookie check at the end is not reproduced (tagged); the spec hooks 0x633654 as a no-op for both sides.
Fakes per case (the image is restored between runs; hooks set in gen):
  * this+0x44 is object A; A's vtable slot +0x80 (thiscall, two arguments, ret 8) writes 12 random bytes through each argument
    (the two local blocks) and records its arguments;
  * A+8 is object B; 0x4daf90 and 0x4db7c0 (thiscall, one argument, ret 4) write 12 random bytes through their argument and record;
  * 0x4419f0 and 0x441940 (fastcall, plain ret; other areas' code) are hooks: they copy 12 bytes from EDX to ECX and record;
  * 0x4de420 is the verified 0x24-byte copy and runs as original code;
  * the global 0x7003b8 points to G; G+0x2c51 is object C, hooked as 0x581960 (thiscall, one argument, ret 4), recording its argument.
The data is random 32-bit words, so NaN and denormal floats both occur."""
from pilot import S


def _gen_bc30(c):
    e = c.emu
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    A = e.alloc(0x40, 4)
    e.wbytes(A, bytes(0x40))
    B = e.alloc(0x40, 4)
    e.wbytes(B, bytes(0x40))
    e.w32(A + 8, B)
    e.w32(this + 0x44, A)

    def write12(em, dst):
        em.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(12)))

    def slot80(em, a):
        em.calllog.append(('A.80', 0x80, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        write12(em, em.arg32(0))
        write12(em, em.arg32(1))
        em.ret(eax=0, argbytes=8)
    e.w32(A, e.fake_vtable('A', 0x400 // 4, {0x80: slot80}))

    def out1(name):
        def h(em, a):
            em.calllog.append((name, None, em.reg('ecx'), (em.arg32(0),)))
            write12(em, em.arg32(0))
            em.ret(eax=0, argbytes=4)
        return h
    e.hook(0x4daf90, out1('h.4daf90'))
    e.hook(0x4db7c0, out1('h.4db7c0'))

    def fast(name):
        def h(em, a):
            ecx, edx = em.reg('ecx'), em.reg('edx')
            em.calllog.append((name, None, ecx, (edx,)))
            em.wbytes(ecx, em.rbytes(edx, 12))
            em.ret(eax=0, argbytes=0)
        return h
    e.hook(0x4419f0, fast('h.4419f0'))
    e.hook(0x441940, fast('h.441940'))
    e.hook(0x633654, lambda em, a: em.ret(eax=0, argbytes=0))
    C = e.alloc(0x40, 4)
    e.wbytes(C, bytes(0x40))
    G = e.alloc(0x2c51 + 0x40, 4)
    e.wbytes(G, bytes(0x2c51 + 0x40))
    e.w32(G + 0x2c51, C)
    e.w32(0x7003b8, G)
    e.hook(0x581960, lambda em, a: (em.calllog.append(('h.581960', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.mu.ctl_flush_tb()
    return [this]


S(0x5dbc30, 'unnamed 0x5dbc30 thiscall (Load body)', 'thiscall', None, ret=None, gen=_gen_bc30,
  note='unclaimed-63 batch 56; cookie check 0x633654 not reproduced (hooked no-op on both sides)')
