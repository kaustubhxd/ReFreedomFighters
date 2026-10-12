"""specs_s6250.py - area 73 batch 62 (gap band, GUESS name). FUN_4f6680 (ret 4, returns a bool in al): ok = 0x4f0d70(this, a)
(hooked by address, logged, returns a random bool). When ok is 0 it returns 0; otherwise it calls vtable +0x3c on a with
[this+0x93] and returns 1."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x93, c.rng.getrandbits(32))
    arg = _rnd(c, 0x100)
    e.w32(arg, e.logging_vtable('f6680', 0x80 // 4, impl={0x3c: lambda em, a: (0, None)}, argwords={0x3c: 1}))
    okv = c.rng.getrandbits(8) & 1

    def h(em, rr):
        em.calllog.append(('4f0d70', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=okv, argbytes=4)
    e.hook(0x4f0d70, h)
    return [o, arg]


S(0x4f6680, 'GUESS FUN_4f6680 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='area 73 batch 62; ok = 0x4f0d70(this, a); if ok: vt(a)+0x3c([this+0x93]), returns 1; else 0')
