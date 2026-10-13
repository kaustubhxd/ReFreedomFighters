"""specs_s7878.py - area 73 batch 78 (GUESS name). FUN_5001e0 (stdcall, ret 8, two arguments that it ignores): stream = logger
(global 0x700390) vtable +0x20(0x69c7b8, 0x96) (logging stub returns a stream); then the stream's vtable +0x2c (cdecl printf-like,
three arguments: stream, 0x69c6b0, 0x69c7f0); then the assert hook at 0x7003b0, when non-null, is called with no arguments.
Logger, stream and assert hook are logging stubs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0)
    stream = _rnd(c, 16)
    e.w32(stream, e.fake_vtable('stream5001e0', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger5001e0', 16, impl={0x20: lambda em, a: (stream, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    def hassert(em, r):
        em.calllog.append(('assert', 0, None, ()))
        em.ret(eax=0, argbytes=0)
    # The assert hook is always non-null here. With it null the original executes an int3 at 0x500216 (a breakpoint, not a
    # result), which would count as a faulting case.
    e.w32(0x7003b0, e.stub_fn('assert5001e0', hassert))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5001e0, 'GUESS FUN_5001e0 (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='area 73 batch 78; logger(0x700390).vt+0x20(0x69c7b8, 0x96) -> stream; stream.vt+0x2c(stream, 0x69c6b0, 0x69c7f0) cdecl; assert hook 0x7003b0 if set; ret 8')
