"""specs_s5778.py - unclaimed-57, batch 78: 0x5c7980 (GUESS name unnamed_5c7980). Thiscall, one stack argument a (ret 4), no return value.
The argument a is an object whose byte +0x2c is 1 in about one case in four (early return) and whose +0x10 is a list object p (null in
about one case in ten). p has fake slots: +0x4c (one argument, writes a dword through it, result unused) and +0x5c (one argument: writes
the loop flag through it, returns a handle). The flag sequence is 0 to 3 nonzero values followed by zero, so the loop runs 0 to 3 times.
The object at this+0x44 has a fake slot +0x12c (three arguments, logged). The word read from global 0x71434c is the exe's own data."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c7980(c):
    e = c.emu
    seq = [1] * c.rng.randrange(0, 4) + [0]
    handles = [c.rng.getrandbits(32) for _ in range(4)]
    idx = [0]

    def h4c(em, r):
        em.calllog.append(('4c', 0, None, ()))
        em.w32(em.arg32(0), 0)
        em.ret(eax=0, argbytes=4)

    def h5c(em, r):
        i = idx[0]
        idx[0] += 1
        flag = seq[i] if i < len(seq) else 0
        em.calllog.append(('5c', 0, None, (flag,)))
        em.w32(em.arg32(0), flag)
        em.ret(eax=handles[i % 4], argbytes=4)

    def h12c(em, r):
        em.calllog.append(('12c', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)

    vt_p = e.fake_vtable('c7980_p', 160, {0x4c: h4c, 0x5c: h5c})
    vt_q = e.fake_vtable('c7980_q', 160, {0x12c: h12c})
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    q = _rnd(c, 0x40)
    e.w32(q, vt_q)
    a = _rnd(c, 0x80)
    e.wbytes(a + 0x2c, bytes([1 if c.rng.random() < 0.25 else 0]))
    e.w32(a + 0x10, 0 if c.rng.random() < 0.1 else p)
    self_obj = _rnd(c, 0x80)
    e.w32(self_obj + 0x44, q)
    return [self_obj, a]


S(0x5c7980, 'unnamed_5c7980 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c7980,
  note='unclaimed-57 batch 78; list object p slots +0x4c and +0x5c fake (flag sequence); q slot +0x12c logged; word 0x71434c from data')
