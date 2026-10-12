"""specs_s7070.py - area 73 batch 70 (gap band, tail-jump rows, rule: arity = target ret / 4 = 5, target hooked by address).
FUN_4f3e50 (tail-jump): writes 0 to its fifth argument, then jumps to 0x43ff00 (ret 0x14, five arguments).
FUN_4f7ea0 (tail-jump): writes (fifth argument != 0) to its fifth argument, then jumps to 0x4f9e00 (a thunk to 0x43ff00).
0x43ff00 is hooked by address and logged with its five arguments and ecx; the body is not verified here."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook_43ff00(c):
    def h(em, r):
        em.calllog.append(('43ff00', 0, em.reg('ecx'), tuple(em.arg32(k) for k in range(5))))
        em.ret(argbytes=0x14)
    c.emu.hook(0x43ff00, h)


def _gen_3e50(c):
    _hook_43ff00(c)
    return [_rnd(c, 0x100)] + [c.rng.getrandbits(32) for _ in range(5)]


def _gen_7ea0(c):
    _hook_43ff00(c)
    return [_rnd(c, 0x100)] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x4f3e50, 'GUESS FUN_4f3e50 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_3e50,
  note='area 73 batch 70; tail-jump: arg5 = 0; jmp 0x43ff00 (ret 0x14, hooked)')
S(0x4f7ea0, 'GUESS FUN_4f7ea0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_7ea0,
  note='area 73 batch 70; tail-jump: arg5 = (arg5 != 0); jmp 0x4f9e00 -> 0x43ff00 (hooked)')
