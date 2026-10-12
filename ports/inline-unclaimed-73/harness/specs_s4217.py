"""specs_s4217.py - area 73 batch 17 (gap band, GUESS names). Objects have logging vtables (slot +0x2ec, +0xbc); the helpers
0x4ef130 and 0x4f9bc0 are hooked (thiscall, logged). FUN_4fa330 returns false in al; the flag byte at +0x6c is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _obj(c, slots, argw):
    e = c.emu
    o = _rnd(c, 0x200)
    e.w32(o, e.logging_vtable('g42', 0x2f8 // 4, impl={k: _const(0) for k in slots}, argwords=argw))
    e.w32(o + 0x70, c.rng.choice([0x20, 0x20, c.rng.getrandbits(32)]))
    e.wbytes(o + 0x6c, bytes([c.rng.getrandbits(8)]))
    return o


def _f9f10(c):
    o = _obj(c, [0x2ec], {0x2ec: 1})
    return [o]


def _f4fa330(c):
    o = _obj(c, [0x2ec], {0x2ec: 1})
    return [o, c.rng.getrandbits(32)]


def _f6370(c):
    e = c.emu
    o = _obj(c, [0xbc], {0xbc: 1})

    def h4ef130(em, r):
        em.calllog.append(('4ef130', 0, em.reg('ecx'), ()))
        em.ret()

    def h4f9bc0(em, r):
        em.calllog.append(('4f9bc0', 0, em.reg('ecx'), ()))
        em.ret()

    e.hook(0x4ef130, h4ef130)
    e.hook(0x4f9bc0, h4f9bc0)
    return [o]


S(0x4f9f10, 'GUESS FUN_4f9f10 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f9f10,
  note='area 73 batch 17; when +0x70 == 0x20: +0x6c &= ~2; slot +0x2ec(1)')
S(0x4fa330, 'GUESS FUN_4fa330 (unknown) thiscall', 'thiscall', None, ret='al', gen=_f4fa330,
  note='area 73 batch 17; slot +0x2ec(1) when +0x6c bit 1 clear; returns false')
S(0x4f6370, 'GUESS FUN_4f6370 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f6370,
  note='area 73 batch 17; helper 0x4ef130 then slot +0xbc(1)')
S(0x4f6e70, 'GUESS FUN_4f6e70 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f6370,
  note='area 73 batch 17; helper 0x4f9bc0 then slot +0xbc(1)')
