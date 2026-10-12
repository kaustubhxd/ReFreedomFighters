"""specs_s3914.py - area 73 batch 14 (gap band, GUESS names). Setters take random arguments; FUN_4e1b20 calls the helper 0x4e1590
(hooked, logged, returns a random dword) and adds it. FUN_4f9510 is cdecl: its two dword pointers are random heap cells."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setter(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _e1b20(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    rv = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('4e1590', 0, em.reg('ecx'), ()))
        em.ret(eax=rv, argbytes=0)

    e.hook(0x4e1590, h)
    return [self_o]


def _sub(c):
    a = _rnd(c, 0x10)
    b = _rnd(c, 0x10)
    return [a, b]


S(0x4f1510, 'GUESS FUN_4f1510 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 14; byte store at +0x21')
S(0x4f4e10, 'GUESS FUN_4f4e10 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 14; dword store at +0x60')
S(0x4e1b20, 'GUESS FUN_4e1b20 (unknown) thiscall', 'thiscall', None, ret=None, gen=_e1b20,
  note='area 73 batch 14; helper 0x4e1590 then +8 += r+1')
S(0x4f9510, 'GUESS FUN_4f9510 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_sub,
  note='area 73 batch 14; cdecl [a1]-[a2]')
S(0x4f10f0, 'GUESS FUN_4f10f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 14; dword store at +0x9f')
