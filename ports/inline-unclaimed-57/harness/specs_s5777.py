"""specs_s5777.py - unclaimed-57, batch 77: 0x5d8420 (GUESS name unnamed_5d8420). No arguments, no ECX use, plain ret. The engine
(global 0x70039c) is a per-case object whose fake slot +0x1cc (one argument, logged) is called first; then the function tail-jumps to
0x5d7b10, which is a separate large function (owned by another area) and is hooked here as a logging stub that writes nothing."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d8420(c):
    e = c.emu

    def h1cc(em, r):
        em.calllog.append(('1cc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def tail(em, r):
        em.calllog.append(('5d7b10', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x5d7b10, tail)
    vt = e.fake_vtable('d8420_eng', 160, {0x1cc: h1cc})
    eng = _rnd(c, 0x100)
    e.w32(eng, vt)
    e.w32(0x70039c, eng)
    return []


S(0x5d8420, 'unnamed_5d8420 (GUESS) cdecl', 'cdecl', None, ret=None, gen=_d8420,
  note='unclaimed-57 batch 77; engine slot +0x1cc fake (one argument, logged); tail target 0x5d7b10 hooked (logs)')
