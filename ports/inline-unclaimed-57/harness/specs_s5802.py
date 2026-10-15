"""specs_s5802.py - unclaimed-57, batch 102: 0x5d5400 (GUESS name unnamed_5d5400). Thiscall, no stack args, plain ret. The state at this+0x54 is 1 or 2
in about nine cases in ten (other values return at once). The engine (global 0x70039c) dword at +0x40 and this+0x4c are random signed values
in a range that makes both the early branch and the division branch run. this+0x50 is never equal to this+0x4c (the divisor is nonzero, as
it is in the original's real use). The object at this+0x44 has fake slots +0x250 and +0xbc (one argument each, logged). The 64-bit division is
the CRT helper at 0x634290, which the port reproduces in C."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5400(c):
    e = c.emu

    def h250(em, r):
        em.calllog.append(('250', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def hbc(em, r):
        em.calllog.append(('bc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_o = e.fake_vtable('d5400_o', 160, {0x250: h250, 0xbc: hbc})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    eng = _rnd(c, 0x100)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    st = 1 if c.rng.random() < 0.45 else (2 if c.rng.random() < 0.8 else c.rng.getrandbits(32))
    e.w32(self_obj + 0x54, st)
    x = c.rng.randrange(-200000, 200000)
    # the engine value equals this+0x4c in about one case in seven (the strict > test is checked at its edge)
    e40 = x if c.rng.random() < 1 / 7 else c.rng.randrange(-200000, 200000)
    e.w32(eng + 0x40, e40 & 0xffffffff)
    n = x
    while n == x:
        n = c.rng.randrange(-200000, 200000)
    e.w32(self_obj + 0x4c, x & 0xffffffff)
    e.w32(self_obj + 0x50, n & 0xffffffff)
    e.w32(self_obj + 0x44, obj)
    return [self_obj]


S(0x5d5400, 'unnamed_5d5400 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5400,
  note='unclaimed-57 batch 102; object slots +0x250 and +0xbc logged; the CRT 64-bit division (0x634290) is ported as C arithmetic')
