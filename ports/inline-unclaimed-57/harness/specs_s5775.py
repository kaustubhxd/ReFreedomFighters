"""specs_s5775.py - unclaimed-57, batch 75: 0x5d91a0 (GUESS name unnamed_5d91a0). Thiscall, no stack args, plain ret. The state at this+0x4c
is 1 in most cases (0 or 2 otherwise, which returns early). The threshold f = (float)(engine+0x40 - this+0x48 - 0x200) * (1/1024) is
compared with 0.0 (read from the exe's data), chosen random so both branches run. The object at this+0x44 has a fake slot +0x254 (no
args, logged); the engine sub-object's slot +0x58 (one argument, logged) returns object obj (or null in about one case in four); obj has
a fake slot +0x254 (logged) that the original tail-calls. All slots log only their own tag."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d91a0(c):
    e = c.emu
    st = c.rng.choice([1, 1, 1, 0, 2])
    null_obj = c.rng.random() < 0.25

    def hA(em, r):
        em.calllog.append(('A254', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def hO(em, r):
        em.calllog.append(('O254', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=0 if null_obj else obj, argbytes=4)

    vt_a = e.fake_vtable('d91a0_a', 160, {0x254: hA})
    vt_o = e.fake_vtable('d91a0_o', 160, {0x254: hO})
    vt_sub = e.fake_vtable('d91a0_sub', 160, {0x58: h58})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    a_obj = _rnd(c, 0x40)
    e.w32(a_obj, vt_a)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    s48 = c.rng.randrange(0, 4096)
    # in about one case in five the difference is exactly zero, so the strict test against 0.0 is checked at its boundary
    e40 = s48 + 0x200 if c.rng.random() < 0.2 else c.rng.randrange(-4096, 8192)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x40, e40 & 0xffffffff)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x4c, st)
    e.w32(self_obj + 0x48, s48)
    e.w32(self_obj + 0x44, a_obj)
    return [self_obj]


S(0x5d91a0, 'unnamed_5d91a0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d91a0,
  note='unclaimed-57 batch 75; threshold against 0.0 from data; object +0x44 slot +0x254, engine sub slot +0x58, obj slot +0x254 (tail) logged')
