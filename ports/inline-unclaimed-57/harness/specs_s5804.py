"""specs_s5804.py - unclaimed-57, batch 104: 0x5ddb00 (GUESS name unnamed_5ddb00). Thiscall, no stack args, plain ret. The same shape as 0x5d5400
(batch 102) with the state at this+0x5c: 1 or 2 in about nine cases in ten. The engine (global 0x70039c) dword at +0x40 and this+0x4c are random
signed values, equal in about one case in seven (the strict > test is checked at its edge), and this+0x50 is never equal to this+0x4c (the
divisor is nonzero). The object at this+0x44 has fake slots +0x250 and +0xbc (one argument each, logged). The 64-bit division is the CRT helper at
0x634290 (original code)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5b00(c):
    e = c.emu

    def h250(em, r):
        em.calllog.append(('250', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def hbc(em, r):
        em.calllog.append(('bc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_o = e.fake_vtable('d5b00_o', 160, {0x250: h250, 0xbc: hbc})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    eng = _rnd(c, 0x100)
    x = c.rng.randrange(-200000, 200000)
    e40 = x if c.rng.random() < 1 / 7 else c.rng.randrange(-200000, 200000)
    e.w32(eng + 0x40, e40 & 0xffffffff)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    st = 1 if c.rng.random() < 0.45 else (2 if c.rng.random() < 0.8 else c.rng.getrandbits(32))
    e.w32(self_obj + 0x5c, st)
    n = x
    while n == x:
        n = c.rng.randrange(-200000, 200000)
    e.w32(self_obj + 0x4c, x & 0xffffffff)
    e.w32(self_obj + 0x50, n & 0xffffffff)
    e.w32(self_obj + 0x44, obj)
    return [self_obj]


S(0x5ddb00, 'unnamed_5ddb00 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5b00,
  note='unclaimed-57 batch 104; the batch 102 shape with the state at +0x5c; object slots +0x250 and +0xbc logged; CRT 64-bit divide original')
