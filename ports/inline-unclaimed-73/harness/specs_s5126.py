"""specs_s5126.py - area 73 batch 51 (gap band, GUESS name). FUN_4f4d60 (ret 4, returns a bool in al): when this+0x70 is 0x20
it returns 1. Otherwise it tail-jumps to 0x560360 with the same stack argument. 0x560360 is hooked to a logging stub (its
original code is xor al,al; ret 4), so the port's call to it is recorded and its result is compared."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x70, 0x20 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o, c.rng.getrandbits(32)]


def _hook(em, r):
    em.calllog.append(('560360', 0, em.reg('ecx'), (em.arg32(0),)))
    em.ret(eax=0x100 | (1 if em.arg32(0) & 1 else 0), argbytes=4)


def _install(c):
    c.emu.hook(0x560360, _hook)


S(0x4f4d60, 'GUESS FUN_4f4d60 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen, setup=_install,
  note='area 73 batch 51; this+0x70 == 0x20 returns 1, else tail call 0x560360 (hooked, logging)')
